#ifndef __PLAYING_STATE__
#define __PLAYING_STATE__

#include <set>
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

  void drawScore();
  void loadAndDraw(SpriteParameters* sp, int x);

  BulletManager* m_bulletManager;
  Player* m_player;
  Spritesheet* m_spritesheet;
  std::vector<GameObject*> m_enemies;
  std::set<ExplosionAnimation*> m_explosionAnimations;
  int m_score;
  std::map<std::string, SpriteParameters*> m_scoreSpriteParameters;

};

#endif
