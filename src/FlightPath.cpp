#include "FlightPath.h"

FlightPath::FlightPath() {}

Vector2D* FlightPath::getPath(int posX, int posY) {
  int newX = 4;
  int newY = 0;
  if (posX > 700) {
    newX = 0;
    newY = 3;
  }
  if (posY > 200) {
    newX = -4;
    newY = 0;
  }
  return new Vector2D(newX, newY);
}

