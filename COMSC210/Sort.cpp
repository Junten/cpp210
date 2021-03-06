// Sort.cpp
// lab 9c, The "Sort" program

#include <iostream>
#include <fstream>
#include <ctime>
#include <cassert>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  cout << "Lab 9c, The \"Sort\" Program " << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  int n = 10000;
  string bigOh = "O(n log n)";
  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  
  for (int cycle = 0; cycle < 4; cycle++, n*= 2) {
    double* array = new double[n];
    for (int i = 0; i < n; i++) {
      array[i] = rand();
    }
    
    clock_t startTime = clock();
    sort(array, array + n);
    clock_t endTime = clock();
    for (int i = 1; i < n; i++) {
      assert (array[i - 1] <= array[i]);
    }
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