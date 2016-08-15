#include "FlightPath.h"

FlightPath::FlightPath() {}

Vector2D* FlightPath::getPath(int posX, int posY) {
  int newX = 3;
  int newY = 0;
  // object past screen midpoint?
  if (posX > 400) {
    newY = -2;
  } else {
    newY = 2;
  }
  Vector2D* v = new Vector2D(newX, newY);
  return v;
}

