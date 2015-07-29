#ifndef __PLAYER__
#define __PLAYER__

#include "SDL.h"
#include "GameObject.h"
#include "LoaderParams.h"
#include "BulletManager.h"

class Player : public GameObject {

public:
  
  Player(const LoaderParams* pParams);
  
  void draw();
  void update();
  void clean();
  void setBulletManager(BulletManager* bulletManager);
  
private:
  
  void handleInput();
  bool canFire();

  BulletManager* m_bulletManager;
  Uint32 m_lastFired;
  
};

#endif
