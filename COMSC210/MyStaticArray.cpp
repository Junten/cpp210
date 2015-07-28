// MyStaticArray.cpp, by Junteng Tan (1489763)
// lab 5a, The "MyStaticArray" program
// Editor(s) used: xcode text Edit
// Compiler(s) used: xcode

#include <iostream>
#include <string>
#include <cstdlib>
#include "StaticArray.h"
using namespace std;
#include "StaticArray.h"

int main() {
  cout << "Lab 5a, The \"MyStaticArray\" Program " << endl
       << "Programmer: Junteng Tan" << endl
       << "Editor(s) used: xcode text Edit" << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
	
  Array<int, 1000> array;
  string userEnter;
  string userEnter2;
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