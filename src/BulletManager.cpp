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