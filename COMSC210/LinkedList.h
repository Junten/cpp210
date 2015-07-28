// LinkedList.h, by Junteng Tan (1489763)
// lab 10a, The "LinkedList" program
// Editor(s) used: xcode text Edit
// Compiler(s) used: xcode

#ifndef LinkedList_h
#define LinkedList_h

template<class DataType> 
class LinkedList{
private:
  template<class T>
  struct Node{
    T data;
    Node* next;
  };
  Node<DataType>* start;
  Node<DataType>* current;
  int currentIndex;
  int size;
  DataType dummy;
  
public:
  LinkedList();
  LinkedList(const LinkedList<DataType>&);
  ~LinkedList();
  LinkedList<DataType>& operator=(const LinkedList<DataType>&);
  void insert(const DataType&);
  bool first(DataType&);
  bool getNext(DataType&);
  bool find(const DataType&);
  bool retrieve(DataType&);
  bool replace(const DataType&);
  bool remove(DataType&);
  bool isEmpty() const;
  void makeEmpty();
  int length() const;
  DataType& operator[](const int&);
};

template<class DataType>
LinkedList<DataType>::LinkedList() : start(0), current(0), size(0), currentIndex(-1){
}

template<class DataType>
LinkedList<DataType>::~LinkedList() {
  Node<DataType>* p;
  while (start) {
    p = start->next;
    delete start;
    start = p;
  }
}

template<class DataType>
LinkedList<DataType>::LinkedList(const LinkedList<DataType>& a) : start(0), current(0), size(0), currentIndex(-1){
  Node<DataType>* p;
  Node<DataType>* end = 0;
  for (p = a.start; p; p = p->next) {
    Node<DataType>* node = new Node<DataType>;
    node->data = p->data;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
    if (p == a.current) {
      current = node;
    }
  }
}

template <class DataType>
LinkedList<DataType>& LinkedList<DataType>::operator=(const LinkedList<DataType>& a) {
  if (this != &a) {
    current = 0;
	currentIndex = -1;
    Node<DataType>* p;
    Node<DataType>* end = 0;
    while (start) {
      p = start->next;
      delete start;
      start = p;
    }
    for (p = a.start; p; p = p->next) {
      Node<DataType>* node = new Node<DataType>;
      node->data = p->data;
      node->next = 0;
      if (end) end->next = node;
      else start = node;
      end = node;
      if (p == a.current) current = node;
    }
  }
return *this;
}

template<class DataType>
void LinkedList<DataType>::insert(const DataType& parameter) {
  current = 0;
  currentIndex = -1;
  Node<DataType>* node = new Node<DataType>;
  node->data = parameter;
  node->next = start;
  start = node;
  ++size;
}

template<class DataType>
bool LinkedList<DataType>::first(DataType& parameter) {
  if (!start) return false;
  parameter = start->data;
  current = start;
  ++currentIndex;
  return true;
}

template<class DataType>
bool LinkedList<DataType>::getNext(DataType& paremeter) {
  if (!current) return false;
  current = current->next;
  if (!current) return false;
  paremeter = current->data;
  return true;
}

template<class DataType>
bool LinkedList<DataType>::find(const DataType& parameter) {
  DataType temp;
  if (first(temp)) do {
    if (parameter == temp) return true;
  } while (getNext(temp));
  return false;
}

template<class DataType>
bool LinkedList<DataType>::retrieve(DataType& parameter) {
  if (!find(parameter)) return false;
  parameter = current->data;
  return true;
}

template <class DataType>
bool LinkedList<DataType>::replace(const DataType& parameter) {
  if (!current) return false;
  current->data = parameter;
  return true;
}

template<class DataType>
bool LinkedList<DataType>::remove(DataType& parameter) {
  Node<DataType>* p;
  Node<DataType>* prev;
  for (prev = 0, p = start; p ; prev = p, p =  p->next) {
    if (p->data == parameter)
	  break;
  }
  if (!p) return false;
  if (prev)	prev->next = p->next;
  else start = p->next;
  if (p == current) current = current->next;
  parameter = p->data;
  delete p;
  --size;
  return true;
}

template<class DataType> 
bool LinkedList<DataType>::isEmpty() const{
  return start == 0;
}

template<class DataType>
void LinkedList<DataType>::makeEmpty() {
  while(start) {
    current = start->next;
	delete start;
	start = current;
  }
  size = 0;
}

template<class DataType>
int LinkedList<DataType>::length() const {
 return size;
}

template<class DataType>
DataType& LinkedList<DataType>::operator[](const int& index) {
 
  if (index < 0)
    return dummy;
  if (index >= length())
    return dummy;
  
  while (currentIndex + 1 != index) {
    if (current) {
      current = current->next;
      currentIndex++;
    } else {
      current = start;
      currentIndex = -1;
    }
  }
  return current->data;
}
#endif