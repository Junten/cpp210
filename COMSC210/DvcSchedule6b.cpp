// DvcSchedule6b.cpp
// lab 6a, The "DvcSchedule6b" program

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include "StaticArray.h"

using namespace std;

struct Course {
  string name;
  int count;
};

struct SubjectCode {
  string name;
  vector<Course> courses;
};

struct termAndSection {
  string semester;
  string sectionNumber;
};

int main() {
  cout << "Lab 6b, The \"DvcSchedule6b\" Program " << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  char* token;
  char buf[1000];
  vector<SubjectCode> data;
  Array<termAndSection, 1000> data1;
  SubjectCode temp;
  string line;
  int dupliCount =0;
  bool dupliCourse;
  bool courseExist;
  bool courseCodeExist;
  clock_t startTime = clock();
  double elapsedSeconds;
  ifstream fin;

  fin.open("dvc-schedule.txt");
  if (!fin.good()) {
    cout << "Unable to open file" << endl;
  }

  while (!fin.eof()) {
    
    dupliCourse = false;
    courseCodeExist = false;
    courseExist = false;
    
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue;
    
    const string term(token = strtok(buf, "\t"));
    const string section(token = strtok(NULL, "\t"));
    const string courseCode(token = strtok(NULL, "\t"));
	  char courseCopy[20];
	  strcpy(courseCopy,courseCode.c_str());
	  const string course(token = strtok(courseCopy, "-"));

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
        }
      }
      if (courseExist == false) {
        SubjectCode subjectcode;
        subjectcode.name = course;
        data.push_back(subjectcode);
      } else {
        for (int i = 0; i != data.size(); i++) {
          for (int j = 0; j != data[i].courses.size(); j++) {
            if (data[i].courses[j].name.compare(courseCode) == 0) {
              courseCodeExist = true;
              data[i].courses[j].count++;
            }
          }
        }
        if (courseCodeExist == false) {
          Course classes1;
          classes1.name = courseCode;
          classes1.count = 1;
          for (int i = 0; i != data.size(); i++) {
            if (course.compare(data[i].name) == 0)
              data[i].courses.push_back(classes1);
          }
        }
      }
    }
  }
  fin.close();
  
  for (int i = 0; i != data.size(); i++) {
    for (int j = i + 1; j != data.size(); j++) {
      if (data[j].name < data[i].name) {
        temp.name = data[i].name;
        temp.courses = data[i].courses;
        data[i].name = data[j].name;
        data[i].courses = data[j].courses;
        data[j].name = temp.name;
        data[j].courses = temp.courses;
      } 
    }
  }
  
  elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  
  for (int i = 0; i != data.size(); i++) {
    if (data[i].name != "course")
      cout << "\n" << data[i].name << ", " << data[i].courses.size() << " course(s)" << endl;
    for (int j = 0; j != data[i].courses.size(); j++){
      cout << "\t" << data[i].courses[j].name << ", " << data[i].courses[j].count << " class(es)" << endl;
    }
  }
  
  cout << "\nThe duplicates entries are " << dupliCount << endl;
  cout << "The processing time is: " << elapsedSeconds << " seconds." << endl;

  return 0;
}