// LinkedListBigOh.cpp, by Junteng Tan (1489763)
// lab 10c, The "LinkedListBigOh" program
// Editor(s) used: xcode text Edit
// Compiler(s) used: xcode

#include <iostream>
#include "LinkedList.h"
#include <cassert>
#include <cmath>
#include <ctime>
using namespace std;

int main(int argc, const char * argv[]) {
  cout << "Lab 10c, The \"LinkedListBigOh\" Program " << endl
       << "Programmer: Junteng Tan" << endl
       << "Editor(s) used: xcode text Edit" << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
  
  int n = 5000;
  string bigOh = "O(1)";
  const int REPS = 50000; // for timing fast operations, use REPS up to 100th of the starting n
  
  long elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;

  //operator[] assignment at zeroth index, O(1)
  cout << "\noperator[] assignment at zeroth index, O(1)" << endl;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2) {
    // more problem setup goes here -- the stuff not timed
    LinkedList<double> list;
    for (int i = 0; i < n; i++) {
      list.insert(rand());
    }
    
    clock_t startTime = clock();
    for (int reps = 0; reps < REPS; reps++) {
      list[100];
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
  
  //operator[] assignment at 100th index, O(1)
  n = 5000;
  bigOh = "O(1)";
  elapsedTimeTicksNorm = 0;
  expectedTimeTicks = 0;
  
  cout << "\noperator[] assignment at 100th index, O(1)" << endl;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2) {
    // more problem setup goes here -- the stuff not timed
    LinkedList<double> list;
    for (int i = 0; i < n; i++) {
      list.insert(rand());
    }
    
    clock_t startTime = clock();
    for (int reps = 0; reps < REPS; reps++) {
      list[100];
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

   //iteration from first to last using operator[], O(n)
  n = 500;
  bigOh = "O(n)";
  elapsedTimeTicksNorm = 0;
  expectedTimeTicks = 0;
  
  cout << "\niteration from first to last using operator[], O(n)" << endl;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2) {
    // more problem setup goes here -- the stuff not timed
    LinkedList<double> list;
    for (int i = 0; i < n; i++) {
      list.insert(rand());
    }
    
    clock_t startTime = clock();
    for (int i = 0; i < list.length(); i++) {
      list[i];
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

   //length, O(1)
  n = 50000;
  bigOh = "O(1)";
  elapsedTimeTicksNorm = 0;
  expectedTimeTicks = 0;
  
  cout << "\nlength, O(1)" << endl;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2) {
    // more problem setup goes here -- the stuff not timed
    LinkedList<double> list;
    for (int i = 0; i < n; i++) {
      list.insert(rand());
    }
    
    clock_t startTime = clock();
    for (int reps = 0; reps < REPS; reps++) {
      list.length();
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