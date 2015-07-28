// Stack.h, by Junteng Tan (1489763)
// lab 8a, The "StackDriver" program
// Editor(s) used: xcode text Edit
// Compiler(s) used: xcode

#ifndef Stack_h
#define Stack_h

template <class DataType>
class Stack{
public:
  Stack();
  bool isEmpty() const;
  void makeEmpty();
  void push(const DataType&);
  bool peek(DataType&);
  bool pop(DataType&);
  Stack<DataType>& operator=(const Stack<DataType>&);
  
private:
  DataType* data;
  int capacity;
  int top;
};

template <class DataType>
Stack<DataType>::Stack() {
  capacity = 2;
  data = new DataType[2];
  top = -1;
}

template <class DataType>
bool Stack<DataType>::isEmpty() const {
  return top == -1;
}


template <class DataType>
void Stack<DataType>::makeEmpty() {
  top = -1;
}

template <class DataType>
void Stack<DataType>::push(const DataType& arg) {
  if (++top == capacity) {
    DataType* temPtr = new DataType[capacity * 2];
    for (int i = 0; i < capacity; i++) {
      temPtr[i] = data[i];
    }
    delete[] data;
    data = temPtr;
    capacity *= 2;
  }
  data[top] = arg;
}

template <class DataType>
bool Stack<DataType>::peek(DataType& arg) {
  if (-1 == top)
    return false;
  arg = data[top];
  return true;
}

template <class DataType>
bool Stack<DataType>::pop(DataType& arg) {
  if (top == -1)
    return false;
  arg = data[top--];
  int newSize = capacity / 2;
  if(top > 2 && top < capacity / 4) {
    DataType* temPtr = new DataType[newSize];
    for (int i = 0; i < newSize; i++) {
      temPtr[i] = data[i];
    }
    delete[] data;
    data = temPtr;
    capacity /= 2;
  }
  return true;
}

template <class DataType>
Stack<DataType>& Stack<DataType>::operator=(const Stack<DataType>& a) {
  if (this != &a) {
    delete [] data;
    data = 0;
    capacity = a.capacity;
    if (capacity > 0)
      data = new DataType[capacity];
    for (int i = 0; i < capacity; i++)
      data[i] = a.data[i];
      top = a.top;
  }
  return *this;
}
#endif
