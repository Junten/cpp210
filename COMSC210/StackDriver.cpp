// StackDriver.cpp
// lab 8a, The "StackDriver" program

#include <iostream>
#include <cassert>
#include "Stack.h"

using namespace std;
#include "Stack.h" // testing ifndef

int main() {
  cout << "Lab 8a, The \"StackDriver\" Program " << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  Stack<int> stack;
  Stack<int> stackCopy;
  int peek;
  int pop;
  bool result;
  
  cout << "\nTesting member function push()" << endl;
  stack.push(11);
  stack.push(12);
  stack.push(13);
  stackCopy = stack; // testing the operator=
  
  cout << "\nTesting member function peek()";
  result = stack.peek(peek);
  cout << "\nThe expected result is ture and 13"
       << "\nThe actual result is " << boolalpha << result << " and "  << peek << endl;
  assert(result == true);
  assert(peek == 13);
  
  cout << "\nTesting member function isEmpty()"
       << "\nThe expected result is false"
       << "\nThe actual result is " << boolalpha << stack.isEmpty() << endl;
  assert(stack.isEmpty() == false);
  
  cout << "\nTesting member function pop()";
  result = stack.pop(pop);
  cout << "\nThe expected result is true and 13"
       << "\nThe actual result is " << boolalpha << result << " and "  << pop << endl;
  assert(result == true);
  assert(pop == 13);
  
  cout << "\nTesting member function makeEmpty" << endl;
  stack.makeEmpty();
  result = stack.isEmpty();
  cout << "The expected result is true"
       << "\nThe actual result is " << boolalpha << result << " and " << endl;
  assert(result == true);
  
  //object copy testing
  cout << "\n************************************"
       << "\nObject copy testing";
  Stack<int> copy1 = stack;
  
  cout << "\nTesting member function push()" << endl;
  copy1.push(11);
  copy1.push(12);
  copy1.push(13);
  
  cout << "\nTesting member function peek()";
  result = copy1.peek(peek);
  cout << "\nThe expected result is ture and 13"
       << "\nThe actual result is " << boolalpha << result << " and "  << peek << endl;
  assert(result == true);
  assert(peek == 13);
  
  cout << "\nTesting member function isEmpty()"
       << "\nThe expected result is false"
       << "\nThe actual result is " << boolalpha << copy1.isEmpty() << endl;
  assert(copy1.isEmpty() == false);
  
  cout << "\nTesting member function pop()";
  result = copy1.pop(pop);
  cout << "\nThe expected result is true and 13"
       << "\nThe actual result is " << boolalpha << result << " and "  << pop << endl;
  assert(result == true);
  assert(pop == 13);
  
  cout << "\nTesting member function makeEmpty" << endl;
  copy1.makeEmpty();
  result = copy1.isEmpty();
  cout << "The expected result is true"
       << "\nThe actual result is " << boolalpha << result << " and " << endl;
  assert(result == true);
  
  //objecy assignmnet testing
  cout << "\n************************************"
       << "\nObject assignment testing";
  Stack<int> copy2;
  copy2 = stack;
  
  cout << "\nTesting member function push()" << endl;
  copy2.push(11);
  copy2.push(12);
  copy2.push(13);
  
  cout << "\nTesting member function peek()";
  result = copy2.peek(peek);
  cout << "\nThe expected result is ture and 13"
       << "\nThe actual result is " << boolalpha << result << " and "  << peek << endl;
  assert(result == true);
  assert(peek == 13);
  
  cout << "\nTesting member function isEmpty()"
       << "\nThe expected result is false"
       << "\nThe actual result is " << boolalpha << copy2.isEmpty() << endl;
  assert(copy2.isEmpty() == false);
  
  cout << "\nTesting member function pop()";
  result = copy2.pop(pop);
  cout << "\nThe expected result is true and 13"
       << "\nThe actual result is " << boolalpha << result << " and "  << pop << endl;
  assert(result == true);
  assert(pop == 13);
  
  cout << "\nTesting member function makeEmpty" << endl;
  copy2.makeEmpty();
  result = copy2.isEmpty();
  cout << "The expected result is true"
       << "\nThe actual result is " << boolalpha << result << " and " << endl;
  assert(result == true);
  return 0;
}