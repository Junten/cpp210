//Fraction.cpp, by Junteng Tan (1489763)

#include "Fraction.h"

Fraction Fraction::operator+(const Fraction& arg) {
  Fraction result;
  result.num = num * arg.denom + denom * arg.num;
  result.denom = denom * arg.denom;

  return result;
}

bool Fraction::operator>(const Fraction& arg) const {
  return (float) num / denom > (float) arg.num / arg.denom;
}

Fraction Fraction::operator*(const int& arg) {
  Fraction result;
  result.num = num * arg;
  result.denom = denom;
  return result;
}

Fraction operator*(const int& arg1, const Fraction& arg2) {
  Fraction result;
  result.num = arg1 * arg2.num;
  result.denom = arg2.denom;

  return result;
}

Fraction operator*(const Fraction& fr1, const Fraction& fr2) {
  Fraction result;
  result.num = fr1.num * fr2.num;
  result.denom = fr1.denom * fr2.denom;
  
  return  result;
}