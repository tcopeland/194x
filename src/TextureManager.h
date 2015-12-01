#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "Spritesheet.h"
#include <iostream>

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

    bool load(Spritesheet* spritesheet, SDL_Renderer* pRenderer);
    void draw(int x, int y, int w, int h, SDL_Renderer* pRenderer, SDL_RendererFlip flip=SDL_FLIP_NONE);
    void drawFrame(int horizontalOffset, int verticalOffset, int x, int y, int w, int h, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip=SDL_FLIP_NONE);

private:

  SDL_Texture* m_texture;
  static TextureManager* s_pInstance;

};

typedef TextureManager TheTextureManager;
