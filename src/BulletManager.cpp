#include "BulletManager.h"

BulletManager* BulletManager::s_pInstance = 0;

BulletManager::BulletManager() {

}

void BulletManager::add_bullet(Vector2D* position) {
  printf("BANG\n");
}

void BulletManager::remove_bullet(GameObject* bullet) {

}
