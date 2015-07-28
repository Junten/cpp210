//RoadDriver.cpp, by Junteng Tan (1489763)
//Lab1a, The "Road" Program
// Editor(s) used: xcode text Edit
// Compiler(s) used: xcode

#include <iostream>
#include <cassert>
using namespace std;

#include "Road.h"
#include "Road.h"  //testing ifndef

int main() {
  cout << "Lab 1a, The \"Road\" Program \n";
  cout << "Programmer: Junteng Tan\n";
  cout << "Editor(s) used: xcode text Edit\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Road road;
	
  road.setWidth(30); // width in feet
  road.setLength(10); // length miles
  
  cout << "Testing the getLength function. Expected result in is 10\n"
       << "Actual result is " << road.getLength() << " miles." << endl;
       assert(10 == road.getLength());
  
  cout << "Testing the getwidth function. Expected result in is 30\n"
       << "Actual result is: " << road.getWidth() << " feet." << endl;
       assert(30 == road.getWidth());
  
  cout << "The thickness of the road is 12 inches.\n"
       << "Testing the asphalt function is 1584000 cobic feet.\n"
       << "Actual result is: " << road.asphalt(12) << "cobic feet.\n" << endl;
       assert(1584000 == road.asphalt(12));

	//object copy testing
  Road copy1 = road;
  
  cout << "Testing the getLength function. Expected result in is 10\n"
       << "Actual result is " << road.getLength() << " miles." << endl;
       assert(10 == copy1.getLength());
  
  cout << "Testing the getwidth function. Expected result in is 30\n"
       << "Actual result is: " << road.getWidth() << " feet." << endl;
       assert(30 == copy1.getWidth());
  
  cout << "The thickness of the road is 12 inches.\n"
       << "Testing the asphalt function is 1584000 cobic feet.\n"
       << "Actual result is: " << road.asphalt(12)  << "cobic feet.\n" << endl;
       assert(1584000 == copy1.asphalt(12));

	//object assignment testing
  Road copy2;
  copy2 = road;
  
  cout << "Testing the getLength function. Expected result in is 10\n"
       << "Actual result is " << copy2.getLength() << " miles." << endl;
       assert(10 == road.getLength());
  
  cout << "Testing the getwidth function. Expected result in is 30\n"
       << "Actual result is: " << copy2.getWidth() << " feet." << endl;
       assert(30 == copy2.getWidth());
  
  cout << "The thickness of the road is 12 inches.\n"
       << "Testing the asphalt function is 1584000 cobic feet.\n"
       << "Actual result is: " << road.asphalt(12)  << "cobic feet.\n" << endl;
       assert(1584000 == copy2.asphalt(12));

  return 0;
}

