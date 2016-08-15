#pragma once

#include "SDL.h"
#include "GameObject.h"
#include "LoaderParams.h"
#include "FlightPath.h"

class Enemy : public GameObject {

public:

  Enemy(const LoaderParams* pParams, FlightPath* flightPath);

  void update();

private:

  FlightPath* m_flightPath;

};
