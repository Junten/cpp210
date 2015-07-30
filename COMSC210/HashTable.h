// HashTable.h
// lab 11a, The "HashTable" program

#ifndef HashTable_h
#define HashTable_h

#include <list>
#include <algorithm>
using namespace std;

template<class DataType, int CAPACITY>
class HashTable {
public:
  HashTable();
  int size();
  bool remove(DataType&);
  bool retrieve(DataType&);
  bool replace(const DataType&, const DataType&);
  bool insert(const DataType&);
  void clear();
  
private:
  int currentIndex;
  int count;
  list<DataType> table[CAPACITY];

};

template<class DataType, int CAPACITY>
HashTable<DataType, CAPACITY >::HashTable() : count(0), currentIndex(-1) {
}

template<class DataType, int CAPACITY>
int HashTable<DataType, CAPACITY >::size() {
  return count;
}

template<class DataType, int CAPACITY>
bool HashTable<DataType, CAPACITY>::retrieve(DataType& parameter) {
  int i = parameter.HashCode() % CAPACITY;
  if(i < 0) i = i + CAPACITY;
  if(table[i].empty())
    return false;
  
  typename list<DataType>::const_iterator it;
  it = find(table[i].begin(), table[i].end(), parameter);
  if (it == table[i].end())
    return false;
  return true;
}

template<class DataType, int CAPACITY>
bool HashTable<DataType, CAPACITY>::replace(const DataType& parameter,const DataType& replacement) {
  int i = parameter.HashCode() % CAPACITY;
  if(i < 0) i += CAPACITY;
  
  if(table[i].empty())
    return false;
  
  typename list<DataType>::iterator it;
  it = find(table[i].begin(), table[i].end(), parameter);
  if(it == table[i].end())
    return false;
  
  *it = replacement;
  return  true;
}

template<class DataType, int CAPACITY>
bool HashTable<DataType, CAPACITY>::insert(const DataType& parameter) {
  int i = parameter.HashCode() % CAPACITY;
  if(i < 0) i += CAPACITY;
  if(table[i].empty()) {
    table[i].push_back(parameter);
    ++count;
    return true;
  }
  
  typename list<DataType>::iterator it;
  it = find(table[i].begin(), table[i].end(), parameter);
  if(it == table[i].end()) {
    table[i].push_back(parameter);
    ++count;
    return true;
  }
  return false;
}

template<class DataType, int CAPACITY>
bool HashTable<DataType, CAPACITY>::remove(DataType& parameter) {
  int i = parameter.HashCode() % CAPACITY;
  if (i < 0) i += CAPACITY;
  if (table[i].empty()) return false;
  
  typename list<DataType>::iterator it;
  it = find(table[i].begin(), table[i].end(), parameter);
  if (it == table[i].end())
    return false;
  
  table[i].erase(it);
  --count;
  return true;
}

template<class DataType, int CAPACITY>
void HashTable<DataType, CAPACITY>::clear() {
  count = 0;
  currentIndex  = -1;
  for (int i= 0; i < CAPACITY; i++) {
    if(!table[i].empty())
      table[i].clear();
  }
}

#endif