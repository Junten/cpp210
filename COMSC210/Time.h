//Time.h, by Junteng Tan (1489763)
#ifndef TIME_H
#define TIME_H

class Time {
public:
  void setHours(int);
  void setMinutes(int);
  void setSeconds(int);

  float timeInHours(void);
  float timeInMinutes(void);
  int timeInSeconds(void);

private:
  int hours;
  int minutes;
  int seconds;

};
#endif