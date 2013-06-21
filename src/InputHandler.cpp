#include "InputHandler.h"

InputHandler* InputHandler::s_pInstance = 0;

void InputHandler::update() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			TheGame::Instance()->quit();
		} 
	}
}

void InputHandler::clean() {}