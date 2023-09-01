#include <iostream>
#include <fstream>
#include <cstring>
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include "team.h"
#include "team.cpp"
#include "player.h"
#include "player.cpp"

using namespace std;

//functions that calls our class and adds object or adds information to that object

//this will be the function for players

//this will be the function for the teams
void teamfunction(string team1, string team2, vector v) {
    if (std::find(v.begin(), v.end(), team1) != v.end()) {
        //call the addition thingies
    }
    else {
        //initialize the object for the first time
    }
    if (std::find(v.begin(), v.end(), team2) != v.end()) {
        //call the addition things 
    }
    else {
        //initialize the things for the first time
    }
}


int main(int argc, char* argv[]) {
    ifstream myFile;
    myFile.open(argv[1], ios::in);
    if (myFile.is_open()) 
    {
    string word;
    vector<string>list(0); //list with strings of each word in the file
    while (myFile >> word) {
        list.push_back(word); //put all words from file into vector
    }
    vector<string>players(0);
    vector<string>teams(0);
    for (int i = 0, i < list.size(), i+=1) {
        string elem = list[i];
        if (elem == "at") {
            string team1 = list[i-1];
            string team2 = list[i+1];
            teamfunction(team1,team2);
            teams.push_back(team1);
            teams.push_back(team2);
        }
        else if (elem == "penalty") {

        }
        else if (elem == "goal") {

        }
        

    }


    }
    return 0;
}