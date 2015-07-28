//TimeDriver.cpp, by Junteng Tan (1489763)
//lab1b, The "Time" program
// Editor(s) used: xcode text Edit
// Compiler(s) used: xcode

#include <iostream>
#include "Time.h"
#include <cassert>
using namespace std;

#include "Time.h"  //testing class ifndef

int main() {
  cout << "Lab 1b, The \"Time\" Program \n";
  cout << "Programmer: Junteng Tan\n";
  cout << "ditor(s) used: xcode text Edit\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Time time;

  time.setHours(1);
  time.setMinutes(59);
  time.setSeconds(60);

  cout << "Testing the functiontimeInSeconds(). The expect result is 7200.\n"
       << "The actual result is " << time.timeInSeconds() << endl;
       assert(7200 == time.timeInSeconds());

  cout << "Testing the functiontimeInMinutes(). The expect result is 120.\n"
       << "The actual result is " << time.timeInMinutes() << endl;
       assert(120 == time.timeInMinutes());
  
  cout << "Testing the functiontimeInHours(). The expect result is 2.\n"
       << "The actual result is " << time.timeInHours() << endl;
       assert(2 == time.timeInHours());
       
   //object copy testing
  Time timeCopy1 = time;
  cout << "Testing the functiontimeInSeconds(). The expect result is 7200.\n"
       << "The actual result is " << timeCopy1.timeInSeconds() << endl;
       assert(7200 == timeCopy1.timeInSeconds());

  cout << "Testing the functiontimeInMinutes(). The expect result is 120.\n"
       << "The actual result is " << timeCopy1.timeInMinutes() << endl;
       assert(120 == timeCopy1.timeInMinutes());
  
  cout << "Testing the functiontimeInHours(). The expect result is 2.\n"
       << "The actual result is " << timeCopy1.timeInHours() << endl;
       assert(2 == timeCopy1.timeInHours());
  
  //object assignment testing
  Time timeCopy2;
  timeCopy2 = time;
  cout << "Testing the functiontimeInSeconds(). The expect result is 7200.\n"
       << "The actual result is " << timeCopy1.timeInSeconds() << endl;
       assert(7200 == timeCopy1.timeInSeconds());

  cout << "Testing the functiontimeInMinutes(). The expect result is 120.\n"
       << "The actual result is " << timeCopy1.timeInMinutes() << endl;
       assert(120 == timeCopy1.timeInMinutes());
  
  cout << "Testing the functiontimeInHours(). The expect result is 2.\n"
       << "The actual result is " << timeCopy1.timeInHours() << endl;
       assert(2 == timeCopy1.timeInHours());


  return 0;
}