// Calculator8 by Junteng Tan (1489763)
// lab 8a, The "Calculator8" program
// Editor(s) used: xcode text Edit
// Compiler(s) used: xcode

#include <iostream>
#include <cstdlib>
#include "Stack.h"
#include <string>

using namespace std;

int main() {
  cout << "Lab 8a, The \"Calculator8\" Program " << endl
       << "Programmer: Junteng Tan" << endl
       << "Editor(s) used: xcode text Edit" << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
  
  string value;
  Stack<double> s;
  Stack<double> copy;
  double a, b;
  double pop;
  
  do {
    cout << "\nEnter: ";
    copy = s;
    while (!copy.isEmpty()) {
      copy.pop(pop);
      cout << pop << " ";
    }

    cin >> value;
    
    if (value == "+") {
      if (s.isEmpty() == false)
        s.pop(a);
      if (s.isEmpty() == false)
        s.pop(b);
      s.push(b + a);
    } else if(value == "-") {
      if (s.isEmpty() == false)
        s.pop(a);
      if (s.isEmpty() == false)
        s.pop(b);
      s.push(b - a);
    } else if (value == "*") {
      if (s.isEmpty() == false)
        s.pop(a);
      if (s.isEmpty() == false)
        s.pop(b);
      s.push(b * a);
    } else if (value == "/") {
      if (s.isEmpty() == false)
        s.pop(a);
      if (s.isEmpty() == false)
        s.pop(b);
      s.push(b / a);
    } else {
      s.push(atof(value.c_str()));
    }
  } while (value != "Q" && value != "q");
  
  return 0;
}

