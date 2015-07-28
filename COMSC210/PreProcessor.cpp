// PreProcessor.cpp, by Junteng Tan (1489763)
// lab 8c, The "PreProcessor" program
// Editor(s) used: xcode text Edit
// Compiler(s) used: xcode

#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

void printOpen(char&, int&, string&);
void printClose(char&, int&, string&);

int main() {
  cout << "Lab 8c, The \"PreProcessor\" Program " << endl
       << "Programmer: Junteng Tan" << endl
       << "Editor(s) used: xcode text Edit" << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
  
  string line;
  char* buf;
  int lineCount = 0;
  stack<int> lineNumStack;
  stack<char> stack;
  bool unMatchFound = false;
  char unMatchChar;
  char brace;
  ifstream fin;
  string fileName;
  
  cout << "\nEnter filename (H, CPP, JAVA, HTML, or JS): ";
  cin >> fileName;
  
  fin.open(fileName);
  if (!fin.good()) {
    cout << "Unable to open file" << endl;
    return 0;
  }
  
  while(!fin.eof()) {
    lineCount++;
    getline(fin, line);
    buf = new char[line.length()+1];
    strcpy(buf, line.c_str());
    
    for (int i = 0; i < line.length(); i++) {
      if (buf[i] == '{' || buf[i] == '[' || buf[i] == '(') {
        stack.push(buf[i]);
        lineNumStack.push(lineCount);
	    }
      if (buf[i] == '/') {
        if (buf[i + 1] == '*')
          stack.push(buf[i]);
          lineNumStack.push(lineCount);
      }
      
      if (buf[i] == '}') {
        if (stack.empty()) {
          unMatchFound = true;
          unMatchChar = '}';
       
          break;
        }
        if (stack.top() == '{') {
          stack.pop();
          lineNumStack.pop();
        } else {
          unMatchFound = true;
          unMatchChar = '}';
          
          break;
        }
      }
      if (buf[i] == ']') {
        if (stack.empty()) {
          unMatchFound = true;
          unMatchChar = ']';
      
          break;
        }
        if (stack.top() == '[') {
          stack.pop();
          lineNumStack.pop();
        } else {
          unMatchFound = true;
          unMatchChar = ']';
          
          break;
        }
      }
      if (buf[i] == ')') {
        if (stack.empty()) {
          unMatchFound = true;
          unMatchChar = ')';

          break;
        }
        if (stack.top() == '(') {
          stack.pop();
          lineNumStack.pop();
        } else {
          unMatchFound = true;
          unMatchChar = ')';
     
          break;
        }
      }
      if (buf[i] == '*' && buf[i+1] == '/') {
        if (stack.empty()) {
          unMatchFound = true;
          unMatchChar = '/';
         
          break;
        }
        if (stack.top() == '/') {
          stack.pop();
          lineNumStack.pop();
        } else {
          unMatchFound = true;
          unMatchChar = '/';
        
          break;
        }
      }
    }
    delete[] buf;
    
    if (unMatchFound == true) {
      if (stack.empty()) {
        printClose(unMatchChar, lineCount, fileName);
        break;
      } else {
        brace = stack.top();
        stack.pop();
        if (stack.empty()) {
          printClose(unMatchChar, lineCount, fileName);
          break;
        } else {
          if (stack.top() == '(') {
            if (unMatchChar == ')') {
              printOpen(brace, lineNumStack.top(), fileName);
              break;
            }
          } else {
            printClose(unMatchChar, lineCount, fileName);
            break;
          }
          if (stack.top() == '[') {
            if (unMatchChar == ']') {
              printOpen(brace, lineNumStack.top(), fileName);
              break;
            }
          } else {
            printClose(unMatchChar, lineCount, fileName);
            break;
          }
          if (stack.top() == '{') {
            if (unMatchChar == '}') {
              printOpen(brace, lineNumStack.top(), fileName);
              break;
            }
          } else {
            printClose(unMatchChar, lineCount, fileName);
            break;
          }if (stack.top() == '/') {
             if (unMatchChar == '/') {
               printOpen(brace, lineNumStack.top(), fileName);
               break;
             }
          } else {
            printClose(unMatchChar, lineCount, fileName);
            break;
          }
        }
      }
    }
  }
  fin.close();
  
  if (!stack.empty() && unMatchFound == false) {
    printOpen(stack.top(), lineNumStack.top(), fileName);
  }

  if (stack.empty() && unMatchFound == false) {
    cout << "\nNo mismatches found by my preprocessor " << fileName << endl;
  }
  return 0;
}

void printClose(char& op, int& lineCount, string& fileName) {
  if (op == ')') {
    cout << "\nClosing parentheses found in line " << lineCount << " of "  << fileName << endl
         << "But no matching opening parentheses found" << endl;
  }
  if (op == ']') {
    cout << "\nClosing square brackets found in line " << lineCount << " of "  << fileName << endl
         << "But no matching opening square brackets found" << endl;
  }
  if (op == '}') {
    cout << "\nClosing curly braces found in line " << lineCount << " of "  << fileName << endl
         << "But no matching opening curly braces found" << endl;
  }
  if (op == '/') {
    cout << "\nClosing comment offsets found in line " << lineCount << " of "  << fileName << endl
         << "But no matching opening comment offsets found" << endl;
  }
}

void printOpen(char& op, int& lineCount, string& fileName) {
   if (op == '(') {
    cout << "\nOpening parentheses found in line " << lineCount << " of "  << fileName << endl
         << "But no matching closing parentheses found" << endl;
  }
  if (op == '[') {
    cout << "\nOpening square brackets found in line " << lineCount << " of "  << fileName << endl
         << "But no matching closing square brackets found" << endl;
  }
  if (op == '{') {
    cout << "\nOpening curly braces found in line " << lineCount << " of "  << fileName << endl
         << "But no matching closing curly braces found" << endl;
  }
  if (op == '/') {
    cout << "\nOpening comment offsets found in line " << lineCount << " of "  << fileName << endl
         << "But no matching closeing comment offsets found" << endl;
  }
}
