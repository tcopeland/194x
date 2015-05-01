#ifndef __COLLISION__
#define __COLLISION__

#include "GameObject.h"

class Collision {

public:

  Collision();

  bool hitOccurred();
  void setHitOccurred();
  void setBullet(GameObject* bullet);
  GameObject* getBullet();

private:

  bool m_hitOccurred;
  GameObject* m_bullet;

};

#endif
