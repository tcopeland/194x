#include "Game.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* args[]) {
	Uint32 frameStart, frameTime;
	if (TheGame::Instance()->init("194x", 200, 200, 800, 600)) {
		while (TheGame::Instance()->running()) {
			frameStart = SDL_GetTicks();
			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();
			SDL_Delay(10);
			frameTime = SDL_GetTicks() - frameStart;
			if (frameTime < DELAY_TIME) {
				SDL_Delay(DELAY_TIME - frameTime);
			}
		}
	}
	TheGame::Instance()->clean();
	return 0;
}
