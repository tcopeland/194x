#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : GameObject(pParams) {}

void Enemy::update() {
  m_velocity.setY(1);
  m_velocity.setX(1);
  GameObject::update();
}