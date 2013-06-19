#include "GameObject.h"
#include "LoaderParams.h"
#include "Game.h"

GameObject::GameObject(const LoaderParams* pParams) {
	m_x = pParams->getX();
	m_y = pParams->getY();
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();
	m_currentRow = 1;
	m_currentFrame = 1;
}

void GameObject::draw() {
	TheTextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer());
}

void GameObject::update() {
	if (m_x < 640-m_width) {
		m_x += 1;
	}
}

void GameObject::clean() {}

