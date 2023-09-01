// A simple "caller ID" program

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


/*
the cost of this program is O(1) because the add operation is O(1) and the identify is O(1)

if we had a 7 or 10 digit number it would create a vector of much larger amount and store a lot of values as unassigned
and the running time would increase by alot. It probably wouldn't work on a cellphone because it can take too much memory
or take too much runtime.
*/

/*
the new version is much better because it only stores the phone numbers we have as opposed to adding a ton of numbers. It also runs in 
O(N log(N)) runtime.
*/




// add a number, name pair to the phonebook
void add(std::map<int, std::string> &phonebook, int number, string const& name) {
  phonebook[number] = name;
}

// given a phone number, determine who is calling
void identify(std::map<int, std::string> & phonebook, int number) {
  // if (phonebook[number] == "UNASSIGNED") 
  //   cout << "unknown caller!" << endl;
  // else 
  //   cout << phonebook[number] << " is calling!" << endl;
  if (phonebook.find(number) == phonebook.end()) {
      std::cout<< "Unknown Caller!" <<std::endl;
  }
  else {
    std::cout<<phonebook[number] << " is calling!" << std::endl;
  }
}


int main() {
  // create the phonebook; initially all numbers are unassigned
  //vector<string> phonebook(10000, "UNASSIGNED");
  std::map<int, std::string>phonebook;

  // add several names to the phonebook
  add(phonebook, 1111, "fred");
  add(phonebook, 2222, "sally");
  add(phonebook, 3333, "george");

  // test the phonebook
  identify(phonebook, 2222);
  identify(phonebook, 4444);






}
