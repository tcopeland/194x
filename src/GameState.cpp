#include "GameState.h"

GameState::GameState(Spritesheet* spritesheet) {}

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