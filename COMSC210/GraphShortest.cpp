// GraphShortest.cpp
// Lab15b, The "GraphShortest" program

#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;

#include <cstdlib>

struct Vertex {
  string name;

  bool isVisited;
  list<pair<int, double> > adjacentVertices;
  int prev;
  double cost;
};

pair<stack<int>, double> getShortestRoute(int iStart, int iEnd, vector<Vertex>& database) {
  pair<stack<int>, double> result;
  list<pair<int, double> >::iterator it; // to iterate over adjacentVertices
  queue<int> vertexToConsider;
  int vertexIndex;
  
  for (int i = 0; i < database.size(); i++) {
    database[i].isVisited = false;
    database[i].prev = -1;
    database[i].cost = 0;
  }
  
  database[iStart].isVisited = true;
  vertexToConsider.push(iStart);
  
  while (!vertexToConsider.empty()) {
    vertexIndex = vertexToConsider.front();
    vertexToConsider.pop();
    
    for (it = database[vertexIndex].adjacentVertices.begin(); it != database[vertexIndex].adjacentVertices.end(); it++) {
      if (!database[it->first].isVisited) {
        database[it->first].isVisited= true;
        database[it->first].cost = 1 + database[vertexIndex].cost;
        database[it->first].prev = vertexIndex;
        vertexToConsider.push(it->first);
      }
      if (it->first == iEnd) {
        while (!vertexToConsider.empty())
          vertexToConsider.pop();
        break;
      }
    }
  }
  result.second = database[iEnd].cost;
  for (int vertex = iEnd; vertex >= 0; vertex = database[vertex].prev)
    result.first.push(vertex);
  return result;
}


int main() {
  cout << "Lab15b, The \"GraphShortest\" program " << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
  
  ifstream fin;
  bool cityFromMatch;
  bool cityToMatch;
  fin.open("cities.txt");
  if (!fin.good()) throw "I/O error";  

  // process the input file
  vector<Vertex> database;
  while (fin.good()) { // EOF loop
  
    string fromCity, toCity, cost;

    // read one edge
    getline(fin, fromCity);
    getline(fin, toCity);
    getline(fin, cost);
    fin.ignore(1000, 10); // skip the separator
    fromCity.erase(remove_if(fromCity.begin(), fromCity.end(), ::isspace), fromCity.end());
    toCity.erase(remove_if(toCity.begin(), toCity.end(), ::isspace), toCity.end());

    // add vertices for new cities included in the edge
    int iToVertex = -1, iFromVertex = -1, i;
    for (i = 0; i < database.size(); i++) // seek "to" city
      if (database[i].name == fromCity)
        break;
    if (i == database.size()) { // not in database yet
  
      // store the vertex if it is new
      Vertex fromVertex;
      fromVertex.name = fromCity;
      database.push_back(fromVertex);
    }
    iFromVertex = i; 

    for (i = 0; i < database.size(); i++) // seek "from" city
      if (database[i].name == toCity)
        break;
    if (i == database.size()) { // not in vector yet
    
      // store the vertex if it is new
      Vertex toVertex;
      toVertex.name = toCity;
      database.push_back(toVertex);
    }
    iToVertex = i; 

    // store bi-directional edges
    double edgeCost = atof(cost.c_str());
    database[iFromVertex].adjacentVertices.push_back(pair<int, double>(iToVertex, edgeCost));
    database[iToVertex].adjacentVertices.push_back(pair<int, double>(iFromVertex, edgeCost));
  }
  fin.close();
  cout << "\nInput file processed\n\n";

  while (true) {
    string fromCity, toCity;
    cout << "\nEnter the source city [blank to exit]: ";
    getline(cin, fromCity);
    if (fromCity.length() == 0) break;

    // find the from city
    int iFrom;
    cityFromMatch = false;
    for (iFrom = 0; iFrom < database.size(); iFrom++) {
       if (database[iFrom].name == fromCity) {
        cityFromMatch = true;
        break;
      }
    }
    if (!cityFromMatch)
      cout << "\nThere is no matching city is found" << endl;
    else {
      cout << "Enter the destination city [blank to exit]: ";
      getline(cin, toCity);
      if (toCity.length() == 0) break;
    // find the destination city
      int iTo;
      cityToMatch = false;
      for (iTo = 0; iTo < database.size(); iTo++) {
        if (database[iTo].name == toCity) {
          cityToMatch = true;
        break;
        }
      }
      if (!cityToMatch)
        cout << "\nThere is no matching city is found" << endl;
      else {
        cout << "Route: ";
        pair<stack<int>, double> result = getShortestRoute(iFrom, iTo, database);
        while (!result.first.empty()){cout << '-' << database[result.first.top()].name; result.first.pop();}
        cout << "\nTotal edges: " << result.second;
        cout << endl;
      }
    }
  }
  return 0;
}