#include <iostream>
#include <iomanip>
#include <list>
#include <cctype>
#include <string>
#include <bits/stdc++.h>
#include "Customers.cpp"
#include "Inventory.cpp"

using namespace std;

bool check_id(const string word) {    //this function is supposed to check to make sure
    for (int i = 1; i < 5; i++) {     //the id is a valid ID meaning all the XXXX in TXXXX
        if (!isdigit(word[i])) {      //are actually digits
            return true;
        }

    }
    return false;
}

int main(int argc, char* argv[]) {  //this is the error checker for the file with the cerr message
    //error checking
    std::ifstream myInventoryFile;
    myInventoryFile.open(argv[1], ios::in);
    if (!myInventoryFile.is_open()) {
          std::cerr<<"Inventory File could not open"<<endl;
        exit(1);
     }

    //declaring variables
    string id,name;
    int quantity;
    list<Inventory>tools;

    //iterate through file
    while (myInventoryFile >> id) {     //we iterate through word by word and set the words equal to what
        myInventoryFile>>quantity>>name;//we had initialized earlier(id,name,quantity)
        //check if te id is valid
        if ((id[0] != 'T' && isdigit(id[1])) || check_id(id)) {    //here we make sure its a valid id
            cerr<<"Invalid inventory ID"<<id.substr(1,5)<<"found in the inventory file."<<endl;
            continue;   //above we take a substr to print out the numbers in the inventory ID
        }
        //declare the object
        Inventory tool(id,quantity,name);
        //if this is the first time we put a tool in we just pushback if not sort.
        if (tools.size() == 0) {
            tools.push_back(tool);
        }
        else {
            //this is how i sort
            int i = 0;
            for (list<Inventory>::iterator i = tools.begin();i != tools.end();i++) {        
                string id = (*i).get_ID(); //take the iterator id
                int id_num = stoi(id.substr(1,5)); //get just the number of the id
                if (stoi(tool.get_ID().substr(1,5)) < id_num) { //compare the numbers of ids,if less the id is
                    tools.insert(i,tool);                       //inserted in the list before the next iteration  
                    i++;
                }

                
            }
            if (i == 0) {
                tools.push_back(tool);
            }
        }
    }
    
        

    
    std::ifstream myCustomerFile; //here I error check again after opening the file and check with .is_open()
    myCustomerFile.open(argv[2], ios::in);
    if (!myCustomerFile.is_open()) {
         std::cerr<<"Customer File could not open"<<endl;
         exit(1);
    }

    string cid, action, tool_id, customer_name; //similar to before we declare these variables then as we 
    int time, requested_quantity;               //go through the file we set the values and initialize the 
    list<Customers> people;                     //objects and insert in order.
    while (myCustomerFile >> cid) {
        myCustomerFile >> action >> time >> requested_quantity >> tool_id >> customer_name;
        if ((cid[0] != 'C' && isdigit(cid[1])) ||  !check_id(id)) { //check if valid customer
            std::cerr<<"Invalid customer information found for ID"<<cid.substr(1,5)<<"in the customer file."<<endl;
            continue;                                        //above take a substr for the digits in the customer id
        }
        if ((tool_id[0] != 'T' && isdigit(tool_id[1])) || !check_id(tool_id)) { //check if a valid tool id
            std::cerr<<"Customer CXXXX requested item TYYYY which is not in the inventory."<<endl;
            continue;
        }
        
        //checks to make sure that people are not init twice for diff actions.
        for (list<Customers>::iterator i = people.begin(); i != people.end(); i++) {
            if (cid == (*i).get_customer_id()) {
                continue;
            }
        }

        Customers customer(cid,action,time,requested_quantity,tool_id,name);
        if (people.size() == 0) { //pushback if the first time we add a customer obj to people list
            people.push_back(customer);
        }
        else {  //here we sort customers based on their id's
            int i = 0;
            for (list<Customers>::iterator i = people.begin();i != people.end();i++) {        
                string cust_id = (*i).get_customer_id();  //take the id of the customer
                int id_num = stoi(cust_id.substr(1,5)); //take the numbers from the customer id
                if (stoi(customer.get_customer_id().substr(1,5)) < id_num) { //compare the ids and then
                    people.insert(i,customer);    //the smaller id gets inserted before the id we find thats bigger
                    i++;
                }
            }
            if (i == 0) {                    
                people.push_back(customer); 
            }
        }


    }


    //after initializing everything we now iterate through all the customers
    //and complete requests.
    for (list<Customers>::iterator i = people.begin(); i != people.end(); i++) { 
        for (list<Inventory>::iterator j = tools.begin(); j != tools.end(); i++) {
            if ((*i).get_tool_id() == (*j).get_ID()) {  //we compare the tool id and the customers requested tool
                if ((*i).get_action() == "rent") { //we then get the action
                    if ((*i).get_quantity_requested() > (*j).get_quantity()) { 
                        //if the action is greater than the amount available
                        //place on pending list
                        (*j).add_pending_customer((*i).get_customer_id());
                        (*i).add_tool_pending((*j).get_ID());
                    }
                    else {
                        //place on renting list and reduce from the amount available
                        (*j).add_current_renters((*i).get_customer_id());
                        (*i).add_tool_renting((*j).get_ID());
                        (*j).set_quantity((*j).get_quantity() - (*i).get_quantity_requested());

                    }
                }
                else if ((*i).get_action() == "return") { 
                    //check if item returning is even in the inventory of items
                    for (list<Inventory>::iterator t = tools.begin(); t != tools.end(); t++) {
                       if ((*i).get_tool_id() != (*t).get_ID()) { 
                            cerr<<"Customer CXXXX attempted to return item TYYY which is not in the inventory";
                            continue;
                       }
                    }
                    //check if they rented the item in the first place
                    if ((*j).check_for_id("renting",(*i).get_customer_id())) {
                        //get amount requested from customer then add it to the amount available of tools
                        int added_quantity = (*i).get_quantity_requested();
                        (*j).set_quantity((*j).get_quantity() + added_quantity);
                        //if quantity returned is equal to the amount they had requested then remove customer from list
                        
                    }
                    else {
                        std::cerr<<"Customer CXXXX attemped to return item TYYYY which he/she did not rent."<<endl;
                        continue;
                    }
                }
                //check if the customer has any more requests then delete
                

                
            }
        }

    }


    std::ofstream MyInventoryoutputFile;
    MyInventoryoutputFile.open(argv[3]);
    if (!MyInventoryoutputFile.is_open()) {
        std::cerr<<"Inventory output file could not open"<<endl;
        exit(1);
    }
//here we output to the inventory file
    for (list<Inventory>::iterator p = tools.begin(); p != tools.end(); p++) {
        MyInventoryoutputFile<<(*p).get_ID()<<(*p).get_quantity()<<"available"<<(*p).get_tool_name()<<endl;
        if ((*p).get_size_renting() != 0) {
            MyInventoryoutputFile<<"Rental Customers: ";
            list<string>renting = (*p).get_list("renting");
            for (list<string>::iterator j = renting.begin(); j != renting.end(); j++) {
                for (list<Customers>::iterator k = people.begin(); k != people.end(); k++) {
                    if (*j == (*k).get_customer_id()) {
                        MyInventoryoutputFile<<(*j)<<(*k).get_name()<<(*k).get_quantity_requested();
                    }
                }
            }
        }
//here is the output for the pending customers
        if ((*p).get_size_pending() != 0) {
            MyInventoryoutputFile<<"Pending Customers: ";
            list<string>pending = (*p).get_list("pending");
            for (list<string>::iterator j = pending.begin(); j != pending.end(); j++) {
                for (list<Customers>::iterator k = people.begin(); k != people.end(); k++) {
                    if (*j == (*k).get_customer_id()) {
                        MyInventoryoutputFile<<(*j)<<(*k).get_name()<<(*k).get_quantity_requested();
                    }
                }
            }
        }
    }


    std::ofstream MyCustomeroutputFile(argv[4]);
    if (!MyCustomeroutputFile) {
        std::cerr<<"Customer output file could not open"<<endl;
        exit(1);
    }
    //was not able to finish the output or the attempt to output the customer information.






}
