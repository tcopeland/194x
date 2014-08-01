#ifndef __ENEMY__
#define __ENEMY__

#include "SDL.h"
#include "GameObject.h"
#include "LoaderParams.h"

class Enemy : public GameObject {

public:

  Enemy(const LoaderParams* pParams);

  void update();

};

#endif
