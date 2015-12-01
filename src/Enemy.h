#pragma once

#include "SDL.h"
#include "GameObject.h"
#include "LoaderParams.h"

class Enemy : public GameObject {

public:

  Enemy(const LoaderParams* pParams);

  void update();

};
