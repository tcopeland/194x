#include "BulletManager.h"

BulletManager::BulletManager(Spritesheet* spritesheet) {
  m_spritesheet = spritesheet;
  m_bullets.reserve(50);
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

void BulletManager::draw() {
  for (std::vector<GameObject*>::iterator i = m_bullets.begin(); i != m_bullets.end(); i++) {
    (*i)->draw();
  }
}

void BulletManager::update() {
  // TODO is there an iterator that supports removal?  if not, can we just put these in a set vs a vector?
  std::vector<GameObject*> to_remove;
  for (std::vector<GameObject*>::iterator i = m_bullets.begin(); i != m_bullets.end(); i++) {
    (*i)->update();
    GameObject* bullet = *i;
    if (bullet->getPosition().getY() < 0) {
      to_remove.push_back(bullet);
    }
  }
  for (std::vector<GameObject*>::iterator i = to_remove.begin(); i != to_remove.end(); i++) {
    removeBullet(*i);
  }
}

void BulletManager::removeBullet(GameObject* bullet) {
  //std::cout << "There are " << m_bullets.size() << " bullets in a vector of capacity " << m_bullets.capacity() << std::endl;
  m_bullets.erase(std::remove(m_bullets.begin(), m_bullets.end(), bullet), m_bullets.end());
}

Collision* BulletManager::checkHit(GameObject* pGameObject) {
  Collision* c = new Collision();
  for (std::vector<GameObject*>::iterator i = m_bullets.begin(); i != m_bullets.end(); i++) {
    if (collided(pGameObject, (*i))) {
      c->setBullet(*i);
      c->setHitOccurred();
      return c;
    }
  }
  return c;
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
