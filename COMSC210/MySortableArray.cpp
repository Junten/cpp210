// MySortableArray.cpp
// lab 5a, The "MySortableArray" program

#include <iostream>
#include <string>
#include <cstdlib>
#include "SortableArray.h"
using namespace std;


int main() {
  cout << "Lab 5a, The \"MySortableArray\" Program " << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
	
  Array<int, 1000> array;
  string userEnter;
  string userEnter2;
  int size = 0;
  int index;
  int i;

  for (i = 0; i < 1000; i++) {
    cout << "\nPlease Enter Q(q) to exit or your number for index " << i << ": ";
    cin >> userEnter;
    if (userEnter == "q" || userEnter == "Q") {
      break;
    } else {
      array[i] = atoi(userEnter.c_str());
    }
    size++;
  }
  
  cout << "\nThe unsorting datas that you enter are: ";
  for (i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  
  cout << "\n\n***********************************************************"
       << "\nImplement linear search" << endl
       << "Please enter the data that you want to search or enter Q(q) to exit: ";
  cin >> userEnter;

  while (userEnter != "q" && userEnter != "Q") {
  cout << "\n\tPlease enter the numbers of the elements that you want to search: ";
  cin >> userEnter2;
    index = array.lsearch(atoi(userEnter.c_str()), atoi(userEnter2.c_str()));
    cout << "\nThe position of the data that you enter is: " << index << endl
         << "\nPlease enter another data that you want or search or enter Q(q) to exit: ";
    cin >> userEnter;
  }
  
  cout << "\n***********************************************************" << endl;
  array.sort(size);
  cout << "\nThe datas after sorting are: ";
  for (i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  
  cout << "\n***********************************************************"
       << "\n\nImplement binary search" << endl
       << "Please enter the data that you want to search or enter Q(q) to exit:: ";
  cin >> userEnter;
  
  while (userEnter != "q" && userEnter != "Q") {
    cout << "\n\tPlease enter the starting elements that you want to search: ";
    cin >> userEnter2;
    int s = atoi(userEnter2.c_str());
    cout << "\n\tPlease enter the ending elements that you want to search: ";
    cin >> userEnter2;
    int e = atoi(userEnter2.c_str());
    index = array.bsearch(atoi(userEnter.c_str()), s, e);
    cout << "\nThe position of the data that you enter is: " << index << endl
         << "\nPlease enter another data that you want or search or enter Q(q) to exit: ";
    cin >> userEnter;
  }
  return 0;
}