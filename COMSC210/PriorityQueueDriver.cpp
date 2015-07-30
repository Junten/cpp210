// PriorityQueueDriver.cpp
// lab 12a, The "PriorityQueue" program

#include <iostream>
#include "PriorityQueue.h"
#include <cassert>
using namespace std;

#include "PriorityQueue.h" // testing ifndef

int main(int argc, const char * argv[]) {
  cout << "Lab 12a, The \"PriorityQueue\" Program " << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
  PriorityQueue<int> pq;
  
  cout << "\nTesting the function enquene()" << endl;
  for (int i = 0; i < 5; i++) {
    pq.enqueue(i);
  }
  
  cout << "\nTesting the function getSize()"
       << "\nThe expected result is 5."
       << "\nThe actual result is " << pq.getSize() << endl;
  assert(pq.getSize() == 5);
  
  cout << "\nTesting the funciton dequeue()" << endl;
  int data[5];
  for (int i = 0; i < 5; i++) {
    data[i] = pq.dequeue();
  }
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      assert(data[i] >= data[j]);
    }
  }
  
  cout << "\n********************************************"
       << "\nObject copy testing" << endl;
  
  PriorityQueue<int> pqCopy = pq;
  
  cout << "\nTesting the function enquene()" << endl;
  for (int i = 0; i < 6; i++) {
    pqCopy.enqueue(i);
  }
  
  cout << "\nTesting the function getSize()"
       << "\nThe expected result is 6."
       << "\nThe actual result is " << pqCopy.getSize() << endl;
  assert(pqCopy.getSize() == 6);
  
  cout << "\nTesting the funciton dequeue()" << endl;
  for (int i = 0; i < 6; i++) {
    data[i] = pqCopy.dequeue();
  }
  for (int i = 0; i < 6; i++) {
    for (int j = i + 1; j < 6; j++) {
      assert(data[i] >= data[j]);
    }
  }
  
  cout << "\n********************************************"
       << "\nObject assignment testing" << endl;
  
  PriorityQueue<int> pqAssign;
  pqAssign = pq;
  
  cout << "\nTesting the function enquene()" << endl;
  for (int i = 0; i < 6; i++) {
    pqAssign.enqueue(i);
  }
  
  cout << "\nTesting the function getSize()"
       << "\nThe expected result is 6."
       << "\nThe actual result is " << pqAssign.getSize() << endl;
  assert(pqAssign.getSize() == 6);
  
  cout << "\nTesting the funciton dequeue()" << endl;
  for (int i = 0; i < 6; i++) {
    data[i] = pqAssign.dequeue();
  }
  for (int i = 0; i < 6; i++) {
    for (int j = i + 1; j < 6; j++) {
      assert(data[i] >= data[j]);
    }
  }

  return 0;
}
