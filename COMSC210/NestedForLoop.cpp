// NestedForLoop.cpp
// lab 9b, The "NestedForLoop" program

#include <iostream>
#include <fstream>
#include <ctime>
#include <cassert>
#include <cmath>
#include <string>

using namespace std;

int main() {
  cout << "Lab 9b, The \"NestedForLoop\" Program " << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  int n = 500;
  string bigOh = "O(n squared)";
  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2) {
    // more problem setup goes here -- the stuff not timed
    double* array = new double[n];
    for (int i = 0; i < n; i++) {
      array[i] = rand();
    }
    
    clock_t startTime = clock();
 
    for (int i = 0; i < n; i++) {
      for(int j = i + 1; j < n; j++) {
        if (array[i] > array[j]) {
          double temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
      }
    }
    for (int i = 1; i < n; i++) {
      assert (array[i - 1] <= array[i]);
    }
    clock_t endTime = clock();

    delete[] array;
    
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