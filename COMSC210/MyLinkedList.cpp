// MyLinkedList.cpp
// lab 10a, The "MyLinkedList" program

#include <iostream>
#include "LinkedList.h"
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
  cout << "Lab 10b, The \"MyLinkedList\" Program " << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  LinkedList<int> list;
  string userEnter;
  int parameter;
  int index;
  
  do {
    cout << "\nPlease Enter your number for you list: ";
    cin >> userEnter;
    if (userEnter != "q" && userEnter != "Q") {
      list.insert(atoi(userEnter.c_str()));
    }
    
  } while (userEnter != "q" && userEnter != "Q");
  
  cout << "\nThe data that you enter are: ";
  list.first(parameter);
  cout << parameter << " ";
  while (list.getNext(parameter)) {
    cout << parameter << " ";
  }
  
  cout << "\nPlease enter the data that you want to search or enter Q(q) to exit:: ";
  cin >> userEnter;
  while (userEnter != "q" && userEnter != "Q") {
    index = 0;
    int temp = atoi(userEnter.c_str());
    if (list.first(parameter)) {
      do {
        index++;
        if (temp == parameter)
        break;
      } while (list.getNext(parameter));
    }
    cout << "\nThe position of the data that you enter is: " << index << endl
         << "\n Please enter another data that you want or search or enter Q(q) to exit: ";
    cin >> userEnter;
  }
  
  return 0;
}
