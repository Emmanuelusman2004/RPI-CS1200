#include <iostream>
#include <fstream>
#include <cstdlib>


int main(int argc, char* argv[]) {
int x = 1;
for (int i = 1; i < argc; ++i) {
    x*= atoi(argv[i]);
}
    std::cout << x;
}

