#ifndef _Customer_h_
#define _Customer_h_
#include <iostream>

using namespace std;

class Customers {
public:
Customers();
Customers(string acustomer_ID, string aaction, int atime, int aquantity_requested, string atool_ID, string aname);
//setters


void add_tool_renting(string tool_id);

void add_tool_pending(string tool_id);

void remove_tool_renting(string tool_id);

void remove_tool_pending(string tool_id);


//getters
string get_customer_id() {
    return customer_ID;
}


string get_action() {
    return action;
}
int get_time() {
    return time;
}
int get_quantity_requested() {
    return quantity_requested;
}
string get_tool_id() {
    return tool_ID;
}
string get_name() {
    return name;
}



private:

string customer_ID;
string action;
int time;
int quantity_requested;
string tool_ID;
string name;
std::list<string>tool_renting;
std::list<string>tool_pending;


};

#endif