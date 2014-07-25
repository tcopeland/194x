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
                                                spriteParameters->getHeight());

  m_player = new Player(loaderParams);
  m_player->setBulletManager(m_bulletManager);
  m_gameObjects.push_back(m_player);
}

void PlayingState::draw() {
  m_bulletManager->draw();
  GameState::draw();
}

void PlayingState::update() {
  m_bulletManager->update();
  GameState::update();
}