// GameOfLifeMap.cpp
// lab 11c, The "GameOfLifeMap" program

#include <iostream>
using namespace std;

#include <cstdlib>
struct cell {
  int row;
  int col;
  
  bool operator==(const cell& c) const {
    return row == c.row && col == c.col;
  }
  bool operator<(const cell& c) const {
    return (1000000 * row + col) < (1000000 * c.row + c.col);
  }
  int HashCode() const {
    return 31 * row + col;
  }
};

#include <map>
map<cell, int> gird;
map<cell, int> newGrid;

const int MINROW = -25;
const int MAXROW = 25;
const int MINCOL = -35;
const int MAXCOL = 35;

int neighborCount(int row, int col) {
  cell temp;
  int count = 0;
  for (temp.row = row - 1; temp.row <= row + 1; temp.row++)
    for (temp.col = col - 1; temp.col <= col + 1; temp.col++)
      if (temp.row != row || temp.col != col)
        if (gird.find(temp) != gird.end())
          ++count;
  return count;
}

void initialize() {
  cout << "List the coordinates for living cells.\n"
       << "Terminate the list with a special pair -1 -1\n";
  
  cell temp;
  char buf[100];
  while (true) {
    cin >> buf; temp.row = atoi(buf);
    cin >> buf; temp.col = atoi(buf);
    if (temp.row == -1 && temp.col == -1)
      break;
    gird[temp] = 1;
  }
  cin.ignore();
}

void print() {
  cell temp;
  cout << "\nThe current Life configuration is:\n";
  for (temp.row = MINROW; temp.row <= MAXROW; temp.row++) {
    for (temp.col = MINCOL; temp.col <= MAXCOL; temp.col++)
      if (gird.find(temp) != gird.end())
        cout << '*';
      else
        cout << ' ';
    cout << endl;
  }
  cout << endl;
}

void update() {
  cell temp = {1};
  newGrid.clear();
  for (temp.row = MINROW; temp.row <= MAXROW; temp.row++)
    for (temp.col = MINCOL; temp.col <= MAXCOL; temp.col++)
      switch (neighborCount(temp.row, temp.col)) {
        case 2:
          if (gird.find(temp) != gird.end()) newGrid[temp] = 1;
          break;
        case 3:
          newGrid[temp] = 1;
          break;
      }

  gird = newGrid;
};

int main() {
  cout << "Lab 11c, The \"GameOfLifeMap\" Program " << endl
       << "File: " << __FILE__ << endl
       << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  initialize();
  print();

  for (int i = 1; gird.size(); i++) {
    cout << "Generation " << i << ". Press ENTER to continue, X-ENTER to quit...\n";
    if (cin.get() > 31) break;
    update();
    print();
  }
  return 0;
}