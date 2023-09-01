#include "Customers.h"

using namespace std;
Customers::Customers() {

}
Customers::Customers(string acustomer_ID, string aaction, int atime, int aquantity_requested, string atool_ID, string aname) {
    customer_ID = acustomer_ID;
    action = aaction;
    time = atime;
    quantity_requested = aquantity_requested;
    tool_ID = atool_ID;
    name = aname;

}

void Customers::add_tool_renting(string tool_id) {
    tool_renting.push_back(tool_id);
}
void Customers::add_tool_pending(string tool_id) {
    tool_pending.push_back(tool_id);
}
void Customers::remove_tool_renting(string cid) {
    for (list<string>::iterator r = tool_renting.begin(); r != tool_renting.end(); r++) {
        if (*r == cid) {
            tool_renting.erase(r);
        }
    }
}
void Customers::remove_tool_pending(string cid) {
    for (list<string>::iterator p = tool_pending.begin(); p != tool_pending.end(); p++) {
        if (*p == cid) {
            tool_pending.erase(p);
        }
    }
}


 