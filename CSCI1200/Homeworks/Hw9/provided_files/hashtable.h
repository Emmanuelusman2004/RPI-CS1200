#ifndef _hashtable_h_
#define _hashtable_h_

#include <iostream>
#include <vector>
#include <string>

class hashtable {
private:
    std::vector<std::pair<std::string, std::vector<int>>> hashTable;
    int size;
    float occupancy;
    int num_entries;

public:
    hashtable(int s = 100, float f = 0.5);
    void setsize(int tablesize);
    void setocc(float tableoccupancy) { occupancy = tableoccupancy;}
    unsigned int hash(const std::string& key);
    void resize();
    void insert(const std::string& key, int index);
    void altFind(std::string kmer, int m);
    std::vector<int> findpos(std::string str, int k);
    void query(std::string querystr, int m, int k, std::string genome);
};

#endif
