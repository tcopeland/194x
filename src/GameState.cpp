#include "GameState.h"

GameState::GameState(Spritesheet* spritesheet) {
  SpriteParameters *spriteParameters = spritesheet->getSpriteParameters("player");
  LoaderParams *loaderParams = new LoaderParams(spriteParameters->getHorizontalOffset(),
                                                spriteParameters->getVerticalOffset(),
                                                350, 450,
                                                spriteParameters->getWidth(),
                                                spriteParameters->getHeight());
  m_gameObjects.push_back(new Player(loaderParams));
}

void GameState::update() {
  for (std::vector<GameObject*>::iterator i = m_gameObjects.begin(); i != m_gameObjects.end(); i++) {
    (*i)->update();
  }
}

void GameState::draw() {
  for (std::vector<GameObject*>::iterator i = m_gameObjects.begin(); i != m_gameObjects.end(); i++) {
    (*i)->draw();
  }
}