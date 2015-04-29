#ifndef __BULLET_MANAGER__
#define __BULLET_MANAGER__

#include "Vector2D.h"
#include "GameObject.h"
#include "Spritesheet.h"
#include <vector>

class BulletManager {

public:

  BulletManager(Spritesheet* spritesheet);
  void addBullet(Vector2D* position);
  void removeBullet(GameObject* bullet);
  void draw();
  void update();
  bool hitAndEraseBullet(GameObject* pGameObject);

private:

  std::vector<GameObject*> m_bullets;
  Spritesheet* m_spritesheet;
  bool collided(GameObject* pA, GameObject* pB);

};

#endif
