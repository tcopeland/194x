#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams, FlightPath* flightPath) : GameObject(pParams) {
  m_flightPath = flightPath;
}

void Enemy::update() {
  Vector2D* velocity = m_flightPath->getPath(m_position.getX(), m_position.getY());
  m_velocity.setX(velocity->getX());
  m_velocity.setY(velocity->getY());
  GameObject::update();
}