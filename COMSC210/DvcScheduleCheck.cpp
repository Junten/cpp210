// DvcScheduleCheck.cpp
// Term Project, The "DvcScheduleCheck" program

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

int main() {
  cout << "Term Project, The \"DvcScheduleCheck\" program " << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
       
  char* token;
  char buf[1000];
  string line;
  multimap<string, string> data;
  typename map<string, string>::iterator it;
  map<string, string> result;
  ifstream fin;
  string term;
  string section;
  string course;
  int i = 0;
  
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
    const string instructor((token = strtok(NULL, "\t")) ? token : "");
    const string whenWhere((token = strtok(NULL, "\t")) ? token : "");
    
    it = data.find(term + "-" + section);
    if (it == data.end())
      data.insert(make_pair(term + "-" + section, course));
    else {
      
      if (it->second != course) {
        result.insert(make_pair(term + "-" + section + "-" + course, it->first + "-" + it->second));
      }
    }
  }

  cout << "\nThere are total " << result.size() << " invalid entries in the database and list blow:" << endl;
  for (it = result.begin(); it != result.end(); it++) {
    strcpy(buf, it->first.c_str());
    term = (token = strtok(buf, "-"));
    section = (token = strtok(NULL, "-"));
    course = (token =  strtok(NULL, "\t"));
    
    cout << "\n\t" << ++i << ". " << term << ", section " << section  << ", " << course ;
    
    strcpy(buf, it->second.c_str());
    term = (token = strtok(buf, "-"));
    section = (token = strtok(NULL, "-"));
    course = (token =  strtok(NULL, "\t"));
    
    cout << "\n\t   " << term << ", section " << section  << ", " << course << endl;

  }
  
  return 0;
}