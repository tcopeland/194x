#ifndef __Game__
#define __Game__

#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "GameObject.h"
#include "Player.h"
#include "Vector2D.h"
#include "SpriteParameters.h"
#include "Spritesheet.h"
#include "PlayingState.h"
#include "MenuState.h"
#include "GameState.h"
#include <iostream>

class Game {
	
public:
	
	~Game() {}
	
	static Game* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Game();
		}
		return s_pInstance;
	}
	
	SDL_Renderer* getRenderer() const {
		return m_pRenderer;
	}
	
	bool init(std::string title, int xpos, int ypos, int width, int height);
	void render();
	void handleEvents();
	void clean();
	void update();
	void quit();
  void changeToPlayingState();
	
	bool running() {
		return m_bRunning;
	}
	
private:
	
	Game() {}
		
	static Game* s_pInstance;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	GameState* m_gameState;
	
};

typedef Game TheGame;

#endif