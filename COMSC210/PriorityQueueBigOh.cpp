// PriorityQueueBigOh.cpp
// lab 12b, The "PriorityQueueBigOh" program

#include <iostream>
#include <ctime>
#include <cassert>
#include <cmath>
#include <string>
#include "PriorityQueue.h"
using namespace std;

#include "PriorityQueue.h" // testing ifndef

int main(int argc, const char * argv[]) {
  cout << "Lab 12b, The \"PriorityQueueBigOh\" Program " << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
  
  int n = 5000;
  const int REPS = 47;
  string bigOh = "O(log n)";
  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  
  cout << "\nenqueue, O(log n)" << endl;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2) {
    PriorityQueue<int> enq;
    for (int i = 0; i < n; i++) {
      enq.enqueue(n - i);
    }

    clock_t startTime = clock();
    for (int reps = 0; reps < REPS; reps++) {
      enq.enqueue(n + reps);
    }
    clock_t endTime = clock();
    
    int data[REPS];
    for (int reps = 0; reps < REPS; reps++) {
      data[reps] = enq.dequeue();
    }
    for (int i = 0; i < REPS; i++) {
      for (int j = i + 1; j < REPS; j++) {
        assert(data[j] <= data[i]);
      }
    }
    
    long elapsedTimeTicks = (long)(endTime - startTime);
    double factor = pow(2.0, cycle);
    if (cycle == 0)
      elapsedTimeTicksNorm = elapsedTimeTicks;
    else if (bigOh == "O(1)")
      expectedTimeTicks = elapsedTimeTicksNorm;
    else if (bigOh == "O(log n)")
      expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n)")
      expectedTimeTicks = factor * elapsedTimeTicksNorm;
    else if (bigOh == "O(n log n)")
      expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n squared)")
      expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;
    
    cout << elapsedTimeTicks;;
    if (cycle == 0)
      cout << " (expected " << bigOh << ')';
    else
      cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n = " << n << endl;

  }
  
  n = 5000;
  bigOh = "O(log n)";
  elapsedTimeTicksNorm = 0;
  expectedTimeTicks = 0;
  
  cout << "\ndequeue, O(log n)" << endl;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2) {
    PriorityQueue<int> deq;
    for (int i = 0; i < n; i++) {
      deq.enqueue(n-i);
    }
    
    clock_t startTime = clock();
    for (int reps = 0; reps < REPS; reps++) {
      deq.dequeue();
    }
    clock_t endTime = clock();
    
    long elapsedTimeTicks = (long)(endTime - startTime);
    double factor = pow(2.0, cycle);
    if (cycle == 0)
      elapsedTimeTicksNorm = elapsedTimeTicks;
    else if (bigOh == "O(1)")
      expectedTimeTicks = elapsedTimeTicksNorm;
    else if (bigOh == "O(log n)")
      expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n)")
      expectedTimeTicks = factor * elapsedTimeTicksNorm;
    else if (bigOh == "O(n log n)")
      expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n squared)")
      expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;
    
    cout << elapsedTimeTicks;;
    if (cycle == 0)
      cout << " (expected " << bigOh << ')';
    else
      cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n = " << n << endl;

  }
  return 0;
}