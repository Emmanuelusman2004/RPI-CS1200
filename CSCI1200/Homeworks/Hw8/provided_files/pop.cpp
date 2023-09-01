#include "BPlusTree.h"

int main() {
    BPlusTree<int> b1(3);
    for (int i = 0; i < 6; i++) {
        b1.insert(i);
    }
}