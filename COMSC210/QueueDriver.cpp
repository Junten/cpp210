// QueueDriver.cpp
// lab 8b, The "QueueDriver" program

#include <iostream>
#include <cassert>
#include "Queue.h"

using namespace std;

#include "Queue.h" // testing ifdef

int main() {
  cout << "Lab 8b, The \"QueueDriver\" Program " << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
  
  Queue<int> queue;
  int peek;
  int pop;
  bool result;
  
  cout << "\nTesting member function push()" << endl;
  queue.push(12);
  queue.push(13);
  
  cout << "\nTesting member function peek()";
  result = queue.peek(peek);
  cout << "\nThe expected result is true and 12"
       << "\nThe actual result is " << boolalpha << result << " and "  << peek << endl;
  assert(result == true);
  assert(peek == 12);
  
  cout << "\nTesting member function isEmpty()"
       << "\nThe expected result is false"
       << "\nThe actual result is " << boolalpha << queue.isEmpty() << endl;
  assert(queue.isEmpty() == false);
  
  cout << "\nTesting member function pop()";
  result = queue.pop(pop);
  cout << "\nThe expected result is true and 12"
       << "\nThe actual result is " << boolalpha << result << " and "  << pop << endl;
  assert(result == true);
  assert(pop == 12);
  
  cout << "\nTesting member function makeEmpty" << endl;
  queue.makeEmpty();
  cout << "\nThe expected result is true"
       << "\nThe actual result is " << boolalpha << queue.isEmpty() << endl;
  assert(queue.isEmpty() == true);
  
   //object copy testing
  cout << "\n**************************************"
       << "\nObject copy testing";
  Queue<int> copy1 = queue;
  
  cout << "\nTesting member function push()" << endl;
  copy1.push(11);
  copy1.push(12);
  copy1.push(13);
  
  cout << "\nTesting member function peek()";
  result = copy1.peek(peek);
  cout << "\nThe expected result is ture and 11"
       << "\nThe actual result is " << boolalpha << result << " and "  << peek << endl;
  assert(result == true);
  assert(peek == 11);
  
  cout << "\nTesting member function isEmpty()"
       << "\nThe expected result is false"
       << "\nThe actual result is " << boolalpha << copy1.isEmpty() << endl;
  assert(copy1.isEmpty() == false);
  
  cout << "\nTesting member function pop()";
  result = copy1.pop(pop);
  cout << "\nThe expected result is true and 11"
       << "\nThe actual result is " << boolalpha << result << " and "  << pop << endl;
  assert(result == true);
  assert(pop == 11);
  
  cout << "\nTesting member function makeEmpty" << endl;
  copy1.makeEmpty();
  cout << "The expected result is true"
       << "\nThe actual result is " << boolalpha << copy1.isEmpty() << endl;
  assert(copy1.isEmpty() == true);
  
  //objecy assignmnet testing
  cout << "\n**************************************"
       << "\nObject assignment testing";
  Queue<int> copy2;
  copy2 = queue;
  
  cout << "\nTesting member function push()" << endl;
  copy2.push(10);
  copy2.push(11);
  copy2.push(12);
  copy2.push(13);
  
  cout << "\nTesting member function peek()";
  result = copy2.peek(peek);
  cout << "\nThe expected result is ture and 10"
       << "\nThe actual result is " << boolalpha << result << " and "  << peek << endl;
  assert(result == true);
  assert(peek == 10);
  
  cout << "\nTesting member function isEmpty()"
       << "\nThe expected result is false"
       << "\nThe actual result is " << boolalpha << copy2.isEmpty() << endl;
  assert(copy2.isEmpty() == false);
  
  cout << "\nTesting member function pop()";
  result = copy2.pop(pop);
  cout << "\nThe expected result is true and 10"
       << "\nThe actual result is " << boolalpha << result << " and "  << pop << endl;
  assert(result == true);
  assert(pop == 10);
  
  cout << "\nTesting member function makeEmpty" << endl;
  copy2.makeEmpty();
  cout << "The expected result is true"
       << "\nThe actual result is " << boolalpha << copy2.isEmpty() << endl;
  assert(copy2.isEmpty() == true);

  return 0;
}