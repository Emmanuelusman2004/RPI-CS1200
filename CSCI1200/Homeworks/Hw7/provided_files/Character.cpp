#ifndef _Character_cpp_
#define _Character_cpp_
#include "Character.h"

int Character::getFrame(std::string move) {
    if (move == "jab") {
        return jab_frame;
    }    
    else if (move == "forward-tilt") {
        return f_tilt_frame;
    }
    else if (move == "up-tilt") {
        return u_tilt_frame;
    }    
    else if (move == "down-tilt") {
        return d_tilt_frame;
    }
    else if (move == "forward-smash") {
        return f_smash_frame;
    }
    else if (move == "up-smash") {
        return u_smash_frame;
    }    
    else if (move == "down-smash") {
        return d_smash_frame;
    }
    return -1;
}

Character::Character(std::string ch_name, int jab, int f_tilt, int u_tilt, int d_tilt, int f_smash, int u_smash, int d_smash) {
    character = ch_name;
    jab_frame = jab;
    f_tilt_frame = f_tilt;
    u_tilt_frame = u_tilt;
    d_tilt_frame = d_tilt;
    f_smash_frame = f_smash;
    u_smash_frame = u_smash;
    d_smash_frame = d_smash;
}

#endif

