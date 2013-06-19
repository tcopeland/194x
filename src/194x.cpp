#include "Game.h"

int main(int argc, char* args[]) {
	if (TheGame::Instance()->init("194x", 200, 200, 800, 600)) {
		while (TheGame::Instance()->running()) {
			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();
			SDL_Delay(10);
		}
	}
	TheGame::Instance()->clean();
	return 0;
}