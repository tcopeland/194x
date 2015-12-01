#pragma once

#include "SDL.h"
#include "GameObject.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "Game.h"

class QuitLabel : public GameObject {

public:

  QuitLabel(const LoaderParams* pParams);

  void update();

private:

  void handleInput();

};
