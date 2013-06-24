#ifndef __INPUT_HANDLER__
#define __INPUT_HANDLER__

#include "SDL.h"
#include "Game.h"
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
	std::vector<bool> m_mouseButtonStates;
	Uint8* m_keystates;
	
	void onKeyUp();
	void onKeyDown();
};


#endif