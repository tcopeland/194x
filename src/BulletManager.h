#ifndef __BULLET_MANAGER__
#define __BULLET_MANAGER__

#include "Vector2D.h"
#include "GameObject.h"
#include <vector>

class BulletManager {

public:

  static BulletManager* Instance() {
    if (s_pInstance == 0) {
      s_pInstance = new BulletManager();
    }
    return s_pInstance;
  }

  void add_bullet(Vector2D* position);
  void remove_bullet(GameObject* bullet);

private:

  BulletManager();
  ~BulletManager();

  static BulletManager* s_pInstance;

  std::vector<GameObject*> m_gameObjects;

};

typedef BulletManager TheBulletManager;

#endif
