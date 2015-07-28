// SortableArray,h, by Junteng Tan (1489763)
// lab 5a, The "MySortableArray" program
// Editor(s) used: xcode text Edit
// Compiler(s) used: xcode

#ifndef SortableArray_H
#define SortableArray_H

template<class DataType, int CAPACITY>
class Array{
public:
  Array();
  inline DataType& operator[](int);
  int getCapacity() const;
  int lsearch(const DataType&, int = -1) const;
  int bsearch(const DataType&, int, int = -1) const;
  void sort(int = -1);
  
private:
  DataType data[CAPACITY];
  int index;
  DataType dummy;
  void heapInsert(DataType, int, int);
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
int Array<DataType, CAPACITY>::lsearch(const DataType& arg, int size) const {
  for (int i = 0; i < size; i++) {
    if(arg == data[i]) {
      return i;
    }
  }
  return -1;
}

template<class DataType, int CAPACITY>
int Array<DataType, CAPACITY>::bsearch(const DataType& value, int start, int size) const {
  int m = (size + start) / 2;
  if (value == data[m])
    return m;
  else if (size == 0)
    return -1;
  else if (value < data[m]) {
    if (size == 0) return -1;
    else return bsearch(value, start, m - 1);
  } else {
    if (m == size) return -1;
    else return bsearch(value, m + 1, size);
  }
}

template<class DataType, int CAPACITY>
void Array<DataType, CAPACITY>::heapInsert(DataType insertThis, int s, int e) {
  int i = s;
  while (i <= e) {
    int iLeft = 2 * i + 1;
    int iRight = 2 * i + 2;
    if (iLeft > e) {
      data[i] = insertThis;
      break;
    } else if (iLeft == e) {
      if (insertThis < data[iLeft]) {
        data[i] = data[iLeft];
        data[iLeft] = insertThis;
      } else
        data[i] = insertThis;
      break;
    } else if (data[iLeft] < insertThis && data[iRight] < insertThis) {
      data[i] = insertThis;
      break;
    } else if (data[iLeft] < data[iRight]) {
      data[i] = data[iRight];
      i = iRight;
    } else {
      data[i] = data[iLeft];
      i = iLeft;
    }
  }
}

template<class DataType, int CAPACITY>
void Array<DataType, CAPACITY>::sort(int size) {
  int i;
  for (i = size / 2 - 1; i >= 0; i--) {
    DataType removed = data[i];
    heapInsert(removed, i, size - 1);
  }
  
  for (i = 0; i < size; i++) {
    int e = size - i - 1;
    DataType removed = data[e];
    data[e] = data[0];
    heapInsert(removed, 0, e - 1);
  }
}

#endif