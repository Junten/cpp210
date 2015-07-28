// DvcScheduleSearch.cpp, by Junteng Tan (1489763)
// Term Project, The "DvcScheduleSearch" program
// Editor(s) used: xcode text Edit
// Compiler(s) used: xcode

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

bool compareTerm(string term1, string term2) {
  char buf[100];
  char* token;
  
  strcpy(buf, term1.c_str());
  const string season1(token = strtok(buf, " "));
  const string year1((token = strtok(0, " ")) ? token : "");
  
  strcpy(buf, term2.c_str());
  const string season2(token = strtok(buf, " "));
  const string year2((token = strtok(0, " ")) ? token : "");
  
  if (year1 == year2) {
    if (season1 == "Spring")
      return true;
    else if (season1 == "Fall")
      return false;
    else if (season2 == "Spring")
      return false;
    else if (season2 == "Fall")
      return true;
    else
      return true;
  } else
    return year1 > year2;
}

int main() {
  cout << "Term Project, The \"DvcScheduleSearch\" program " << endl
       << "Programmer: Junteng Tan" << endl
       << "Editor(s) used: xcode text Edit" << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
  
  char* token;
  char buf[1000];
  string line;
  map<string, string> data;
  typename map<string, string>::iterator it;
  ifstream fin;
  string userInput;
  
  fin.open("dvc-schedule.txt");
  if (!fin.good()) {
    cout << "\nUnable to open file" << endl;
    return 0;
  }
  
  while (!fin.eof()) {
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue;
    
    const string term(token = strtok(buf, "\t"));
    const string section(token = strtok(NULL, "\t"));
    const string course(token = strtok(NULL, "\t"));
    
    strcpy(buf, term.c_str());
    const string season(token = strtok(buf, " "));
    const string year((token = strtok(0, " ")) ? token : "");
    
    it = data.find(course);
    if (it == data.end())
      data.insert(make_pair(course, term));
    else {
      if (compareTerm(term, it->second) == true)
        data[course] = term;
    }
  }
  fin.close();
  
  do {
    cout << "\nEnter the course that you are looking for or \"X\"/\"x\" to Exit: "
         << "\n(including a subject code, a dash, and an alphanumeric sequence number, such as COMSC-210) ";
    cin >> userInput;
    
    if (userInput != "X" && userInput != "x") {
      it = data.find(userInput);
      if (it != data.end())
        cout << it->first << " was last offered in " << it->second << endl;
      else
        cout << userInput << " has not been offered since the year 2000." << endl;
    }
  } while (userInput != "X" && userInput != "x");


  return 0;
}