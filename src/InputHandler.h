#pragma once

#include "SDL.h"
#include "Game.h"
#include "SoundManager.h"
#include <vector>

class InputHandler {
	
public:
	
	InputHandler() {};
	
	static InputHandler* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	
	void update();
	void clean();
	bool isKeyDown(SDL_Scancode key);
	
private:
	
	~InputHandler();
	static InputHandler* s_pInstance;
	Uint8* m_keystates;
	
	void onKeyUp();
	void onKeyDown();
};
