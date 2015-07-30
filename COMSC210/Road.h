//Road.h

#ifndef ROAD_H
#define ROAD_H

class Road {
public:
  void setWidth(int);
  int getWidth(void) const;

  void setLength(int);
  int getLength(void) const;
	
  int asphalt(int);
private:
  int width;
  int length;
};

#endif