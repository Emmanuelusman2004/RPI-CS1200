#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    ifstream myFile;
    myFile.open(argv[1], ios::in);
    if (myFile.is_open()) 
    {
    string word;
    vector<string>list(0); //list with strings
    int width = atoi(argv[2]); // converting argument into int to multiply string
    while (myFile >> word) {

        list.push_back(word); //put all words from file into vector
    }

    for (auto & elem : list) {
        cout<<elem<<endl;
    }
    int count = 0;
    vector<vector>lines;
    vector<string>lineofwords;
    for (auto & elem : list) { 
        if (count <= width && count + elem.length() + 1 <= width) {
            lineofwords.push_back(elem);
            count = count + elem.length() + 1;
        }
        else {
            lines.pushback(lineofwords);
            vector<string>lineofwords;
            count = 0;
            lineofwords.push_back(elem);
            count = count + elem.length() + 1;
        }
    for (auto & elem : lines) {
        for (auto & line : elem) {
            cout<<"this is a word in line"<<endl;
            cout<<elem<<endl;
        }
    }
    }
    }
    }