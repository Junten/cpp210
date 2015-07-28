// LinkedListDriver.cpp, by Junteng Tan (1489763)
// lab 10a, The "LinkedList" program
// Editor(s) used: xcode text Edit
// Compiler(s) used: xcode

#include "LinkedList.h"
#include <iostream>
#include <cassert>

using namespace std;

#include "LinkedList.h" // testing ifndef

int main() {
  cout << "Lab 10a, The \"LinkedList\" Program " << endl
       << "Programmer: Junteng Tan" << endl
       << "Editor(s) used: xcode text Edit" << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
       
  LinkedList<int> list;
  int parameter;
  bool testResult;

  cout << "\nTesting member function insert()." << endl;
  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.insert(4);
  list.insert(5);
  
  cout << "\nTesting member function first(). Expected Value is true and 5" << endl;
  testResult = list.first(parameter);
  cout << "The actual value is " << boolalpha << testResult  << " and " << parameter << endl;
  assert(true == testResult);
  assert(5 == parameter);

  cout << "\nTesting member function getNext(). Expected Value is true and 4" << endl;
  testResult = list.getNext(parameter);
  cout << "The actual value is " << boolalpha << testResult << " and " << parameter << endl;
  assert(true == testResult);
  assert(4 == parameter);
  
  cout << "\nTesting member function operator[]. Expected Value is 5" << endl;
  cout << "The actual value is " << list[0] << endl;
  assert(5 == list[0]);
  
  cout << "\nTesting member function find(). Expected Value is true" << endl;
  testResult = list.find(4);
  cout << "The actual value is " << boolalpha << testResult << endl;
  assert(true == testResult);

  cout << "\nTesting member function retrieve(). Expected Value is true" << endl;
  parameter = 3;
  testResult = list.retrieve(parameter);
  cout << "The actual value is " << boolalpha << testResult << endl;
  assert(true == testResult);

  cout << "\nTesting member function replace(). Expected Value is true" << endl;
  testResult = list.replace(6);
  cout << "The actual value is " << boolalpha << testResult << endl;
  assert(true == testResult);

  cout << "\nTesting member function remove(). Expected Value is true" << endl;
  parameter = 2;
  testResult = list.remove(parameter);
  cout << "The actual value is " << boolalpha << testResult << endl;
  assert(true == testResult);

  cout << "\nTesting member function isEmpty(). Expected Value is false" << endl;
  testResult = list.isEmpty();
  cout << "The actual value is " << boolalpha << testResult << endl;
  assert(false == testResult);

  cout << "\nTesting member function length(). Expected Value is 4" << endl;
  cout << "The actual value is " << list.length() << endl;
  assert(4 == list.length());

  cout << "\nTesting member function makeEmpty(). Expected Value is true" << endl;
  list.makeEmpty();
  testResult = list.isEmpty();
  cout << "The actual value is " << boolalpha << testResult << endl;
  assert(true == testResult);

  //Object copy testing
  cout << "\n**************************************************************"
	     << "\nObject Copy testing" << endl;
  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.insert(4);
  LinkedList<int> copy = list;

  cout << "\nTesting member function first(). Expected Value is true and 4" << endl;
  testResult = list.first(parameter);
  cout << "The actual value is " << boolalpha << testResult << " and " << parameter << endl;
  assert(true == testResult);
  assert(4 == parameter);
  
  cout << "\nTesting member function getNext(). Expected Value is true and 3" << endl;
  testResult = list.getNext(parameter);
  cout << "The actual value is " << boolalpha << testResult << " and " << parameter << endl;
  assert(true == testResult);
  assert(3 == parameter);
  
  cout << "\nTesting member function operator[]. Expected Value is 1" << endl;
  cout << "The actual value is " << list[3] << endl;
  assert(1 == list[3]);

  cout << "\nTesting member function find(). Expected Value is true" << endl;
  testResult = list.find(4);
  cout << "The actual value is " << boolalpha << testResult << endl;
  assert(true == testResult);

  cout << "\nTesting member function retrieve(). Expected Value is true" << endl;
  parameter = 2;
  testResult = list.retrieve(parameter);
  cout << "The actual value is " << boolalpha << testResult << endl;
  assert(true == testResult);

  cout << "\nTesting member function replace(). Expected Value is true" << endl;
  testResult = list.replace(1);
  cout << "The actual value is " << boolalpha << testResult << endl;
  assert(true == testResult);

  cout << "\nTesting member function remove(). Expected Value is true" << endl;
  parameter = 1;
  testResult = list.remove(parameter);
  cout << "The actual value is " << boolalpha << testResult << endl;
  assert(true == testResult);

  cout << "\nTesting member function isEmpty(). Expected Value is false" << endl;
  testResult = list.isEmpty();
  cout << "The actual value is " << boolalpha << testResult << endl;
  assert(false == testResult);

  cout << "\nTesting member function length(). Expected Value is 3" << endl;
  cout << "The actual value is " << list.length() << endl;
  assert(3 == list.length());
  
  cout << "\nTesting member function makeEmpty(). Expected Value is true" << endl;
  list.makeEmpty();
  testResult = list.isEmpty();
  cout << "The actual value is " << boolalpha << testResult << endl;
  assert(true == testResult);

  //Object assignmnet testing
   cout << "\n**************************************************************"
	      << "\nObject assignment testing" << endl;
  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.insert(4);
  list.insert(5);
  list.insert(6);
  LinkedList<int> copyAssign;
  copyAssign = list;

    cout << "\nTesting member function first(). Expected Value is true and 6" << endl;
  testResult = list.first(parameter);
  cout << "The actual value is " << boolalpha << testResult << " and " << parameter << endl;
  assert(true == testResult);
  assert(6 == parameter);
  
  cout << "\nTesting member function getNext(). Expected Value is true and 5" << endl;
  testResult = list.getNext(parameter);
  cout << "The actual value is " << boolalpha << testResult << " and " << parameter << endl;
  assert(true == testResult);
  assert(parameter);
  
  cout << "\nTesting member function operator[]. Expected Value is 3" << endl;
  cout << "The actual value is " << list[3] << endl;
  assert(3 == list[3]);

  cout << "\nTesting member function find(). Expected Value is true" << endl;
  testResult = list.find(4);
  cout << "The actual value is " << boolalpha << testResult << endl;
  assert(true == testResult);

  cout << "\nTesting member function retrieve(). Expected Value is true" << endl;
  parameter = 2;
  testResult = list.retrieve(parameter);
  cout << "The actual value is " << boolalpha << testResult << endl;
  assert(true == testResult);

  cout << "\nTesting member function replace(). Expected Value is true" << endl;
  testResult = list.replace(1);
  cout << "The actual value is " << boolalpha << testResult << endl;
  assert(true == testResult);

  cout << "\nTesting member function remove(). Expected Value is true" << endl;
  parameter = 1;
  testResult = list.remove(parameter);
  cout << "The actual value is " << boolalpha << testResult << endl;
  assert(true == testResult);

  cout << "\nTesting member function isEmpty(). Expected Value is false" << endl;
  testResult = list.isEmpty();
  cout << "The actual value is " << boolalpha << testResult << endl;
  assert(false == testResult);

  cout << "\nTesting member function length(). Expected Value is 5" << endl;
  cout << "The actual value is " << list.length() << endl;
  assert(5 == list.length());
  
  cout << "\nTesting member function makeEmpty(). Expected Value is true" << endl;
  list.makeEmpty();
  testResult = list.isEmpty();
  cout << "The actual value is " << boolalpha << testResult << endl;
  assert(true == testResult);
  return 0;
}