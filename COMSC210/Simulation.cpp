// Simulation.cpp, by Junteng Tan (1489763)
// Lab13, The "DSimulation" program
// Editor(s) used: xcode text Edit
// Compiler(s) used: xcode

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <stack>

using namespace std;

struct customer {
  int arrival_Time;  //time that the cusomer arrives to be placed in the wait queue
  int service_Time;  //time that the custmoers service starts, by arriving when a server is idle or moveing out of the queue
  int completion_Time;  //time that the custmoer's service ends
  int customer_Count;
  char id_Tag;
};

struct serviceEvent {
  int clock_Time;
  int server_Number;
  bool operator<(const serviceEvent& se) const {
    return  se.clock_Time < clock_Time;
  }
};

int newArrival(double arrivalRate) {
  int requests = 0;
  double probOfnRequests = exp(-arrivalRate);
  for (float randomValue = (double)rand() / RAND_MAX;
      (randomValue -= probOfnRequests) > 0.0;
      probOfnRequests *= arrivalRate / (double)++requests);
  return requests;
}

int main() {
  cout << "Term Project, The \"Simulation\" program " << endl
       << "Programmer: Junteng Tan" << endl
       << "Editor(s) used: xcode text Edit" << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl;

  string line;
  ifstream fin;
  queue<customer> customerQueue; //wait queue
  priority_queue<serviceEvent> eventQueue; //service events that get scheduled each time service begins
  stack<customer> customerStack; //customer objects after service is completed
  customer* serverArray; //customer objects to represent the customers being served by each server
  bool* serverBool;
  string inputArray[6];
  int current_ClcokTime;
  int avg_Time;
  int number_Arrival;
  int turn_Away = 0;
  
  fin.open("simulation.txt");
  if (!fin.good())
	cout << "\nUnable to open the file!!!" << endl;

  for(int i = 0; i < 6; i++) {
    getline(fin, line);
	  inputArray[i] = line;
  }
  
  const int serverNumber = atoi(inputArray[0].c_str());
  const float arrivalRate = atof(inputArray[1].c_str());
  const int maxLengthQueue = atoi(inputArray[2].c_str());
  const int minTimeInterval = atoi(inputArray[3].c_str());
  const int maxTimeInterval = atoi(inputArray[4].c_str());
  const int time_Stop = atoi(inputArray[5].c_str());
  
  serverArray = new customer[serverNumber];
  serverBool = new bool[serverNumber];
  
  for (int time = 0;; time++) {
    
    while (!eventQueue.empty() && eventQueue.top().clock_Time == time) {
      serviceEvent server = eventQueue.top();
	    eventQueue.pop();
      serverArray[server.server_Number].completion_Time = time;
      customer completeCustomer;
      completeCustomer = serverArray[server.server_Number];
      customerStack.push(completeCustomer);
      serverBool[server.server_Number] = false;
    }
    
    if (time < time_Stop) {
      number_Arrival = newArrival(arrivalRate);
      for (int i = 0; i < number_Arrival; i++) {
        if (customerQueue.size() == maxLengthQueue)
          turn_Away++;
        else {
          customer newCustomer;
          newCustomer.arrival_Time = time;
          customerQueue.push(newCustomer);
        }
      }
    }
    
    for (int i = 0; i < serverNumber; i++) {
      if (!serverBool[i] && !customerQueue.empty()) {
        serverArray[i] = customerQueue.front();
        customerQueue.pop();
        serverArray[i].service_Time = current_ClcokTime;
        int randomNumber = rand() % maxTimeInterval + minTimeInterval;
        serviceEvent newServiceEvent;
        newServiceEvent.clock_Time = current_ClcokTime + randomNumber;
        eventQueue.push(newServiceEvent);
      }
    }
    
    cout << "\nTime: " << time
	       << "\n-----------------------------"
         << "\nline  now serving  wait queue"
         << "\n----  -----------  ----------";
    for (int i = 0; i < serverNumber; i++) {
      cout << "\n" << i << "     " << serverArray[i].id_Tag << "     ";
      queue<customer> waitQueue = customerQueue;
      if (i == 0) {
        while (!waitQueue.empty()) {
          cout << waitQueue.front().id_Tag;
          waitQueue.pop();
        }
      }
    }
    
    for (auto copy = customerStack; !copy.empty(); copy.pop()) {
      avg_Time += copy.top().completion_Time;
      avg_Time -= copy.top().arrival_Time;
    }
    avg_Time /= customerStack.size();
    cout << "\n-----------------------------"
         << "\nAvg time:" << avg_Time << ". Turned away per minute: "
         << "\nPress ENTER to continue, X-ENTER to exit... " << endl;
    if (cin.get() > 31) break;
  }
  return 0;
}
