//Fraction.h

#ifndef Fraction_H
#define Fraction_H

struct Fraction {
  int denom;
  int num;
  
  Fraction operator+(const Fraction&);  //Fraction add Fraction operator overload
  bool operator>(const Fraction&) const;  //compare two Fraction operator overload
  Fraction operator*(const int&);  //Fraction multiply int operator overload
  
};

Fraction operator*(const int&, const Fraction&); // stand alone function, int multiply fraction operator overload
Fraction operator*(const Fraction&, const Fraction&); ////Fraction multiply Fraction operator overload
#endif