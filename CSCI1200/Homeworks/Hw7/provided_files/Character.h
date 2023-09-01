#ifndef _Character_h_
#define _Character_h_
#include <iostream>

class Character {
public:
//constructors
Character() {

}
Character(std::string ch_name, int jab = 0 , int f_tilt = 0, int u_tilt = 0, int d_tilt = 0, int f_smash = 0, int u_smash = 0, int d_smash = 0);

//getters
std::string getName() {
    return character;
}
int getJab() {
    return jab_frame;
}
int getFtilt() {
    return f_tilt_frame;
}
int getUtilt() {
    return u_tilt_frame;
}
int getDtilt() {
    return d_tilt_frame;
}
int getFsmash() {
    return f_smash_frame;
}
int getUsmash() {
    return u_smash_frame;
}
int getDsmash() {
    return d_smash_frame;
}

int getFrame(std::string move);


//setters

//set argument

void setArgument(std::string argument) { //check if ill need this later
    file_argument = argument;
}











private:
std::string character;
int jab_frame = 0;
int f_tilt_frame = 0;
int u_tilt_frame = 0;
int d_tilt_frame = 0;
int f_smash_frame = 0;
int u_smash_frame = 0;
int d_smash_frame = 0;
std::string file_argument;

};

#endif