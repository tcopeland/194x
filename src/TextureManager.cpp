#include "TextureManager.h"

TextureManager* TextureManager::s_pInstance=0;

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer) {
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
	if (pTempSurface == 0) {
		return false;
	}
	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);
	if (pTexture == 0) {
		return false;
	}
	m_textureMap[id] = pTexture;
	return true;
}

void TextureManager::draw(std::string id, int x, int y, int w, int h, SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = w;
	srcRect.h = destRect.h = h;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int offset, int x, int y, int w, int h, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = offset + (currentFrame * w);
	// Adding 4 pixels here because airplane images
	// have a top border margin
	// TODO parameterize this
	srcRect.y = h * (currentRow - 1) + 4;
	// Subtracting two pixels here because the airplane images
	// have a white border line.
	// TODO does this hold for all images?
	srcRect.w = destRect.w = w-2;
	srcRect.h = destRect.h = h;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

