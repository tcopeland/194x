#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams) : GameObject(pParams) {
  m_lastFired = 0;
}

void Player::draw() {
  GameObject::draw();
}

void Player::update() {
  handleInput();
  GameObject::update();
  if (m_position.getX() < 0) {
    m_position.setX(0);
  } else if (m_position.getX() > 738) {
    // 738 = 800 - sprite width
    m_position.setX(738);
  }
  if (m_position.getY() < 0) {
    m_position.setY(0);
  } else if (m_position.getY() > 545) {
    // 545 = 600 - sprite height
    m_position.setY(545);
  }
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

bool Player::canFire() {
  Uint32 timeSinceLast = SDL_GetTicks() - m_lastFired;
  return m_lastFired == 0 || timeSinceLast > 1000 || m_bulletManager->noBulletsInFlight();
}

void Player::handleInput() {
  if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE) && canFire()) {
    // TODO generate bullets based on a strategy
    // TODO bullet could contain trajectory
    m_lastFired = SDL_GetTicks();
    Vector2D* halfPlayer1 = new Vector2D(30, 0);
    Vector2D* halfPlayer2 = new Vector2D(14, 0);
    Vector2D newBullet1Position = m_position + *halfPlayer1;
    m_bulletManager->addBullet(&newBullet1Position);
    Vector2D newBullet2Position = m_position + *halfPlayer2;
    m_bulletManager->addBullet(&newBullet2Position);
    // SoundManager::Instance()->play_sound("bang");
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
