#ifndef __GAME_STATE__
#define __GAME_STATE__

#include <vector>
#include "SpriteParameters.h"
#include "LoaderParams.h"
#include "Player.h"
#include "GameObject.h"
#include "Spritesheet.h"
#include "GameObject.h"

class GameState {

public:

  GameState(Spritesheet* pSpritesheet);

  void update();
  void draw();

private:

  std::vector<GameObject*> m_gameObjects;

};

#endif
