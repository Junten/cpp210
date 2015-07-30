// DvcSchedule14b.cpp
// lab 14b, The "DvcSchedule14b" program

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cassert>
#include <set>
#include "SortableArray.h"

using namespace std;

struct SubjectCode {
  string name;
  int count;
  bool operator<(SubjectCode parameter) {
    if (name < parameter.name) return true;
    return false;
  }
};

int main() {
  cout << "Lab 5b, The \"DvcSchedule14b\" Program " << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  char* token;
  char buf[1000];
  Array<SubjectCode, 500> data;
  set<string> dupli_Set;
  set<string>::iterator itDuplicate;
  SubjectCode temp;
  string line;
  int counter = 0;
  int dupliCount =0;
  bool courseExist;
  clock_t startTime = clock();
  double elapsedSeconds;

  
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) {
    cout << "Unable to open file" << endl;
  }

  while (!fin.eof()) {
    courseExist = false;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue;
    
    const string term(token = strtok(buf, "\t"));
    const string section(token = strtok(NULL, "\t"));
    const string course((token = strtok(NULL, "\t, -")) ? token : "");
    
    itDuplicate = dupli_Set.find(term + section);
    if (itDuplicate != dupli_Set.end()) {
      dupliCount++;
    } else {
      dupli_Set.insert(term+section);
      for (int i = 0; i < counter + 1; i++) {
        if (course.compare(data[i].name) == 0) {
          courseExist = true;
          data[i].count++;
        }
      }
      if (courseExist == false) {
        data[counter].name = course;
        data[counter].count++;
        counter++;
      }
    }
    assert(counter <= 500);
  }
  fin.close();
  
  data.sort(counter);
  
  elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
 
  for (int i = 0; i < counter; i++) {
    if (i == counter - 1) break;
    cout << data[i].name << ", "<< data[i].count  << " Classes"<< endl;
  }
  cout << "\nThe duplicates entries are " << dupliCount << endl;
  cout << "The processing time is: "  << elapsedSeconds << " seconds." << endl;
  
  return 0;
}