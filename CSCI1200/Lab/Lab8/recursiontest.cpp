#include <iostream>

int paths(int x, int y){
    if (x == 0 || y == 0) {
        return 1;
    }
    else{ 
        return paths(x-1,y) + paths(x, y-1);
    }
}


int main () {
    std::cout<<paths(0,0)<<std::endl;
    std::cout<<paths(2,1)<<std::endl;
    std::cout<<paths(5,5)<<std::endl;
}

