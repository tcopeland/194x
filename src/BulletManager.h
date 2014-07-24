#ifndef __BULLET_MANAGER__
#define __BULLET_MANAGER__

#include "Vector2D.h"
#include "GameObject.h"
#include <vector>

class BulletManager {

public:

  BulletManager() {};
  void add_bullet(Vector2D* position);
  void remove_bullet(GameObject* bullet);

private:

  std::vector<GameObject*> m_gameObjects;

};

#endif
