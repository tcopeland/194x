#pragma once

#include <vector>
#include <set>
#include "SpriteParameters.h"
#include "LoaderParams.h"
#include "Player.h"
#include "GameObject.h"
#include "Spritesheet.h"

class GameState {

public:

  GameState(Spritesheet* pSpritesheet);

  virtual void update();
  virtual void draw();

protected:

  std::set<GameObject*> m_gameObjects;

};
