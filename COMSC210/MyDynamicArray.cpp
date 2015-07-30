// MyDynamicArray.cpp
// lab 6c, The "MyDynamicArray" program

#include <iostream>
#include "DynamicArray.h"

using namespace std;


int main() {
  cout << "Lab 6c, The \"MyDynamicArray\" Program " << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  DynamicArray<int> array = DynamicArray<int>(1000);
  string userEnter;
  int size = 0;
  int index;
  int i;
  
  for (i = 0; i < 1000; i++) {
    cout << "\nPlease Enter your number for index " << i << ": ";
    cin >> userEnter;
    if (userEnter == "q" || userEnter == "Q") {
      break;
    } else {
      array[i] = atoi(userEnter.c_str());
    }
    size++;
  }
  
  cout << "\nThe data that you enter are: ";
  for (i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  
  cout << "\n\nImplement linear search" << endl
       << "\nPlease enter the data that you want to search or enter Q(q) to exit:: ";
  cin >> userEnter;
  
  while (userEnter != "q" && userEnter != "Q") {
    index = array.lsearch(atoi(userEnter.c_str()));
    cout << "\nThe position of the data that you enter is: " << index << endl
         << "\n Please enter another data that you want or search or enter Q(q) to exit: ";
    cin >> userEnter;
  }
  
  return 0;
}