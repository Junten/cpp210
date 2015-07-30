// DvcSchedule6a.cpp,
// lab 6a, The "DvcSchedule6a" program

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
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
  cout << "Lab 6a, The \"DvcSchedule6a\" Program " << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  char* token;
  char buf[1000];
  vector<SubjectCode> data;
  Array<termAndSection, 1000> data1;
  SubjectCode temp;
  int progressCount = 0;
  string line;
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
    dupliCourse = false;
    courseExist = false;

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
      for (int i = 0; i != data.size(); i++) {
        if (course.compare(data[i].name) == 0) {
          courseExist = true;
          data[i].count++;
        }
      }

      if (courseExist == false) {
        SubjectCode subjectCode;
        subjectCode.name = course;
        subjectCode.count = 1;
        data.push_back(subjectCode);
      }
    }
  }
  fin.close();

  for (int i = 0; i != data.size(); i++) {
    for (int j = i + 1; j != data.size(); j++) {
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

  for (int i = 0; i != data.size() - 1; i++) {
    cout << data[i].name << ", " << data[i].count << " Classes" << endl;
  }
  cout << "\nThe duplicates entries are " << dupliCount << endl;
  cout << "The processing time is: " << elapsedSeconds << " seconds." << endl;

  return 0;
}