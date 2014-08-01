#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : GameObject(pParams) {}

void Enemy::update() {
  m_currentFrame = ((SDL_GetTicks() / 100) % 3);
}