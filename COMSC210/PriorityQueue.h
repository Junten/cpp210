// PriorityQueue.h by Junteng Tan (1489763)
// lab 12a, The "PriorityQueue" program
// Editor(s) used: xcode text Edit
// Compiler(s) used: xcode


#ifndef PriorityQueue_H
#define PriorityQueue_H

template<class DataType>
class PriorityQueue {

public:
  PriorityQueue();
  int getSize() const;
  void enqueue(const DataType&);
  DataType dequeue();

private:
  int capacity;
  DataType* data;
  int size;
  int currentIndex;
};

template<class DataType>
PriorityQueue<DataType>::PriorityQueue() : size(0), capacity(2), data(new DataType[capacity]){
}

template<class DataType>
int PriorityQueue<DataType>::getSize() const {
  return size;
}

template<class DataType>
void PriorityQueue<DataType>::enqueue(const DataType& parameter) {
  currentIndex = size;
  if (currentIndex >= capacity) {
    DataType* tempPtr = new DataType[capacity * 2];
    for (int i = 0; i < capacity; i++) {
      tempPtr[i] = data[i];
    }
    delete[] data;
    data = tempPtr;
    capacity *= 2;
  }
  data[currentIndex] = parameter;
  int parentIndex;
  while (currentIndex > 0) {
    parentIndex = (currentIndex + 1) / 2 - 1;
    if (parentIndex < 0) break;
    if (data[parentIndex] >= data[currentIndex]) break;
    DataType temp = data[parentIndex];
    data[parentIndex] = data[currentIndex];
    data[currentIndex] = temp;
    currentIndex = parentIndex;
  }
  ++size;
}

template<class DataType>
DataType PriorityQueue<DataType>::dequeue() {
  DataType parameter = data[0];
  currentIndex = 0;
  int indexLeft;
  int indexRight;
  while (currentIndex <= size) {
    indexLeft = 2 * currentIndex + 1;
    indexRight = 2 * currentIndex + 2;
    if (indexLeft >= size) break;
    if (indexLeft == size - 1 || data[indexLeft] >= data[indexRight]) {
      data[currentIndex] = data[indexLeft];
      currentIndex = indexLeft;
    } else {
      data[currentIndex] = data[indexRight];
      currentIndex = indexRight;
    }
  }
  --size;
  
  if (size >= 2 && size < capacity / 4) {
    DataType* tempPtr = new DataType[capacity / 2];
    for (int i; i < size; i++) {
      tempPtr[i] = data[i];
    }
    delete[] data;
    data = tempPtr;
    capacity /= 2;
  }

  while (currentIndex > 0) {
    int parentIndex = (currentIndex + 1) / 2 - 1;
    if (parentIndex < 0) break;
    if (data[parentIndex] >= data[currentIndex]) break;
    DataType temp = data[parentIndex];
    data[parentIndex] = data[currentIndex];
    data[currentIndex] = temp;
    currentIndex = parentIndex;
  }
  return parameter;
}
#endif