#include "hashtable.h"

hashtable::hashtable(int s, float f) {
    size = s;
    occupancy = f;
    hashTable = std::vector<std::pair<std::string, std::vector<int>>>(size, std::make_pair("", std::vector<int>()));
    num_entries = 0;
}

void hashtable::setsize(int tablesize) {
    // Check if the new size is smaller than the current number of entries
    if (tablesize < num_entries) {
        std::cerr << "New size is smaller than the current number of entries!" << std::endl;
        return;
    }
    // Create a new table with the new size
    std::vector<std::pair<std::string, std::vector<int>>> new_table(tablesize, std::make_pair("", std::vector<int>()));
    // Rehash all entries from the old table into the new table
    for (int i = 0; i < size; i++) {
        if (hashTable[i].first != "") {
            int new_keyindex = hash(hashTable[i].first);
            while (new_table[new_keyindex].first != "") {
                new_keyindex++;
                if (new_keyindex >= tablesize) new_keyindex = 0;
            }
            new_table[new_keyindex].first = hashTable[i].first;
            new_table[new_keyindex].second = hashTable[i].second;
        }
    }
    // Set the new table and size
    hashTable = new_table;
    size = tablesize;
}


unsigned int hashtable::hash(const std::string& key) {
    unsigned int hash = 1315423911;
    for(unsigned int i = 0; i < key.length(); i++)
        hash ^= ((hash << 5) + key[i] + (hash >> 2));
    return hash % size;
}

void hashtable::resize() {
    float current_occupancy = static_cast<float>(num_entries) / static_cast<float>(size);
    if (current_occupancy >= occupancy) {
        int new_size = size * 2;
        std::vector<std::pair<std::string, std::vector<int>>> new_table(new_size, std::make_pair("", std::vector<int>()));  //make new table of new size
        for (int i = 0; i < size; i++) {
            if (hashTable[i].first != "") {
                int new_keyindex = hash(hashTable[i].first);    //get new hash indexes for each value in table
                while (new_table[new_keyindex].first != "") {   //fill the table up
                    new_keyindex++;
                    if (new_keyindex >= new_size) new_keyindex = 0;
                }
                new_table[new_keyindex].first = hashTable[i].first;
                new_table[new_keyindex].second = hashTable[i].second;
            }
        }
        hashTable = new_table;  //set the new table
        size = new_size;
    }
    else {
        return;
    }
}

void hashtable::insert(const std::string& key, int index) {
    //std::cout<<key<<index<<std::endl;
    int keyindex = hash(key);   
    for (unsigned int i = 0; i < hashTable.size(); i++) {   //search if key in table already
        if (hashTable[i].first == key) {
            hashTable[i].second.push_back(index);
            return;
        }
    }

    if (hashTable[keyindex].first == "") {
        hashTable[keyindex].first = key;
        hashTable[keyindex].second.push_back(index);
    }
    else {  //we execute linear probing by going to the next index until its empty and we fill it
        while (hashTable[keyindex].first != "") {
            keyindex++;
            if (keyindex >= size) keyindex = 0; //if table ever gets too full we fill from beginning
        }
        hashTable[keyindex].first = key;    
        hashTable[keyindex].second.push_back(index);
    }

    // check if the table needs to be resized
    resize();
    num_entries++; //add to unique entries
}

std::vector<int> hashtable::findpos(std::string str, int k) { //return a vector of positions of the parameter within the original genome
    std::string tempstring;
    for (unsigned int i = 0; i < str.size() && i < (unsigned int)k; i++) { 
        tempstring+=str[i];
    }

    for (unsigned int i = 0; i < hashTable.size(); i++) { //search entire hashtable for query
        if (hashTable[i].first == tempstring) {
            return hashTable[i].second;

        }
    }

    std::vector<int>nothing; //if we find nothing return empty vector
    return nothing;

}

void hashtable::query(std::string querystr, int m, int k, std::string genome) {
    std::vector<int> positions = findpos(querystr, k);
    bool printed = false;
    for (unsigned int i = 0; i < positions.size (); i++) {  //iterate through all positions in genome
        std::string substr = genome.substr(positions[i], querystr.size());
        int mismatches = 0;
        for (unsigned int j = 0; j < querystr.size(); j++) { //compare substr and query for mismatches
            if (querystr[j] != substr[j]) {
                mismatches++;
            }
        }
        if (mismatches <= m) { 
            std::cout<<positions[i]<<" "<<mismatches<<" "<<substr<<std::endl;
            printed = true;
        }
        
    }
    if (printed == false) { 
        std::cout<<"No Match"<<std::endl;
    }
}







