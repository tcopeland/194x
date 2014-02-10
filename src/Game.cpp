#include "Game.h"

Game* Game::s_pInstance = 0;

bool Game::init(std::string title, int xpos, int ypos, int width, int height) {
	SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);
	m_pWindow = SDL_CreateWindow(title.c_str(), xpos, ypos, width, height, 0);
	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
	SDL_SetRenderDrawColor(m_pRenderer, 0, 100, 220, 255);
	TheTextureManager::Instance()->load("assets/1945.png", "1945", m_pRenderer);
	// I need metadata about the spritesheet
	m_gameObjects.push_back(new Player(new LoaderParams(598, 4, 350, 450, 99, 98, "1945")));
	m_bRunning = true;
	return true;
}

void Game::update() {
	for (std::vector<GameObject*>::iterator i = m_gameObjects.begin(); i != m_gameObjects.end(); i++) {
		(*i)->update();
	}
}

void Game::render() {
	SDL_RenderClear(m_pRenderer);
	for (std::vector<GameObject*>::iterator i = m_gameObjects.begin(); i != m_gameObjects.end(); i++) {
		(*i)->draw();
	}
	SDL_RenderPresent(m_pRenderer);
}

void Game::handleEvents() {
	InputHandler::Instance()->update();
}

void Game::clean() {
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::quit() {
	m_bRunning = false;
}