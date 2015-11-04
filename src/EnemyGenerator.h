#ifndef __ENEMY_GENERATOR__
#define __ENEMY_GENERATOR__

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

#endif
