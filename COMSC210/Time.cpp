//Time.cpp

#include "Time.h"

void Time::setHours(int arg) {
  hours = arg;
}

void Time::setMinutes(int arg) {
  minutes = arg;
}

void Time::setSeconds(int arg) {
  seconds =arg;
}

float Time::timeInHours() {
  float result;
  result = hours + (float)minutes / 60 + (float)seconds / 3600;

  return result;
}

float Time::timeInMinutes() {
  float result;
  result = hours * 60 + minutes + (float)seconds / 60;

  return result;
}

int Time::timeInSeconds() {
  int result;
  result = hours * 3600 + minutes * 60 + seconds;

  return result;
}
