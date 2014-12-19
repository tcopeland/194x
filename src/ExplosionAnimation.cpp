#include "ExplosionAnimation.h"

ExplosionAnimation::ExplosionAnimation(const LoaderParams* pParams) : GameObject(pParams) {
  this->m_counter = 0;
}

void ExplosionAnimation::update() {
  this->m_counter += 1;
  GameObject::update();
}

bool ExplosionAnimation::done() {
  // this is stored in positions.txt, how to use that here?
  return this->m_counter > 7;
}
