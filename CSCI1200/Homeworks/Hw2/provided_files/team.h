#ifndef __team_h_
#define __team_h_

#include <iostream>
#include <fstream>
#include <cstring>
//#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Team {
private:

string name;
int goals;
int penalties;
int wins;
int losses;
int ties;
int games;
double Wratio;

public:
    //constructors
    Team();
    Team(string name, int goals, int penalties, int wins, int losses, int ties, int games, double Wratio);

    //getters
    int getGoal() const;
    int getPenalties() const;
    int getWins() const;
    int getLosses() const;
    int getTies() const;
    double getWratio() const;
    int getGames() const;
    string getname() const;

    //setters
    void addGoal();
    void addPenalties();
    void addWins();
    void addLosses();
    void addTies();
    void addGames();
    void setname(string namegiven);
    void setWratio(double Wratio);

};
//sorting function
bool compareteams( const Team &obj1, const Team &obj2);

#endif