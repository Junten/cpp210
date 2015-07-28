// Lab 2b, The "Rectangle" Program
// Programmer: Junteng Tan
// Editor(s) used: xcode text Edit
// Compiler(s) used: xcode

#include <iostream>
#include "Rectangle.h"
#include "Fraction.h"
#include <cassert>
using namespace std;

#include "Rectangle.h" //testing #ifdef

int main() {
  cout << "Lab 2b, The \"Rectangle\" Program \n";
  cout << "Programmer: Junteng Tan\n";
  cout << "ditor(s) used: xcode text Edit\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
  
  Rectangle<float> rectangleFloat;
  float parimeterFloat;
  float areaFloat;
  float lengthFloat;
  float widthFloat;
  Rectangle<Fraction> rectangleFraction;
  Fraction lengthFraction;
  Fraction widthFraction;
  Fraction parimeterFraction;
  Fraction areaFraction;
  
  lengthFloat = 5.8f;
  widthFloat  = 2.5f;
  rectangleFloat.setLength(lengthFloat);
  rectangleFloat.setWidth(widthFloat);
  
  parimeterFloat = rectangleFloat.getParimeter();
  areaFloat = rectangleFloat.getArea();
  cout << "\nThe length of the rectangle in float is 5.8"
       << "\nThe width of the rectangle in float is 2.5" << endl;
  cout << "The parimeter of the rectangle in float: \n"
	  << "The expected value is 16.6\n"
	  << "The actual value is: "
       << parimeterFloat << endl;
	  assert(16.6f == parimeterFloat);

  cout << "The area of the rectangle in float: \n"
	  << "The expected value is 14.5\n"
	  << "The actual value is: "
       << areaFloat << endl;
       assert(14.5 == areaFloat);
  
  cout << "Checking whether the length is greater than width, \n"
       << "The expected value is: true\n"
	  << "The actual value is: "
       << boolalpha << (lengthFloat > widthFloat) << endl;
       assert(true == (lengthFloat > widthFloat));

  //object copy testing
  Rectangle<float> rectangleFloatcopy1 = rectangleFloat;
  
  parimeterFloat = rectangleFloat.getParimeter();
  areaFloat = rectangleFloat.getArea();
  cout << "" << endl;
  cout << "\nThe length of the rectangle in float is 5.8"
       << "\nThe width of the rectangle in float is 2.5" << endl;
  cout << "The parimeter of the rectangle in float: \n"
	  << "The expected value is 16.6\n"
	  << "The actual value is: "
       << parimeterFloat << endl;
	  assert(16.6f == parimeterFloat);

  cout << "The area of the rectangle in float: \n"
	  << "The expected value is 14.5\n"
	  << "The actual value is: "
       << areaFloat << endl;
       assert(14.5 == areaFloat);
  
  cout << "Checking whether the length is greater than width, \n"
       << "The expected value is: true\n"
	  << "The actual value is: "
       << boolalpha << (lengthFloat > widthFloat) << endl;
       assert(true == (lengthFloat > widthFloat));

  //object assignment testing
  Rectangle<float> rectangleFloatcopy2;
  rectangleFloatcopy2 = rectangleFloat;
  parimeterFloat = rectangleFloat.getParimeter();
  areaFloat = rectangleFloat.getArea();
  cout << "Object assignmnet testing for float type" << endl;
  cout << "\nThe length of the rectangle in float is 5.8"
       << "\nThe width of the rectangle in float is 2.5" << endl;
  cout << "The parimeter of the rectangle in float: \n"
	  << "The expected value is 16.6\n"
	  << "The actual value is: "
       << parimeterFloat << endl;
	  assert(16.6f == parimeterFloat);

  cout << "The area of the rectangle in float: \n"
	  << "The expected value is 14.5\n"
	  << "The actual value is: "
       << areaFloat << endl;
       assert(14.5 == areaFloat);
  
  cout << "Checking whether the length is greater than width, \n"
       << "The expected value is: true\n"
	  << "The actual value is: "
       << boolalpha << (lengthFloat > widthFloat) << endl;
       assert(true == (lengthFloat > widthFloat));

  lengthFraction.num = 5;
  lengthFraction.denom = 7;
  widthFraction.num = 3;
  widthFraction.denom = 11;
  
  rectangleFraction.setWidth(widthFraction);
  rectangleFraction.setLength(lengthFraction);
  
  parimeterFraction = rectangleFraction.getParimeter();
  areaFraction = rectangleFraction.getArea();
  
  cout << "\nThe length of the rectangle in fraction is 5/7"
       << "\nThe width of the rectangle in fraction is 3/11";

  cout << "The parimeter of the rectangle in fraction: \n"
       << "The expected value is: 152/77\n"
	  << "The actual value is: "
       << parimeterFraction.num << "/" << parimeterFraction.denom;
       assert(152 == parimeterFraction.num);
	  assert(77 == parimeterFraction.denom);

  cout << "\nThe area of the rectangle in fraction: \n"
       << "The expected value is: 15/77\n"
	  << "The actual value is: "
       << areaFraction.num << "/" << areaFraction.denom << endl;
       assert(15 == areaFraction.num);
	  assert(77 == areaFraction.denom);
  
  cout << "Checking whether the length is greater than width: \n"
       << "The expected value is: ture\n"
	  << "The actual value is: "
       << (lengthFraction > widthFraction) << endl;
       assert(true == (lengthFraction > widthFraction));

  //object copy testing
  Rectangle<Fraction> rectangleFractioncopy1 = rectangleFraction;
  parimeterFraction = rectangleFractioncopy1.getParimeter();
  areaFraction = rectangleFractioncopy1.getArea();
  
  cout << "\nObject copy testing"
       << "\nThe length of the rectangle in float is 5/7"
       << "\nThe width of the rectangle in float is 3/11" << endl;

  cout << "\nThe parimeter of the rectangle in fraction is: "
       << parimeterFraction.num << "/" << parimeterFraction.denom
       << "\nThe area of the rectangle in fraction is: "
       << areaFraction.num << "/" << areaFraction.denom << endl;

  //object assignment testing
  Rectangle<Fraction> rectangleFractioncopy2;
  rectangleFractioncopy2 = rectangleFraction;
  parimeterFraction = rectangleFractioncopy2.getParimeter();
  areaFraction = rectangleFractioncopy2.getArea();
  
  cout << "\nObject assignment testing"
       << "\nThe length of the rectangle in float is 5/7"
       << "\nThe width of the rectangle in float is 3/11" << endl;

  cout << "\nThe parimeter of the rectangle in fraction is: "
       << parimeterFraction.num << "/" << parimeterFraction.denom
       << "\nThe area of the rectangle in fraction is: "
       << areaFraction.num << "/" << areaFraction.denom << endl;

  return 0;
}
