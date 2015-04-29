#include "PlayingState.h"

PlayingState::PlayingState(Spritesheet* spritesheet) : GameState(spritesheet) {
  m_spritesheet = spritesheet;
}

void PlayingState::initializeBulletManager() {
  m_bulletManager = new BulletManager(m_spritesheet);
}

void PlayingState::initializePlayer() {
  SpriteParameters *spriteParameters = m_spritesheet->getSpriteParameters("player");
  LoaderParams *loaderParams = new LoaderParams(spriteParameters->getHorizontalOffset(),
                                                spriteParameters->getVerticalOffset(),
                                                350, 450,
                                                spriteParameters->getWidth(),
                                                spriteParameters->getHeight(),
                                                spriteParameters->getImagesToCycle());

  m_player = new Player(loaderParams);
  m_player->setBulletManager(m_bulletManager);
  m_gameObjects.push_back(m_player);
}

void PlayingState::initializeEnemy() {
  SpriteParameters *spriteParameters = m_spritesheet->getSpriteParameters("enemy");
  LoaderParams* loaderParams = new LoaderParams(spriteParameters->getHorizontalOffset(),
                                                spriteParameters->getVerticalOffset(),
                                                350, 50,
                                                spriteParameters->getWidth(),
                                                spriteParameters->getHeight(),
                                                spriteParameters->getImagesToCycle());
   m_enemy = new Enemy(loaderParams);
   m_gameObjects.push_back(m_enemy);
}

void PlayingState::draw() {
  m_bulletManager->draw();
  GameState::draw();
}

void PlayingState::update() {
  m_bulletManager->update();
  // Did bullet hit enemy?
  if (m_bulletManager->hitAndEraseBullet(m_enemy)) {
    if (std::find(m_gameObjects.begin(), m_gameObjects.end(), m_enemy) != m_gameObjects.end()) {
      // TODO needs to be midpoint of enemy sprite
      ExplosionAnimation* explosionAnimation = ExplosionAnimation::createAtPosition(m_spritesheet, m_enemy->getPosition());
      m_explosionAnimations.push_back(explosionAnimation);
      m_gameObjects.push_back(explosionAnimation);
      // TODO if game objects are not ordered, a std::set has simpler removal functions
      m_gameObjects.erase(std::remove(m_gameObjects.begin(), m_gameObjects.end(), m_enemy), m_gameObjects.end());
    }
  }
  // TODO possible to use RTTI to identify explosions in game objects list?
  for (std::vector<ExplosionAnimation*>::iterator it = m_explosionAnimations.begin(); it != m_explosionAnimations.end(); ++it) {
    ExplosionAnimation* e = *it;
    if (e->done()) {
      std::remove(m_explosionAnimations.begin(), m_explosionAnimations.end(), e), m_explosionAnimations.end();
      m_gameObjects.erase(std::remove(m_gameObjects.begin(), m_gameObjects.end(), e), m_gameObjects.end());
    }
  }
  GameState::update();
}
