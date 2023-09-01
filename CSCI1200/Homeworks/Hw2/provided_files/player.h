#ifndef __player_h_
#define __player_h_
#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
#include <string>

using namespace std;

//constructors
class Players {
private:

string name;
string team;
int goals;
int assists;
int penalties;
float ppg;

public:

    Players();
    Players(string name, string team, int goals, int assists, int penalties);

    //getters
    string getPname() const;
    string getPteam() const;
    int getPgoal() const;
    int getPassists() const;
    int getPpenalties() const;
    float getPPG() const;

    //setters
    void addPgoal();
    void addPassists();
    void addPpenalties();
    void setPname(string namegiven);
    void setPteam(string teamname);
    void setPPG(float pointspergame);



};

//sorting functions
bool compareplayers( const Players &obj1, const Players &obj2);
bool compareppg( const Players &obj1, const Players &obj2);

#endif