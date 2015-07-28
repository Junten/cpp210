// DvcSchedule7a.cpp, by Junteng Tan (1489763)
// lab 7a, The "DvcSchedule7a" program
// Editor(s) used: xcode text Edit
// Compiler(s) used: xcode

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "StaticArray.h"
using namespace std;

struct SubjectCode {
  string name;
  int count;

  inline bool operator<(SubjectCode arg) {
    if (name.compare(arg.name) < 0) {
    return true;
    }
    return false;
  }
};

struct Node {
  SubjectCode data;
  Node* next;

};

struct termAndSection {
  string semester;
  string sectionNumber;
};

bool foundData(SubjectCode);

int main() {
  cout << "Lab 7a, The \"DvcSchedule7a\" Program " << endl
       << "Programmer: Junteng Tan" << endl
       << "Editor(s) used: xcode text Edit" << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  char* token;
  char buf[1000];
  Node* start = 0;
  Node* p;
  Node *prev;
  Node* q;
  Array<termAndSection, 1000> data1;
  string line;
  int dupliCount =0;
  bool dupliCourse;
  bool found;
  clock_t startTime = clock();
  double elapsedSeconds;
  ifstream fin;

  fin.open("dvc-schedule.txt");
  if (!fin.good()) {
    cout << "Unable to open file" << endl;
  }

  while (!fin.eof()) {
    dupliCourse = false;
    found = false;
    
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue;
    
    const string term(token = strtok(buf, "\t"));
    const string section(token = strtok(NULL, "\t"));
    const string course(token = strtok(NULL, "\t, -"));

    for (int i = 1; i < 1000; i++) {
      if (term.compare(data1[i].semester) == 0 &&
        section.compare(data1[i].sectionNumber) == 0) {
        dupliCourse = true;
      }
    }
   
    if (dupliCourse == true) {
      dupliCount++;
    } else {
      for (int i = 1; i < 1000; i++) {
        data1[i].semester = term;
        data1[i].sectionNumber = section;
      }
      p = start;
      while (p != NULL && !found) {
        if (p->data.name.compare(course) == 0) {
          found = true;
        }
        if (!found) {
          p = p->next;
        }
      }
      if (found) {
        p->data.count++;
      } else {
        Node* node = new Node;
        node->data.name = course;
        node->data.count = 1;
        node->next = start;
        start = node;
      }
    }
  }
  fin.close();
  
  for (p = start; p; p = p->next) {
    for (q = p->next; q; q = q->next) {
      if (q->data < p->data) {
        SubjectCode temp = p->data;
        p->data = q->data;
        q->data = temp;
      }
    }
  }
  
  elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  
  for (p = start;p ;p = p->next) {
    if (p -> data.name != "course")
      cout << p->data.name << ", " << p->data.count << " Classes" << endl;
  }
  
  cout << "\nThe duplicates entries are " << dupliCount << endl;
  cout << "The processing time is: "  << elapsedSeconds << " seconds." << endl;
  return 0;
}

