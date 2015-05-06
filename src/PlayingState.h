#ifndef __PLAYING_STATE__
#define __PLAYING_STATE__

#include "GameState.h"
#include "BulletManager.h"
#include "Enemy.h"
#include "ExplosionAnimation.h"

class PlayingState : public GameState {

public:

  PlayingState(Spritesheet* spritesheet);

  void initializeBulletManager();
  void initializePlayer();
  void initializeNewEnemy();
  void draw();
  void update();

private:

  BulletManager* m_bulletManager;
  Player* m_player;
  Spritesheet* m_spritesheet;
  std::vector<GameObject*> m_enemies;
  std::vector<ExplosionAnimation*> m_explosionAnimations;

};

#endif
