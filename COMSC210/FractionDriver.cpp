// Lab 2b, The "Fracton" Program

#include <iostream>
#include <cassert>
#include "Fraction.h"
using namespace std;

#include "Fraction.h" //testing ifdef

int main() {
    cout << "Lab 2c, The \"Frection\" Program \n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    
    Fraction fr1;
    Fraction fr2;
    int number;
    Fraction result;
    
    fr1.num = 1;
    fr1.denom = 2;
    fr2.num = 3;
    fr2.denom = 5;
    number = 7;
    
    cout << "Fraction 1:\n"
         << "The expected value is 1/2.\n"
         << "The actual value is "
         << fr1.num << "/" << fr1.denom << endl;
    
    Fraction fr1Copy1 = fr1;
    cout << "\nObject Copy testing\n"
         << "Fraction1 Copy1: \n"
         << "The expected value is 1/2.\n"
         << "The actual value is "
         << fr1Copy1.num << "/" << fr1Copy1.denom << endl;
    
    Fraction fr1Copy2;
    fr1Copy2 = fr1;
    cout << "\nObject assignmnet testing\n"
         << "Fraction1 Copy2: \n"
         << "The expected value is 1/2.\n"
         << "The actual value is "
         << fr1Copy2.num << "/" << fr1Copy2.denom << endl;
    
    
    result = fr1 + fr2;
    cout << "\nfraction1(1/2) + fraction2(3/5) = \n"
         << "The expected value is: 11/10\n"
         << "The acutal value is: "
         << result.num << "/" << result.denom << endl;
         assert(11 == result.num);
         assert(10 == result.denom);
    
    result = fr1 * fr2;
    cout << "\nfraction1(1/2) * fraction2(3/5) = \n"
         << "The expected value is: 3/10\n"
         << "The acutal value is: "
         << result.num << "/" << result.denom << endl;
         assert(3 == result.num);
         assert(10 == result.denom);
    
    cout << "\nComparing fraction1(1/2) and fraction2(3/5),"
         << "\nFraction2 is greater than Fraction1(True or False): \n"
         << "The expected result is True.\n"
         << "The acutal result is: "
         << boolalpha << (fr2 > fr1) << endl;
         assert(true == (fr2 > fr1));
    
    cout << "\nComparing fraction2(1/2) and fraction1(3/5),"
         << "\nFraction1 is greater than Fraction2(True or False): \n"
         << "The expected result is False.\n"
         << "The acutal result is: "
         << boolalpha << (fr1 > fr2) << endl;
         assert(false == (fr1 > fr2));
    
    result = fr1 * number;
    cout << "\nfraction1(1/2) * interger(7) = \n"
         << "The expected value is: 7/2\n"
         << "The acutal value is: "
         << result.num << "/" << result.denom << endl;
         assert(7 == result.num);
         assert(2 == result.denom);
    
    result = number * fr2;
    cout << "\ninterger(7) * fraction2(3/5) = \n"
         << "The expected value is: 21/5\n"
         << "The acutal value is: "
         << result.num << "/" << result.denom << endl;
         assert(21 == result.num);
         assert(5 == result.denom);
    
    return 0;
}