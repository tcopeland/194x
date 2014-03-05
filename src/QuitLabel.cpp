#include "QuitLabel.h"

QuitLabel::QuitLabel(const LoaderParams *pParams) : GameObject(pParams) {}

void QuitLabel::update() {
  handleInput();
}

void QuitLabel::handleInput() {
  if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_Q)) {
    Game::Instance()->quit();
  }
}