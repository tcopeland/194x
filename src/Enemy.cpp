#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : GameObject(pParams) {}

void Enemy::update() {
  m_velocity.setY(1);
  GameObject::update();
}