#include "InputHandler.h"

InputHandler* InputHandler::s_pInstance = 0;

void InputHandler::update() {
  m_keystates = (Uint8 *)SDL_GetKeyboardState(0);
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        TheGame::Instance()->quit();
        break;
      case SDL_KEYDOWN:
        onKeyDown();
        break;
      case SDL_KEYUP:
        onKeyUp();
        break;
    }
  }
}

bool InputHandler::isKeyDown(SDL_Scancode key) {
  return m_keystates != 0 && m_keystates[key] == 1;
}

void InputHandler::clean() {}

void InputHandler::onKeyUp() {}

void InputHandler::onKeyDown() {}
