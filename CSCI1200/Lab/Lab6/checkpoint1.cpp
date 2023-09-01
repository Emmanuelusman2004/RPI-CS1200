#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;
template <class T>
void print(std::list<T> &data, const std::string &label) {
  std::cout << label << " ";
  for (typename std::list<T>::iterator i = data.begin(); i != data.end(); i++) {
    std::cout << " " << *i;
  }
  std::cout << std::endl;
}


template <class T>
void reverse(std::list<T> &data) {
  unsigned int half;
  T temp;
  half = data.size()/2;
  int counter = 0;
  typename std::list<T>::reverse_iterator p = data.rbegin();
  for (typename std::list<T>::iterator i = data.begin(); i != data.end(); i++) {
    if (counter<=half) {
    temp = *i;
    *i = *p;
    *p = temp;
    p++;
    counter+=1;
    }
    else{
      break;
    }
  }
  
}


int main() {
  std::list<int> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
  data.push_back(4);
  data.push_back(5);
  data.push_back(6);
  data.push_back(7);

  print(data,"before:");
  reverse(data);
  print(data,"after: ");

  std::list<std::string> data2;
  data2.push_back("apple");
  data2.push_back("banana");
  data2.push_back("carrot");
  data2.push_back("date");

  print(data2,"before:");
  reverse(data2);
  print(data2,"after: ");
}
