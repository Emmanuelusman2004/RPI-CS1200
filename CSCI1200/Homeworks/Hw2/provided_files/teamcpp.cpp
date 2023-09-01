#include "team.h"


using namespace std;

//constructor
Team::Team() 
{
    name = "";
    goals = 0;
    penalties = 0;
    wins = 0;
    losses = 0;
    ties = 0;
    games = 0;
    Wratio = 0;
}

//getters

int Team::getGoal() const
{
    return goals;
}

int Team::getPenalties() const 
{
    return penalties;
}
int Team::getWins() const
{
    return wins;
}
int Team::getLosses() const
{
    return losses;
}
int Team::getTies() const
{
    return ties;
}
double Team::getWratio() const
{
    return Wratio;
}
int Team::getGames() const
{
    return games;
}
string Team::getname() const
{
    return name;
}



//setters

void Team::addGoal()
{
    goals+=1;
}
void Team::addPenalties()
{
    penalties+=1;
}
void Team::addWins()
{
    wins+=1;
}
void Team::addLosses()
{
    losses+=1;
}
void Team::addTies()
{
    ties+=1;
}
void Team::addGames()
{
    games+=1;
}
void Team::setname(string namegiven)
{
    name = namegiven;
}
void Team::setWratio(double wratio)
{
    Wratio = wratio;
}

//sorting function
bool compareteams( const Team &obj1, const Team &obj2) {
    if (obj1.getWratio() > obj2.getWratio()) {
        return true;
    }
    
    if (obj1.getWratio() == obj2.getWratio()) { 
        if (obj1.getGoal() > obj2.getGoal()) {
            return true;
        }
        else if (obj1.getGoal() < obj2.getGoal()) {
            return false;
        }
    }
    if (obj1.getWratio() == obj2.getWratio()) {
        if (obj1.getGoal() == obj2.getGoal()) {
            if (obj1.getname() < obj2.getname()) {
                return true;
            }
        }
    }
    return false;


}  