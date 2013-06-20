#include "Player.h"
#include "Game.h"

Player::Player(const LoaderParams* pParams) : GameObject(pParams) {}

void Player::draw() {
	GameObject::draw();
}

void Player::update() {
	m_currentFrame = (((SDL_GetTicks() / 100) % 3));
}

void Player::clean() {}