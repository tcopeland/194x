#include "PlayLabel.h"

PlayLabel::PlayLabel(const LoaderParams* pParams): GameObject(pParams) {}

void PlayLabel::update() {
  handleInput();
}

void PlayLabel::handleInput() {
  if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_P)) {
    Game::Instance()->changeToPlayingState();
  }
}