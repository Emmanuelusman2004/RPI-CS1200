#include <iostream>
#include "hashtable.h" //look later at which i can exclude 
//#include "hashtable.cpp"
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <cassert>
#include <sstream>
#include <fstream>


int main() {
    std::string word, filename, wholegenome;
    hashtable set1;
    int k,tablesize;
    float occupancy;
    std::cin>>word>>filename;
    std::ifstream genomefile(filename);
    while (genomefile>>word) {
        wholegenome+=word;
    }

    while (std::cin>>word) {
        if (word == "table_size") {  //have to do these, have to comment my code, have to do readme
            std::cin>>tablesize;
            set1.setsize(tablesize);

        }
        else if (word == "occupancy") {
            std::cin>>occupancy;
            set1.setocc(occupancy);

        }
        else if (word == "kmer") {
            std::cin>>k;
            for (unsigned int i = 0; i < wholegenome.size()-k; i++) {
                std::string tempkmer = ""; //what we insert into the hash
                for (int j = 0; j < k; j++) {
                    tempkmer+=wholegenome[i+j]; 
                }
                set1.insert(tempkmer, i);//now we insert into the hashtable
            }
        }
        else if (word == "query") {
            int m;
            std::string query_string;
            std::cin>>m>>query_string;
            std::cout<<"Query: "<<query_string<<std::endl;
            set1.query(query_string, m, k, wholegenome);
        }
        else if (word == "quit") {
            return 0;
        }
    }


            





















// int count = 0;
// for (unsigned int i = 0; i < wholegenome.size() - query_string.size() + 1; i++) { //get the temp string we are trying to compare
//     std::string compkmer = wholegenome.substr(i, query_string.size());
//     int mismatches = 0; //check for mismatches in the temp string
//     for (unsigned int k = 0; k < query_string.size() && mismatches <= m; k++) {
//         if (compkmer[k] != query_string[k]) {
//             mismatches++;
//         }
//     }
//     if (mismatches <= m && (compkmer[0] == query_string[0])) {
//         count++;
//         std::cout << i << " " << mismatches << " " << compkmer << std::endl;
//     }
// }
// if (count == 0) {
//     std::cout << "No Match" << std::endl;
// }

//         }
//         else if (word == "quit") {
//             return 0;
//         }
//     }

}




//  if (hashtablecreated == false) {
//                 if ((tablesizeinit = false) && (occupancyinit == false)) { //if both false we create it with the default values
//                     hashtable set1;
//                     std::cout<<"1"<<std::endl;
//                 }
//                 else if ((tablesizeinit == true) && (occupancyinit == false)) {//if given the tablesize and not occ inititalize with default occ
//                     hashtable set1(tablesize,.5);
//                     std::cout<<"1"<<std::endl;

//                 }
//                 else if ((tablesizeinit == false) && (occupancyinit == true)) {
//                     hashtable set1(100,occupancy);
//                     std::cout<<"1"<<std::endl;

//                 }
//             }
//             else {
//                 //if both false we create it with the default values
//                 hashtable set1;
//                 std::cout<<"1"<<std::endl;
//             }



// int main() {
//     std::string word,file,genome, splitline;
//     while (std::cin >> word) {
//         std::cout<<word<<3<<std::endl;
// //         std::istringstream ss(word);
// // //        std::cout<<word<<std::endl;
        
//         // while (ss>>splitline) {
//             if (word == "genome") {
//                     std::string filename;
//                     word>>filename;
//                     std::ifstream genomefile(filename);//not sure if this is the correct way to open the file
//                     genomefile>>genome; //check if this actually works out to take in the file as a string called genome
//                 }
//                 // else if (word == "table_size") { //if they specify the size then use that size if not then use 100 as the default size
//                 //     std::string N; //need to convert to int
//                 //     std::cin>>N;
//                 //     N = std::stoi(N);

//                 // }
//                 // else if (word == "occupancy") { //this is when we resize the table
//                 //     std::string f;
//                 //     std::cin>>f; //need to convert to int
//                 //     f = std::stoi(f);

//                 // }
//                 else if (word == "kmer") { //subsequence of characters in genome
//                     int k;
//                     >>k;

//                     ds_hashset_type set1;
//                     for (unsigned int i = 0; i < genome.size()-k; i++) {/////////////////////////////////////////////////
//                         //need to find a way to make sure it does not get out of range!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



//                         std::string tempkmer = ""; //what we insert into the hash
//                         for (int j = 0; j < k; j++) {
//                             tempkmer+=genome[i+j]; //insert characters into string we will insert into the hash
//                         }
//                         set1.insert(tempkmer);//now we insert into the hashtable
//                     }
//                 }
//                 else if (word == "query") {
//                     //if less than that nulmber of mismatches use that then output everwhere you find it print location also
//                     int m;
//                     std::string query_string;
//                     ss>>m>>query_string;
//                     std::cout<<"Query: "<<query_string<<std::endl;
//                     int count = 0;
//                     for (unsigned int i = 0; i < genome.size(); i++) { //get the temp string we are trying to compare
//                         std::string compkmer = "";
//                         for (unsigned int j = 0; j < query_string.size(); j++) {
//                             compkmer+=genome[i+j];
//                         }
//                         int mismatches = 0; //check for mismatches in the temp string
//                         for (unsigned int k = 0; k < compkmer.size() && mismatches < m; k++) {
//                             if (compkmer[k] != query_string[k]) {
//                                 mismatches++;
//                             }
//                         }
//                         if (mismatches <= m) {
//                             count++;
//                             std::cout<<i<<mismatches<<compkmer<<std::endl;
//                         }
//                     }
//                     if (count == 0) {
//                         std::cout<<"No Match"<<std::endl;
//                     }
//                 }
//                 else if (word == "quit") {
//                     return 0;
//                 }
//         }

//     }
// }