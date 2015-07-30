// Lab 2b, The "Rectangle" Program

#ifndef __Rectangle__H
#define __Rectangle__H

template <class T>
class Rectangle {
public:
  
  void setLength(T);
  void setWidth(T);
  bool checkSize(void);
  T getParimeter(void);
  T getArea(void);
  
private:
  T length;
  T width;
};

template  <class T>
void Rectangle<T>:: setLength(T arg) {
  length = arg;
}
  
template  <class T>
void Rectangle<T>::setWidth(T arg) {
  width = arg;
}

template  <class T>
bool Rectangle<T>::checkSize() {
  if (length > width) {
  return true;
  } else {
  return false;
  }
}

template  <class T>
T Rectangle<T>::getParimeter() {
  T parimeter;
  parimeter = length * 2 + width * 2;
    
  return parimeter;
}

template  <class T>
T Rectangle<T>::getArea() {
  T area;
  area = length * width;
    
  return area;
}

#endif