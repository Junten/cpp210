// DvcSchedule5b.cpp, by Junteng Tan (1489763)
// lab 5b, The "DvcSchedule5b" program
// Editor(s) used: xcode text Edit
// Compiler(s) used: xcode

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cassert>
#include "StaticArray.h"

using namespace std;

struct SubjectCode {
  string name;
  int count;
};


struct termAndSection {
  string semester;
  string sectionNumber;
};

int main() {
  cout << "Lab 5b, The \"DvcSchedule5b\" Program " << endl
       << "Programmer: Junteng Tan" << endl
       << "Editor(s) used: xcode text Edit" << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  char* token;
  char buf[1000];
  int progressCount = 0;
  Array<SubjectCode, 1000> data;
  Array<termAndSection, 1000> data1;
  SubjectCode temp;
  string line;
  int counter = 0;
  int dupliCount =0;
  bool dupliCourse;
  bool courseExist;
  clock_t startTime = clock();
  double elapsedSeconds;

  
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) {
    cout << "Unable to open file" << endl;
  }

  while (!fin.eof()) {
    progressCount++;
    if (progressCount % 1000 == 0) {
        cout << ".";
    }
 
    dupliCourse = false;
    courseExist = false;
    
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue;
    
    const string term(token = strtok(buf, "\t"));
    const string section(token = strtok(NULL, "\t"));
    const string course((token = strtok(NULL, "\t, -")) ? token : "");
    

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
    
     
      for (int i = 0; i < counter + 1; i++) {
        if (course.compare(data[i].name) == 0) {
          courseExist = true;
          data[i].count++;
        }
      }
    
      if (courseExist == false) {
        data[counter].name = course;
        data[counter].count = 1;
        counter++;
      }
    }
    assert(counter <= 1000);
  }
  fin.close();

  cout.flush();
  cout << endl;

  for (int i = 0; i <= counter; i++) {
    for (int j = i + 1; j <= counter; j++) {
      if (data[j].name < data[i].name) {
        temp.name = data[i].name;
        temp.count = data[i].count;
        data[i].name = data[j].name;
        data[i].count = data[j].count;
        data[j].name = temp.name;
        data[j].count = temp.count;
      }
    }
  }

  elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
 
  for (int i = 1; i < counter; i++) {
    cout << data[i].name << ", "<< data[i].count  << " Classes"<< endl;
  }
  cout << "\nThe duplicates entries are " << dupliCount << endl;
  cout << "The processing time is: "  << elapsedSeconds << " seconds." << endl;
  
  return 0;
}

