#include "Collision.h"

Collision::Collision() {}

void Collision::setHitOccurred() {
  m_hitOccurred = true;
}

bool Collision::hitOccurred() {
  return m_hitOccurred;
}

void Collision::setBullet(GameObject* bullet) {
  m_bullet = bullet;
}

GameObject* Collision::getBullet() {
  return m_bullet;
}
