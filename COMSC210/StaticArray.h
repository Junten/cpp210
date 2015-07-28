// StaticArray.h, by Junteng Tan (1489763)
// lab 5a, The "MyStaticArray" program
// Editor(s) used: xcode text Edit
// Compiler(s) used: xcode

#ifndef StaticArray_H
#define StaticArray_H

template<class DataType, int CAPACITY>
class Array{
public:
  Array();
  inline DataType& operator[](int);
  int getCapacity() const;
  int lsearch(const DataType&) const;

private:
  DataType data[CAPACITY];
  int index;
  DataType dummy;
};

template<class DataType, int CAPACITY>
Array<DataType, CAPACITY>::Array() {
}

template<class DataType, int CAPACITY>
inline DataType& Array<DataType, CAPACITY>::operator[](int index) {
  if (index < 0) 
	  return dummy;
  
  if (index >= CAPACITY)
    return dummy;
  
  return data[index];
}

template<class DataType, int CAPACITY>
int Array<DataType, CAPACITY>::getCapacity() const {
 return CAPACITY;
}

template<class DataType, int CAPACITY>
int Array<DataType, CAPACITY>::lsearch(const DataType& arg) const {
  for (int i = 0; i < CAPACITY; i++) {
    if(arg == data[i]) {
      return i;
    }
  }
  return -1;
}

#endif