#include <string>
// Basic Node struct for linked list.
struct Node {
	std::string value;
	Node* next;

    ~Node() {
        if(next != nullptr) {
            delete next;
        }
    }
};

