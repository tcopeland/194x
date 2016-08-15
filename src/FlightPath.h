#pragma once

#include "Vector2D.h"
#include <iostream>

class FlightPath {

public:

  FlightPath();

  Vector2D* getPath(int posX, int posY);
};
