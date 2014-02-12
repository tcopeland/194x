#include "TextureManager.h"

TextureManager* TextureManager::s_pInstance=0;

bool TextureManager::load(Spritesheet* spritesheet, SDL_Renderer* pRenderer) {
	SDL_Surface* pTempSurface = IMG_Load(spritesheet->getFilename().c_str());
	if (pTempSurface == 0) {
		return false;
	}
	m_texture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);
	if (m_texture == 0) {
		return false;
	}
	return true;
}

void TextureManager::draw(int x, int y, int w, int h, SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = w;
	srcRect.h = destRect.h = h;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, m_texture, &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(int horizontalOffset, int verticalOffset, int x, int y, int w, int h, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = horizontalOffset + (currentFrame * w);
	srcRect.y = h * (currentRow - 1) + verticalOffset;
	// Subtracting two pixels here because the airplane images
	// have a white border line.
	// TODO does this hold for all images?
	srcRect.w = destRect.w = w-2;
	srcRect.h = destRect.h = h;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, m_texture, &srcRect, &destRect, 0, 0, flip);
}

