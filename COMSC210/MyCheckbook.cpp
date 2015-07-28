// MyCheckbook.cpp, by Junteng Tan (1489763)
// lab 4b, The "Checkbook" program
// Editor(s) used: xcode text Edit
// Compiler(s) used: xcode

#include <iostream>
#include "Checkbook.h"
using namespace std;

int main() {
  cout << "Lab 4b, The \"Checkbook\" Program \n";
  cout << "Programmer: Junteng Tan\n";
  cout << "Editor(s) used: xcode text Edit\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
	
  int option;
  float amount;
  int size;
  float* temp;
	 
  cout << "\nEnter the initial balance: $";
  cin >> amount;
  Checkbook<float> check;
  check.setBalance(amount);
  bool checkAccepted = false;
	
  do {
    cout << "\n***********************************************"
         << "\n*                   Menu                      *"
         << "\n* 1. Make Deposit                             *"
         << "\n* 2. Show Balance                             *"
         << "\n* 3. Write Check                              *"
         << "\n* 4. Quit                                     *"
         << "\n* 5. Output Check History                     *"
         << "\n***********************************************";
		cout << "\nEnter the selection :  ";
    cin >> option;
	
    switch (option) {
      case 1:
        cout << "\nMake Deposit -- " << endl
             << "\tPlase Enter the amount: \n  $";
			  cin >> amount;
        check.deposit(amount);
        cout << "\tDeposit accepted." << endl;
        break;
      case 2:
        cout << "\nShow Balance -- " <<endl;
        amount = check.getBalance( );
        cout << "\tYour balance is: $" << amount << endl;
        break;
      case 3:
        cout << "\nWrite Check: " << endl;
        cout << "\tEnter check amount: $";
        cin >> amount;
        if (check.writeCheck(amount)) {
          cout << "\tCheck accepted." << endl;
          checkAccepted = true;
        } else {
          cout << "\tYour balance is not high enough for the check." << endl;
        }
          break;
			case 4:
        cout << "\n  Thank you." << endl;
        break;
      case 5: {
        cout << "\nOutput Check History: " << endl;
        size = check.getLastIndex();
        if (size == 0) {
          cout << "\tYou didn't write any check yet." << endl;
        } else {
          cout << "\tChecks that you worte from beginning to the end are: " << endl;
          temp = check.getChecks();
          for (int i = 0; i < size; i++) {
            cout << "\t$" << temp[i] << endl;
          }
          delete[] temp;
        }
			
        break;
      }
      default:
        cout <<"\nWrong Option. Please chosing your option from 1 to 5." <<endl;
    }
  } while (option != 4);
  
  return 0;
}

