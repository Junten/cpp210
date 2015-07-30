// ServerGroupDriver.cpp
// lab 4a, The "ServerGroup" program

#include <iostream>
#include <cassert>
using namespace std;

#include "ServerGroup.h"
#include "ServerGroup.h"  //testing ifndef

int main() {
  cout << "Lab 4a, The \"ServerGroup\" Program \n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
   
  ServerGroup newServers = ServerGroup(6); // testing the constructor ServerGroup(const int&)
	
  cout << "Testing member function spServerFree(). Expected Value is true" << endl
       << "The actual value is "
       << boolalpha << newServers.spServerFree() << endl;
       assert(true == newServers.spServerFree());
		
  cout << "\nTesting member function serverFree(). Expected Value is true" << endl
       << "The actual value is "
       << boolalpha << newServers.serverFree() << endl;
       assert(true == newServers.serverFree());
		
  cout << "\nTesting member function useServer(const int&)." << endl;
       newServers.useServer(5);
		
  cout << "\nTesting member function usespServer(const int&)" << endl;
       newServers.usespServer(7);
		
  cout << "\nTesting member function decServers()" << endl;
       newServers.decServers();
		
  const ServerGroup newServers1 = ServerGroup(8);
	
  cout << "Testing member function spServerFree() for const getter function. Expected Value is true" << endl
       << "The actual value is "
       << boolalpha << newServers1.spServerFree() << endl;
       assert(true == newServers1.spServerFree());

  return 0;
}