// Queue.h
// lab 8b, The "QueueDriver" program

#ifndef Node_H
#define Node_H
template <class DataType>
struct Node{
  Node* next;
  DataType data;
};
#endif

#ifndef QueueDriver_H
#define QueueDriver_H

template <class DataType>
class Queue {
public:
  Queue();
  bool isEmpty() const;
  void push (const DataType&);
  bool peek(DataType&) const;
  bool pop(DataType&);
  void makeEmpty();
  
private:
  Node<DataType>* front;
  Node<DataType>* end;
};

template <class DataType>
Queue<DataType>::Queue():front(0), end(0) {
}

template <class DataType>
bool Queue<DataType>::isEmpty() const {
  return 0 == front;
}

template <class DataType>
void Queue<DataType>::push (const DataType& arg) {
  Node<DataType>* node = new Node<DataType>;
  node->data = arg;
  node->next = 0;
  if (end)
    end->next = node;
  else
    front = node;
  end = node;
}

template <class DataType>
bool Queue<DataType>::peek(DataType& arg) const {
  if (0 == front)
    return false;
  arg = front->data;
  return  true;
}

template <class DataType>
bool Queue<DataType>::pop(DataType& arg){
  if (0 == front)
    return false;
  arg = front->data;
  Node<DataType>* p = front->next;
  delete front;
  front = p;
  if (front == 0)
    end = 0;
  return true;
}

template <class DataType>
void Queue<DataType>::makeEmpty() {
  end = 0;
  Node<DataType>* p;
  while (front) {
    p = front->next;
    delete  front;
    front = p;
  }  
}
#endif