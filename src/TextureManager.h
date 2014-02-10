#ifndef __TextureManager__
#define __TextureManager__

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <map>

class TextureManager {
	
public:
		TextureManager() {}
		~TextureManager() {}
		
		static TextureManager* Instance() {
			if (s_pInstance == 0) {
				s_pInstance = new TextureManager();
			}
			return s_pInstance;
		}
		
		bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
		void draw(std::string id, int x, int y, int w, int h, SDL_Renderer* pRenderer, SDL_RendererFlip flip=SDL_FLIP_NONE);
		void drawFrame(std::string id, int horizontalOffset, int verticalOffset, int x, int y, int w, int h, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip=SDL_FLIP_NONE);
	
private:
	
	std::map<std::string, SDL_Texture*> m_textureMap;
	static TextureManager* s_pInstance;
	
};

typedef TextureManager TheTextureManager;

#endif