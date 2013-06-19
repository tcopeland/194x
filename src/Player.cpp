#include "Player.h"
#include "Game.h"

Player::Player(const LoaderParams* pParams) : GameObject(pParams) {}

void Player::draw() {
	GameObject::draw();
}

void Player::update() {
	if (m_x > 0) {
		m_x -= 1;
	}
	m_currentFrame = (((SDL_GetTicks() / 100) % 6));
}

void Player::clean() {}