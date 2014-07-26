#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams) : GameObject(pParams) {}

void Player::draw() {
  GameObject::draw();
}

void Player::update() {
  handleInput();
  m_currentFrame = (((SDL_GetTicks() / 100) % 3));
  GameObject::update();
  if (m_velocity.getX() > 0) {
    m_velocity.setX(m_velocity.getX()-1);
  }
  if (m_velocity.getX() < 0) {
    m_velocity.setX(m_velocity.getX()+1);
  }
  if (m_velocity.getY() > 0) {
    m_velocity.setY(m_velocity.getY()-1);
  }
  if (m_velocity.getY() < 0) {
    m_velocity.setY(m_velocity.getY()+1);
  }
}

void Player::setBulletManager(BulletManager* bulletManager) {
  m_bulletManager = bulletManager;
}

void Player::clean() {}

void Player::handleInput() {
  if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {
    Vector2D* halfPlayer = new Vector2D(22, 0);
    Vector2D newBulletPosition = m_position + *halfPlayer;
    m_bulletManager->addBullet(&newBulletPosition);
    SoundManager::Instance()->play_sound("bang");
  }
  if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
    m_velocity.setX(2);
  }
  if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
    m_velocity.setX(-2);
  }
  if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
    m_velocity.setY(2);
  }
  if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
    m_velocity.setY(-2);
  }
}
