#include "GameState.h"

GameState::GameState(Spritesheet* spritesheet) {}

void GameState::update() {
  std::vector<GameObject*> to_remove;
  for (std::vector<GameObject*>::iterator i = m_gameObjects.begin(); i != m_gameObjects.end(); i++) {
    GameObject* obj = *i;
    obj->update();
    if (obj->getPosition().getY() > 600) {
      to_remove.push_back(obj);
    }
  }
  for (std::vector<GameObject*>::iterator i = to_remove.begin(); i != to_remove.end(); i++) {
    //std::cout << "There are " << m_gameObjects.size() << " m_gameObjects in a vector of capacity " << m_gameObjects.capacity() << std::endl;
    m_gameObjects.erase(std::remove(m_gameObjects.begin(), m_gameObjects.end(), *i));
  }
}

void GameState::draw() {
  for (std::vector<GameObject*>::iterator i = m_gameObjects.begin(); i != m_gameObjects.end(); i++) {
    (*i)->draw();
  }
}