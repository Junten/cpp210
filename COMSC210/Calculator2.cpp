// Lab 2c, The "Calculator" Program
// Programmer: Junteng Tan
// Editor(s) used: xcode text Edit
// Compiler(s) used: xcode

#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
using namespace std;

stack<double> calculator(stack<double>, string);
void print(stack<double>, string);

int main() {
  cout << "Lab 2c, The \"Calculator\" Program \n";
  cout << "Programmer: Junteng Tan\n";
  cout << "Editor(s) used: Xcode text Edit\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  string value;
  stack<double> stack;
  
  cout << "Enter: ";
  cin >> value;
  
  while (value != "Q") {
    if (value == "+") {
      stack = calculator(stack, value);
      print(stack, value);
    } else if(value == "-") {
      stack = calculator(stack, value);
      print(stack, value);
    } else if (value == "*") {
      stack = calculator(stack, value);
      print(stack, value);
    } else if (value == "/") {
      stack = calculator(stack, value);
      print(stack, value);
    } else {
      cout << "Enter: ";
      stack.push(atof(value.c_str()));
      for (auto count = stack; !count.empty(); count.pop()) {
      cout << count.top() << "  ";
      }
    }
    cin >> value;
     
  }
  return 0;
}

stack<double> calculator(stack<double> s, string op) {
  stack<double> stack;
  double result;
  double a, b;
  
  stack = s;
  if (stack.size() >= 2) {
    a = stack.top();
    stack.pop();
    b = stack.top();
    stack.pop();
    if (op == "+") {
      result = b + a;
    } else if (op == "-") {
      result = b - a;
    } else if (op == "*") {
      result = b * a;
    } else {
      result = b / a;
    }
    stack.push(result);
  }
  
  return stack;
}

void print(stack<double> stack, string value) {
  cout << "Enter: ";
  for (auto count = stack; !count.empty(); count.pop()) {
  cout << count.top() << "  ";
  }
}