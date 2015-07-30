// HashTableDriver.cpp
// lab 11a, The "HashTable" program

#include "HashTable.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include <fstream>
using namespace std;

#include "HashTable.h" // testing the ifndef


int convertStrToInt (string);

struct cell {
  string course;
  string term;
  string section;
  string instructor;

  bool operator==(const cell& c) const {
    return course == c.course && term == c.term && section == c.section;
  }
  
  int HashCode() const {
    int term_Int;
    int course_Int;
    term_Int = convertStrToInt(term);
    course_Int = convertStrToInt(course);
    return atoi(section.c_str()) + term_Int - course_Int;
  }
};

int convertStrToInt (string str) {
  char strPtr[20];
  int str_Int = 0;
  strcpy(strPtr, str.c_str());
  for (int i = 0; i < 20; i++) {
    str_Int  += atoi(&strPtr[i]);
  }
  return str_Int;
}

int main() {
  cout << "Lab 11a, The \"HashTable\" Program " << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
  
  char* token;
  char buf[1000];
  ifstream fin;
  string line;
  HashTable<cell, 1009> dataHash;
  cell dataCell;
  cell cellRemove;
  bool TestResult;
  
  fin.open("dvc-schedule.txt");
  if (!fin.good()) {
    cout << "\nUnable to open the file" << endl;
    return 0;
  }
  
  cout << "\nTesting function insert(const DataType&)" << endl;
  for (int i; i < 100; i++) {
    getline(fin, line);
    strcpy(buf, line.c_str());
    
    const string term(token = strtok(buf, "\t"));
    dataCell.term = term;
    const string section((token = strtok(0, "\t")) ? token : " ");
    dataCell.section = section;
    const string course((token = strtok(0, "\t")) ? token : " ");
    dataCell.course = course;
    const string instructor((token = strtok(0, "\t")) ? token : " ");
    dataCell.instructor = instructor;
    
    dataHash.insert(dataCell); //testing function insert(const DataType&)
  }
  
  fin.close();

  fin.open("dvc-schedule.txt");
  if (!fin.good()) {
    cout << "\nUnable to open the file" << endl;
    return 0;
  }
  
  cout << "\nTesting function retrieve(DataType&)" << endl;
  for (int i; i < 100; i++) {
    getline(fin, line);
    strcpy(buf, line.c_str());
 
    const string term(token = strtok(buf, "\t"));
    dataCell.term = term;
    const string section((token = strtok(0, "\t")) ? token : " ");
    dataCell.section = section;
    const string course((token = strtok(0, "\t")) ? token : " ");
    dataCell.course = course;
    const string instructor((token = strtok(0, "\t")) ? token : " ");
    dataCell.instructor = instructor;
    
    assert(dataHash.retrieve(dataCell)); //testing function retrieve(DataType&)
  }
  fin.close();
  
  cout << "\nTesting function size()"
       << "\nThe actual result is "
       << dataHash.size()
       << "\nThe duplicate entries is "
       << 100 - dataHash.size() << endl;
  
  cout << "\nTesting function replace(const DataType&, const DataType&)";
  cell dataCellReplace;
  dataCellReplace.section = "1176";
  dataCellReplace.course = "MATH-075";
  dataCellReplace.term = "Summer 2007";
  cout << "\nThe expected result is true"
       << "\nThe actual result is ";
  TestResult = dataHash.replace(dataCell, dataCellReplace);
  cout << TestResult<< endl;
  assert(TestResult == true);
  
  cout << "\nTesting function remove(DataType&)"
       << "\nThe expected result is true"
       << "\nThe actual result is ";
  TestResult = dataHash.remove(dataCellReplace);
  cout << TestResult  << endl;
  assert(TestResult == true);
  
  cout << "\nTesting function clear()"
       << "\nThe expected result is 0"
       << "\nThe actual result is ";
  dataHash.clear();
  int size = dataHash.size();
  cout << size << endl;
  assert(size == 0);
  
  cout << "\n************************************************"
       << "\nObject copy Test" << endl;
  
  fin.open("dvc-schedule.txt");
  if (!fin.good()) {
    cout << "\nUnable to open the file" << endl;
    return 0;
  }
  
  for (int i; i < 100; i++) {
    getline(fin, line);
    strcpy(buf, line.c_str());
 
    const string term(token = strtok(buf, "\t"));
    dataCell.term = term;
    const string section((token = strtok(0, "\t")) ? token : " ");
    dataCell.section = section;
    const string course((token = strtok(0, "\t")) ? token : " ");
    dataCell.course = course;
    const string instructor((token = strtok(0, "\t")) ? token : " ");
    dataCell.instructor = instructor;
    
    dataHash.insert(dataCell);
  }
  fin.close();

  HashTable<cell, 1009> dataHashCopy = dataHash;
  
  fin.open("dvc-schedule.txt");
  if (!fin.good()) {
    cout << "\nUnable to open the file" << endl;
    return 0;
  }
  
  cout << "\nTesting function retrieve(DataType&)" << endl;
  for (int i; i < 100; i++) {
    getline(fin, line);
    strcpy(buf, line.c_str());
 
    const string term(token = strtok(buf, "\t"));
    dataCell.term = term;
    const string section((token = strtok(0, "\t")) ? token : " ");
    dataCell.section = section;
    const string course((token = strtok(0, "\t")) ? token : " ");
    dataCell.course = course;
    const string instructor((token = strtok(0, "\t")) ? token : " ");
    dataCell.instructor = instructor;
    
    assert(dataHashCopy.retrieve(dataCell)); //testing function retrieve(DataType&) for dataHashCopy
  }
  fin.close();
  
  cout << "\nTesting function size()"
       << "\nThe actual result is "
       << dataHashCopy.size()
       << "\nThe duplicate entries is "
       << 100 - dataHashCopy.size() << endl;
  
  cout << "\nTesting function replace(const DataType&, const DataType&)";
  cout << "\nThe expected result is true"
       << "\nThe actual result is ";
  TestResult = dataHashCopy.replace(dataCell, dataCellReplace);
  cout << TestResult<< endl;
  assert(TestResult == true);
  
  cout << "\nTesting function remove(DataType&)"
       << "\nThe expected result is true"
       << "\nThe actual result is ";
  TestResult = dataHashCopy.remove(dataCellReplace);
  cout << TestResult  << endl;
  assert(TestResult == true);
  
  cout << "\nTesting function clear()"
       << "\nThe expected result is 0"
       << "\nThe actual result is ";
  dataHashCopy.clear();
  int sizeCopy = dataHashCopy.size();
  cout << sizeCopy << endl;
  assert(sizeCopy == 0);
  
  cout << "\nTesting function insert(const DataType&)"
       << "\nThe expected result is true";
  TestResult = dataHashCopy.insert(dataCellReplace);
  cout << "\nThe actual result is "
       << TestResult << endl;
  assert(TestResult == true);
  
   cout << "\n************************************************"
       << "\nObject Assignment Test" << endl;
  
  HashTable<cell, 1009> dataHashAssign;
  dataHashAssign = dataHash;
  
  fin.open("dvc-schedule.txt");
  if (!fin.good()) {
    cout << "\nUnable to open the file" << endl;
    return 0;
  }
  
  cout << "\nTesting function retrieve(DataType&)" << endl;
  for (int i; i < 100; i++) {
    getline(fin, line);
    strcpy(buf, line.c_str());
 
    const string term(token = strtok(buf, "\t"));
    dataCell.term = term;
    const string section((token = strtok(0, "\t")) ? token : " ");
    dataCell.section = section;
    const string course((token = strtok(0, "\t")) ? token : " ");
    dataCell.course = course;
    const string instructor((token = strtok(0, "\t")) ? token : " ");
    dataCell.instructor = instructor;
    
    assert(dataHashAssign.retrieve(dataCell)); //testing function retrieve(DataType&) for dataHashCopy
  }
  fin.close();
  
  cout << "\nTesting function size()"
       << "\nThe actual result is "
       << dataHashAssign.size()
       << "\nThe duplicate entries is "
       << 100 - dataHashAssign.size() << endl;
  
  cout << "\nTesting function replace(const DataType&, const DataType&)";
  cout << "\nThe expected result is true"
       << "\nThe actual result is ";
  TestResult = dataHashAssign.replace(dataCell, dataCellReplace);
  cout << TestResult<< endl;
  assert(TestResult == true);
  
  cout << "\nTesting function remove(DataType&)"
       << "\nThe expected result is true"
       << "\nThe actual result is ";
  TestResult = dataHashAssign.remove(dataCellReplace);
  cout << TestResult  << endl;
  assert(TestResult == true);
  
  cout << "\nTesting function clear()"
       << "\nThe expected result is 0"
       << "\nThe actual result is ";
  dataHashAssign.clear();
  int sizeAssign = dataHashAssign.size();
  cout << sizeAssign << endl;
  assert(sizeAssign == 0);
  
  cout << "\nTesting function insert(const DataType&)"
       << "\nThe expected result is true";
  TestResult = dataHashAssign.insert(dataCellReplace);
  cout << "\nThe actual result is "
       << TestResult << endl;
  assert(TestResult == true);

  return 0;
}

