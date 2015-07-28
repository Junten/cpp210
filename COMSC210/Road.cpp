//Road.cpp, by Junteng Tan (1489763)

#include "Road.h"

void Road::setWidth(int arg) {
  width = arg;
}

int Road::getWidth() const {
  return width;
}

void Road::setLength(int arg) {
  length = arg;
}

int Road::getLength() const {
  return length;
}

int Road::asphalt(int thick) {
  int result;
  result = 5280 * length * width * thick / 12;

  return result;
}


	