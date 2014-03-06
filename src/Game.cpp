#include "Game.h"

Game* Game::s_pInstance = 0;

bool Game::init(std::string title, int xpos, int ypos, int width, int height) {
  SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);
  m_pWindow = SDL_CreateWindow(title.c_str(), xpos, ypos, width, height, 0);
  m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
  SDL_SetRenderDrawColor(m_pRenderer, 2, 73, 148, 255);
  Spritesheet *spritesheet = new Spritesheet("assets/1945.png");
  TheTextureManager::Instance()->load(spritesheet, m_pRenderer);
  m_gameState = new MenuState(spritesheet);
  m_bRunning = true;
  return true;
}

void Game::update() {
  m_gameState->update();
}

void Game::render() {
  SDL_RenderClear(m_pRenderer);
  m_gameState->draw();
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

void Game::changeToPlayingState() {
  Spritesheet *spritesheet = new Spritesheet("assets/1945.png");
  m_gameState = new PlayingState(spritesheet);
}
