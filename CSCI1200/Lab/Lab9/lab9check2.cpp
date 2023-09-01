#include <iostream>
#include <fstream>
#include <map>
#include <string>


int main(int argc, char* argv[]) {
    std::map<std::string, int> count_of_occ;

    std::ifstream myFile;
    myFile.open(argv[1]);
    if (!myFile.is_open()) {
        std::cerr<<"File could not open"<<std::endl;
        exit(1);
    }
    std::string number;
    while (myFile >> number) {
        if (count_of_occ.find(number) != count_of_occ.end()) {
            count_of_occ.find(number)->second ++;
        }
        else {
            count_of_occ.insert(std::make_pair(number, 1));      
        }
    }
    myFile.close();

    // Get an iterator pointing to the first element in the map
    std::map<std::string, int>::iterator it = count_of_occ.begin();
 
    // Iterate through the map and print the elements
    while (it != count_of_occ.end()) {
    std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    ++it;
    }

}