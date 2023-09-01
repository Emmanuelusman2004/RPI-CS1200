#ifndef _Inventory_h_
#define _Inventory_h_
#include <iostream>



using namespace std;

class Inventory {
public:
Inventory(string id, int q, string t);
//list of pending customers for tool
//list of people currently renting tool

//setter
void set_quantity(int amount);
void add_pending_customer(string cid);
void add_current_renters(string cid);
void remove_renter(string cid);
void remove_pending_renter(string cid);

//getters
string get_ID();
int get_quantity();
unsigned int get_size_renting() {
    return current_renters.size();
}
unsigned int get_size_pending() {
    return pending_customers.size();
}
string get_tool_name();
bool check_for_id(string pending_or_renting, string cid);
list<string> get_list(string pendingorrenting) {
    if (pendingorrenting == "renting") {
        return current_renters;
    }
    else {
        return pending_customers;
    }
}

private:

string ID;
int quantity;
string tool_name;
list<string> pending_customers;
list<string> current_renters;

};

#endif