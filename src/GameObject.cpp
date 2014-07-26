#include "GameObject.h"
#include "Game.h"

GameObject::GameObject(const LoaderParams* pParams) : m_position(pParams->getX(), pParams->getY()), m_velocity(0,0), m_acceleration(0,0) {
  m_horizontalOffset = pParams->getHorizontalOffset();
  m_verticalOffset = pParams->getVerticalOffset();
  m_width = pParams->getWidth();
  m_height = pParams->getHeight();
  m_currentRow = 1;
  m_currentFrame = 1;
}

void GameObject::draw() {
  TheTextureManager::Instance()->drawFrame(m_horizontalOffset, m_verticalOffset, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer());
}

void GameObject::update() {
  m_position += m_velocity;
}

void GameObject::clean() {}

void GameObject::setVelocity(Vector2D velocity) {
  m_velocity = velocity;
}