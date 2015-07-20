#include "GameState.h"

GameState::GameState(Spritesheet* spritesheet) {}

void GameState::update() {
  std::set<GameObject*> to_remove;
  for (std::set<GameObject*>::const_iterator i = m_gameObjects.begin(); i != m_gameObjects.end(); i++) {
    GameObject* obj = *i;
    obj->update();
    if (obj->getPosition().getY() > 600) {
      to_remove.insert(obj);
    }
  }
  while (!to_remove.empty()) {
    GameObject* obj = *to_remove.begin();
    m_gameObjects.erase(obj);
    to_remove.erase(obj);
  }
  //std::cout << "There are " << m_gameObjects.size() << " m_gameObjects in a vector of capacity " << m_gameObjects.capacity() << std::endl;
}

void GameState::draw() {
  for (std::set<GameObject*>::const_iterator i = m_gameObjects.begin(); i != m_gameObjects.end(); i++) {
    (*i)->draw();
  }
}