// FileInput.cpp
// lab 9a, The "FileInput" program

#include <iostream>
#include <fstream>
#include <ctime>
#include <cassert>
#include <cmath>
#include <string>

using namespace std;

int main() {
  cout << "Lab 9a, The \"FileInput\" Program " << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  int n = 5000;
  string bigOh = "O(n)";
  string line;
  char buf[1000];
  char* token;
  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  ifstream fin;
  
  
  
  for (int cycle = 0; cycle < 4; cycle++, n*= 2) {
  fin.open("dvc-schedule.txt");
  if (!fin.good()) {
    cout << "Unable to open file" << endl;
  }
    clock_t startTime = clock();
    for (int i = 0; i < n; i++) {
      getline(fin, line);
      strcpy(buf, line.c_str());
      const string term(token = strtok(buf, "\t"));
      const string section(token = strtok(NULL, "\t"));
      const string course(token = strtok(NULL, "\t, -"));
    }
    clock_t endTime = clock();
    fin.close();
    
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