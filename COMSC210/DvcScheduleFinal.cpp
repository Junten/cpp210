// DvcScheduleFinal.cpp, by Junteng Tan (1489763)
// Term Project, The "DvcScheduleFinal" program
// Editor(s) used: xcode text Edit
// Compiler(s) used: xcode

#include <iostream>
#include <map>
#include <fstream>
#include <cstring>
#include <ctime>

using namespace std;

int main() {
  cout << "Term Project, The \"DvcScheduleFinal\" program " << endl
       << "Programmer: Junteng Tan" << endl
       << "Editor(s) used: xcode text Edit" << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
  
  char* token;
  char buf[1000];
  string line;
  map<string, map<string, int> > dataMap;
  map<string, int> data;
  multimap<string, string> duplicate_Map;
  int duplicateCount = 0;
  typename map<string, int>::iterator it;
  typename map<string, map<string, int> >::iterator itMap;
  typename map<string, string>::iterator itDuplicate;
  ifstream fin;
  double elapsedSeconds;
  clock_t startTime = clock();
  
  fin.open("dvc-schedule.txt");
  if (!fin.good()) {
    cout << "Unable to open file" << endl;
    return 0;
  }
  
  while (!fin.eof()) {
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue;
    
    const string term(token = strtok(buf, "\t"));
    const string section(token = strtok(NULL, "\t"));
    const string courseCode(token = strtok(NULL, "\t"));
	  char courseCopy[20];
	  strcpy(courseCopy,courseCode.c_str());
	  const string course(token = strtok(courseCopy, "-"));
    
    itDuplicate = duplicate_Map.find(term);
    if (itDuplicate != duplicate_Map.end() && itDuplicate->second == section)
      duplicateCount++;
    else {
      duplicate_Map.insert(itDuplicate, make_pair (term, section));
      itMap = dataMap.find(course);
      if (itMap == dataMap.end())
        dataMap.insert(make_pair (course, data));
      else {
        it = dataMap[course].find(courseCode);
        if (it == dataMap[course].end())
          dataMap[course].insert(make_pair(courseCode, 1));
        else
          dataMap[course][courseCode]++;
      }
    }
  }
  fin.close();
  
  elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  for (itMap = dataMap.begin(); itMap != dataMap.end(); ++itMap) {
    if (itMap == --dataMap.end()) break;
    cout << "\n" << itMap->first << ", " << itMap->second.size() << " course(s)" << endl;
    for (it = itMap->second.begin(); it != itMap->second.end(); ++it)
      cout << "\t" << it->first << ", " << it->second << " class(es)" << endl;
  }
  cout << "\nThe duplicates entries are " << duplicateCount << endl;
  cout << "The processing time is: " << elapsedSeconds << " seconds." << endl;
  return 0;
}