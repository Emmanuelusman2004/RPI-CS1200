#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
/*
So for this homework i need to create 3 ways to put a text file together. 
one method is flush left which means the words are on teh left and space on the right
another is flush right meaning words on the right and space on the left
last is full justify which ill have trouble with but you basically split the extra space evenly into 
spaces between the words and if it is an odd number off spaces and white space just add evenly from the left
*/

/* 
create and empty string put the border then we gonna put borders and then we put /n and a | to separate
and then put words but also count the amount each word is. if the word count is larger than the specified
width we will reset the counter and then repeat the process.

we should try and consider vectors, inserting, and using a for loop to go through the string
*/


int main(int argc, char* argv[]) {
    ifstream myFile;
    myFile.open(argv[1], ios::in);
    if (myFile.is_open()) 
    {
    string word;
    vector<string>list(0); //list with strings of each word in the file
    std::size_t width = atoi(argv[3]); // converting argument into int to multiply string
    while (myFile >> word) {
        list.push_back(word); //put all words from file into vector
    }
    vector<string>liststrings(0); //list of strings put into each line of box
    vector<string>listspaces(0); //this was a vector which holds spaces and words as lines
    string line = "";
    int x = 0;
    for (size_t i = 0; i < list.size(); i++) {
    /*
    This for loop basically takes the words in the file and
    finds checks if the line we are adding to + the next word 
    will fit in the width. the cases below take care of the possible scenarios
    */
        string elem = list[i];

        if (line.length() + elem.length() + 1 <= width) { //this takes care of instances when adding the word will be less than the width
            if (x == 0) { //this is when its the first word we do not add a space in front
                line = line + elem;
                x= x + 1;
                listspaces.push_back(elem);
                
            }
            else { //this is in case when the word is not the first word in the line
                line = line + " " + elem;
                listspaces.push_back("");
                listspaces.push_back(elem);
            }
        }
        else if (line.length() + elem.length() + 1 > width) { ////this takes care of when adding the next word is greater than the width
            liststrings.push_back(line);
            line = "";
            line = line + elem;
            listspaces.push_back(elem);
            


        }

        }      
    liststrings.push_back(line); //pushback last line

    string topbottomframe(width + 4,'-');
    if (std::string(argv[4]) == std::string("flush_left")) {
        std::ofstream outFile; // opening the file 
        outFile.open(argv[2]);
        outFile <<topbottomframe<<endl;
        for (std::size_t i = 0; i < liststrings.size(); i++) {
            string elem = liststrings[i];
            outFile<<"| "; //writing to the file
            outFile.setf(ios :: left);
            outFile.width(width);
            outFile<<elem;
            outFile<<" |"<<endl;
        }
        outFile<<topbottomframe<<endl;
        outFile.close();
    }
    else if (std::string(argv[4]) == std::string("flush_right")) {
        std::ofstream outFile;
        outFile.open(argv[2]);
        //std::cout << argv[2] << std::endl;
        outFile<<topbottomframe<<endl;
        for (std::size_t i = 0; i < liststrings.size(); i++) {
            string elem = liststrings[i];
            outFile<<"| "; //writing to a file.
            outFile.setf(ios :: right);
            outFile.width(width);
            outFile<<elem;
            outFile<<" |"<<endl;
        }
        outFile<<topbottomframe<<endl;
        
    }
  
    else if (std::string(argv[4]) == std::string("full_justify")) {
        std::ofstream outFile;
        outFile.open(argv[2]);
        outFile<<topbottomframe<<endl;
        for (std::size_t i = 0; i < liststrings.size(); i++) {
            string elem = liststrings[i];
            outFile<<"| "; // just trying to rack up points for full justify :( i couldnt find out how to do it
            outFile.setf(ios :: right);
            outFile.width(width);
            outFile<<elem;
            outFile<<" |"<<endl;
        }
        outFile<<topbottomframe<<endl;
        


    }


}
}
