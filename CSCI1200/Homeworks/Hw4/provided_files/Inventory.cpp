#include "Inventory.h"

using namespace std;

Inventory::Inventory(string id, int q, string t) {
    ID = id;
    quantity = q;
    tool_name = t;


}
void Inventory::set_quantity(int amount) {
    quantity = amount;
}
void Inventory::add_pending_customer(string cid) {
    pending_customers.push_back(cid);
}
void Inventory::add_current_renters(string cid) {
    current_renters.push_back(cid);
}
void Inventory::remove_renter(string cid) {
    for (list<string>::iterator p = current_renters.begin(); p!= current_renters.end(); p++) {
        if (cid == *p) {
            current_renters.erase(p);
        }
    }
}
void Inventory::remove_pending_renter(string cid) {
    for (list<string>::iterator c = pending_customers.begin(); c!= pending_customers.end(); c++) {
        if (cid == *c) {
            pending_customers.erase(c);
        }
    }
}



//getters
string Inventory::get_ID() {
    return ID;
}
int Inventory::get_quantity() {
    return quantity;
}

string Inventory::get_tool_name() {
    return tool_name;
}
bool Inventory::check_for_id(string pending_or_renting, string cid) {
    if (pending_or_renting == "pending") {
        for (list<string>::iterator p = pending_customers.begin(); p != pending_customers.end();p++) {
            if (*p == cid) {
                return true;
            }
        }
        return false;
    }
    else if (pending_or_renting == "renting") {
        for (list<string>::iterator r = current_renters.begin(); r != current_renters.end();r++) {
            if (*r == cid) {
                return true;
            }
        } 
        return false;
    }
    return false;
}
