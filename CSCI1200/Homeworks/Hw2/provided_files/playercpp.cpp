#include "player.h"


using namespace std;

//constructor
Players::Players()
{
    name = "";
    team = "";
    goals = 0;
    penalties = 0;
    assists = 0;
    ppg = 0;

}

//getters
string Players::getPname() const
{
    return name;
}
string Players::getPteam() const
{
    return team;
}
int Players::getPgoal() const
{
    return goals; 
}
int Players::getPassists() const
{
    return assists;
}
int Players::getPpenalties() const
{
    return penalties;
}

float Players::getPPG() const
{
    return ppg;
}

//setters
void Players::addPgoal() 
{
    goals+=1;
}
void Players::addPassists()
{
    assists+=1;
}
void Players::addPpenalties()
{
    penalties+=1;
}
void Players::setPname(string namegiven)
{
    name = namegiven;
}
void Players::setPteam(string teamname)
{
    team = teamname;
}
void Players::setPPG(float pointspergame)   
{
    ppg = pointspergame;
}


//sorting functions
bool compareplayers( const Players &obj1, const Players &obj2) {
    if (obj1.getPassists() + obj1.getPgoal() > obj2.getPassists() + obj2.getPgoal()) {
        return true;
    }

    if (obj1.getPassists() + obj1.getPgoal() == obj2.getPassists() + obj2.getPgoal()) {
        if (obj1.getPpenalties() < obj2.getPpenalties()) {
            return true;
        }
        else if (obj1.getPpenalties() > obj2.getPpenalties()) {
            return false;
        }
    }

    if (obj1.getPassists() + obj1.getPgoal() == obj2.getPassists() + obj2.getPgoal()) {
        if (obj1.getPpenalties() == obj2.getPpenalties()) {
            if (obj1.getPname() < obj2.getPname()) {
                return true;
            }
        }
    }
    

    return false;

}   

bool compareppg( const Players &obj1, const Players &obj2) {
    if (obj1.getPPG() > obj2.getPPG()) {
        return true;
    }
    else if (obj1.getPPG() == obj2.getPPG()) {
        if (obj1.getPname() < obj2.getPname()) {
            return true;
        }
        else {
            return false;
        }
    }

    return false;
}