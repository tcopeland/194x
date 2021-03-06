#include "BulletManager.h"

BulletManager::BulletManager(Spritesheet* spritesheet) {
  m_spritesheet = spritesheet;
}

void BulletManager::addBullet(Vector2D* position, Vector2D* velocity) {
  if (velocity == NULL) {
    velocity = new Vector2D(0, -3);
  }
  SpriteParameters* bulletSpriteParameters = m_spritesheet->getSpriteParameters("bullet");
  LoaderParams* loaderParams = new LoaderParams(bulletSpriteParameters->getHorizontalOffset(),
                                                bulletSpriteParameters->getVerticalOffset(),
                                                position->getX(), position->getY(),
                                                bulletSpriteParameters->getWidth(),
                                                bulletSpriteParameters->getHeight(),
                                                bulletSpriteParameters->getImagesToCycle());
  GameObject* bullet = new GameObject(loaderParams);
  bullet->setVelocity(*(velocity));
  m_bullets.insert(bullet);
}

void BulletManager::draw() {
  for (auto& bullet : m_bullets) {
    bullet->draw();
  }
}

bool BulletManager::noBulletsInFlight() {
  return m_bullets.empty();
}

void BulletManager::update() {
  // TODO is there an iterator that supports removal?
  std::set<GameObject*> to_remove;
  for (auto& bullet : m_bullets) {
    bullet->update();
    if (bullet->getPosition().getY() < 0) {
      to_remove.insert(bullet);
    }
  }
  while (!to_remove.empty()) {
    GameObject* g = *to_remove.begin();
    removeBullet(g);
    to_remove.erase(g);
  }
}

void BulletManager::removeBullet(GameObject* bullet) {
  // std::cout << "There are " << m_bullets.size() << " bullets in the set" << std::endl;
  m_bullets.erase(bullet);
}

void BulletManager::clear() {
  m_bullets.clear();
}

Collision* BulletManager::checkHit(GameObject* pGameObject) {
  Collision* c = new Collision();
  for (auto& bullet : m_bullets) {
    if (collided(pGameObject, bullet)) {
      c->setBullet(bullet);
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
