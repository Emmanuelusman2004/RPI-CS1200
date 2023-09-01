#include <iostream>


using namespace std;

void compute_squares(unsigned int a[], unsigned int b[], unsigned int n) {
    unsigned int* p1;
    unsigned int* p2;
    for (p1 = a, p2 = b; p1 < a + n; p1++,p2++) {
        unsigned int bObject = (*p1) * (*p1);
        *p2 =  bObject;
        cout<<*p2<<endl;
    }
}

int main() {
    unsigned int array1[4] = {1,2,3,4};
    unsigned int array2[0] = {};
    unsigned int n = 4;
    compute_squares(array1,array2,n);
}