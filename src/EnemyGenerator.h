#pragma once

#include "Spritesheet.h"
#include "Enemy.h"

class EnemyGenerator {

public:

  EnemyGenerator(Spritesheet* spriteSheet);

  Enemy* generate();

private:

  Spritesheet* m_spritesheet;
  int m_ticksSinceLast;

};
