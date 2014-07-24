#ifndef __PLAY_LABEL__
#define __PLAY_LABEL__

#include "SDL.h"
#include "GameObject.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "Game.h"

class PlayLabel : public GameObject {

public:

  PlayLabel(const LoaderParams* pParams);

  void update();

private:

  void handleInput();

};

#endif
