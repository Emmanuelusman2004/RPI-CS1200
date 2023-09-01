#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*
So for this homework i need to create 3 ways to put a text file together. 
one method is flush left which means the words are on teh left and space on the right
another is flush right meaning words on the right and space on the left
last is full justify which ill have trouble with but you basically split the extra space evenly into 
spaces between the words and if it is an odd number off spaces and white space just add evenly from the left
*/

int main () {
    fstream myFile;
    myFile.open(argv1, ios::in);
    if (myFile.is_open()) {
        string fileline;
        while (getline(myFile, line)) {
            
        }
        myFile.close()
    }
}