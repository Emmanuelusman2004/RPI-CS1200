#include <iostream>
#include <vector>

//problem 13.2 in the practice test

void recursionfor(int i, int n) {
    if (i < n) {
        std::cout<<i<<std::endl; //my for loop just prints out numbers
        recursionfor(i+1,n);
    }
}


int main() {

recursionfor(0,35);






}