#include "BulletManager.h"

BulletManager::BulletManager(Spritesheet* spritesheet) {
  m_spritesheet = spritesheet;
}

void BulletManager::addBullet(Vector2D* position) {
  SpriteParameters* bulletSpriteParameters = m_spritesheet->getSpriteParameters("bullet");
  LoaderParams* loaderParams = new LoaderParams(bulletSpriteParameters->getHorizontalOffset(),
                                                bulletSpriteParameters->getVerticalOffset(),
                                                position->getX(), position->getY(),
                                                bulletSpriteParameters->getWidth(),
                                                bulletSpriteParameters->getHeight(),
                                                bulletSpriteParameters->getImagesToCycle());
  GameObject* bullet = new GameObject(loaderParams);
  bullet->setVelocity(*(new Vector2D(0, -3)));
  m_bullets.push_back(bullet);
}

void BulletManager::removeBullet(GameObject* bullet) {
}

void BulletManager::draw() {
  for (std::vector<GameObject*>::iterator i = m_bullets.begin(); i != m_bullets.end(); i++) {
    (*i)->draw();
  }
}

void BulletManager::update() {
  for (std::vector<GameObject*>::iterator i = m_bullets.begin(); i != m_bullets.end(); i++) {
    (*i)->update();
  }
}

// FIXME return a Collision so that the bullet can be erased later
// and so that collision and bullet removal aren't conflated
bool BulletManager::hitAndEraseBullet(GameObject* pGameObject) {
  for (std::vector<GameObject*>::iterator i = m_bullets.begin(); i != m_bullets.end(); i++) {
    if (collided(pGameObject, (*i))) {
      m_bullets.erase(std::remove(m_bullets.begin(), m_bullets.end(), *i), m_bullets.end());
      return true;
    }
  }
  return false;
}

bool BulletManager::collided(GameObject* pA, GameObject* pB) {
  int leftA = pA->getPosition().getX();
  int rightA = leftA + pA->getWidth();
  int topA = pA->getPosition().getY();
  int bottomA = topA + pA->getHeight();

  int leftB = pB->getPosition().getX();
  int rightB = leftB + pB->getWidth();
  int topB = pB->getPosition().getY();
  int bottomB = topB + pB->getHeight();

  if ((rightA < leftB) || (leftA > rightB) || (bottomA < topB) || (topA > bottomB)) {
    return false;
  }

  return true;
}
