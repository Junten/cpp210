// Checkbook.h, by Junteng Tan (1489763)
// lab 4b, The "Checkbook" program
// Editor(s) used: xcode text Edit
// Compiler(s) used: xcode

#ifndef Checkbook_H
#define Checkbook_H

template<class DataType>
class Checkbook {
public:
  Checkbook();
  void setBalance(float);
  bool writeCheck(const DataType&); // returns false if amount is greater than balance, otherwise returns true
	
  void deposit(float);
  float getBalance(void) const;
  int getLastIndex() const;
  DataType* getChecks(void) const;

private:
  DataType *data;
  int capacity;
  void doubleArray(void);
  int lastIndex = 0;
  float balance;
};

template<class DataType>
Checkbook<DataType>::Checkbook() {
  capacity = 2;
  data = new DataType[2];
}

template <class DataType>
void Checkbook<DataType>::setBalance(float amount) {
  balance = amount;
}

template<class DataType>
bool Checkbook<DataType>::writeCheck(const DataType& amount) {
  if (amount > balance) {
     return false;
	}
  balance -= amount;
  data[lastIndex] = amount;
  lastIndex++;
  if (lastIndex == (capacity)) {
    doubleArray();
  }
	
  return true;
}

template<class DataType>
void Checkbook<DataType>::deposit(float amount) {
  balance += amount;
}

template<class DataTpye>
float Checkbook<DataTpye>::getBalance() const {
  return balance;
}

template<class DataType>
void Checkbook<DataType>::doubleArray() {
  DataType *tempPtr = new DataType[capacity * 2];
	
	for (int i = 0; i < capacity; i++) {
    tempPtr[i] = data[i];
	}
	
  delete[] data;
  data = tempPtr;
  capacity *= 2;
}

template<class DataType>
int Checkbook<DataType>::getLastIndex() const {
  return lastIndex;
}
template<class DataType>
DataType* Checkbook<DataType>::getChecks() const {
  DataType *result = new DataType[lastIndex];
	
  for (int i = 0; i < (lastIndex); i++) {
    result[i] = data[i];
	}
	
  return result;
}
#endif