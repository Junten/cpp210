// GraphSearches.cpp
// Lab15a, The "GraphSearches" program

#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct Vertex {
  string name;
  bool isVisited;
  list<int> adjacentVertices;
};

queue<int> doBreadthFirstSearch(int iOriginVertex, vector<Vertex>& database) {
  queue<int> searchOrder; // return this queue of indices
  queue<int> verticesToConsider; // vertices to consider
  int vertexIndex;
  
  for (int i = 0; i < database.size(); i++) {
    database[i].isVisited = false;
  }
  
  database[iOriginVertex].isVisited = true;
  searchOrder.push(iOriginVertex);
  verticesToConsider.push(iOriginVertex);
  
  list<int>::iterator it;
  
  while(!verticesToConsider.empty()) {
    vertexIndex = verticesToConsider.front();
    verticesToConsider.pop();
    for (it = database[vertexIndex].adjacentVertices.begin();
         it != database[vertexIndex].adjacentVertices.end();
         it++) {
      if (database[*it].isVisited == false) {
        database[*it].isVisited = true;
        searchOrder.push(*it);
        verticesToConsider.push(*it);
      }
    }
  }
  return searchOrder;
}

queue<int> doDepthFirstSearch(int iOriginVertex, vector<Vertex>& vertices) {
  queue<int> searchOrder;
  stack<int> verticesToConsider; // vertices to consider
  int vertexIndex;
  
  for (int i = 0; i < vertices.size(); i++) {
    vertices[i].isVisited = false;
  }
  
  verticesToConsider.push(iOriginVertex);
  
  list<int>::reverse_iterator rit;
  
  while (!verticesToConsider.empty()) {
    vertexIndex = verticesToConsider.top();
    verticesToConsider.pop();
    if (!vertices[vertexIndex].isVisited) {
      vertices[vertexIndex].isVisited = true;
      searchOrder.push(vertexIndex);
    
      for (rit = vertices[vertexIndex].adjacentVertices.rbegin();
         rit != vertices[vertexIndex].adjacentVertices.rend();
         rit++) {
        if (!vertices[*rit].isVisited)
          verticesToConsider.push(*rit);
      }
    }
  }
  return searchOrder;
}

int main() {
  cout << "Lab15a, The \"GraphSearches\" program " << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
  
  ifstream fin;
  fin.open("cities.txt");
  if (!fin.good()) throw "I/O error";  

  // process the input file
  vector<Vertex> database;
  
  while (fin.good()) {   // EOF loop
    string fromCity, toCity;

    // read one edge
    getline(fin, fromCity);
    getline(fin, toCity);
    fin.ignore(1000, 10); // skip the line with distance
    fin.ignore(1000, 10); // skip the separator
    fromCity.erase(remove_if(fromCity.begin(), fromCity.end(), ::isspace), fromCity.end());
    toCity.erase(remove_if(toCity.begin(), toCity.end(), ::isspace), toCity.end());
    // add vertices for new cities included in the edge
    int iToVertex = -1, iFromVertex = -1, i;
    for (i = 0; i < database.size(); i++) {// seek "to" city
      if (database[i].name == fromCity)
        break;
    }
    if (i == database.size()) {         // not in database yet
      // store the vertex if it is new
      Vertex fromVertex;
      fromVertex.name = fromCity;
      database.push_back(fromVertex);
    }
    iFromVertex = i; 

    for (i = 0; i < database.size(); i++) // seek "from" city
      if (database[i].name == toCity)
        break;
    if (i == database.size()) {   // not in vector yet
      // store the vertex if it is new
      Vertex toVertex;
      toVertex.name = toCity;
      database.push_back(toVertex);
    }
    iToVertex = i; 

    // store bi-directional edges
    database[iFromVertex].adjacentVertices.push_back(iToVertex);
    database[iToVertex].adjacentVertices.push_back(iFromVertex);
  }
  fin.close();
  cout << "\nInput file processed\n\n";

  while (true) {
    // get the start city for the search
    string startCity;
    cout << "\nEnter the start city [blank to exit]: ";
    getline(cin, startCity);
    if (startCity.length() == 0) break;

    // find the start city
    int i;
    bool cityMatch = false;
    for (i = 0; i < database.size(); i++) {
      if (database[i].name == startCity) {
        cityMatch = true;
        break;
      }
    }
    
    if (!cityMatch) 
      cout << "\nThere is no matching city is found" << endl;
    else {
    // BFS result
      cout << "BFS";
      queue<int> q = doBreadthFirstSearch(i, database);
      while(!q.empty()) {
        cout  << '-'<< database[q.front()].name;
        q.pop();
      }
      cout << endl;

      cout << "DFS";
      q = doDepthFirstSearch(i, database);
      while(!q.empty()) {
        cout  << '-'<< database[q.front()].name;
        q.pop();
      }
      cout << endl;
    }
  }
  return 0;
}