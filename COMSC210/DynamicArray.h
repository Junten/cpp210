// DynamicArray.h, by Junteng Tan (1489763)
// lab 6c, The "MyDynamicArray" program
// Editor(s) used: xcode text Edit
// Compiler(s) used: xcode



#ifndef DynamicArray_H
#define DynamicArray_H

template<class Datatype>
class DynamicArray{
public:
  DynamicArray(int);
  ~DynamicArray();
  inline Datatype& operator[](int);
  void changeCapacity(int);
  int getCapacity() const;
  int lsearch(const Datatype&) const;
  
private:
  Datatype *array;
  int capacity;
  Datatype dummy;
};

template<class Datatype>
DynamicArray<Datatype>::DynamicArray(int arg) {
  capacity = arg;
  if (capacity <= 0) {
    array = 0;
  } else {
    array = new Datatype[capacity];
  }
}

template<class Datatype>
DynamicArray<Datatype>::~DynamicArray() {
  delete[] array;
}

template<class Datatype>
inline Datatype& DynamicArray<Datatype>::operator[](int index) {
  if (index < 0) 
	return dummy;
  
  if (index >= capacity)
    return dummy;
  
  return array[index];
}

template<class Datatype>
int DynamicArray<Datatype>::getCapacity() const {
 return capacity;
}

template<class Datatype>
int DynamicArray<Datatype>::lsearch(const Datatype& arg) const {
  for (int i = 0; i < capacity; i++) {
    if(arg == array[i]) {
      return i;
    }
  }
  return -1;
}

template<class Datatype>
void DynamicArray<Datatype>::changeCapacity(int newCapacity) {
  if (newCapacity <= 0) {
    delete [] array;
    array = 0;
    capacity = newCapacity;
  } else {
    Datatype* newArray = new Datatype[newCapacity];
    int limit = (newCapacity > capacity) ? capacity : newCapacity;
    
    for (int i = 0; i < limit; i++) {
      newArray[i] = array[i];
      }
    delete [] array;
    array = newArray;
    capacity = newCapacity;
  }
}

#endif
