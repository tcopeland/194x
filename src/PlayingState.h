#ifndef __PLAYING_STATE__
#define __PLAYING_STATE__

#include "GameState.h"
#include "BulletManager.h"

class PlayingState : public GameState {

public:

  PlayingState(Spritesheet* spritesheet);

  void initializeBulletManager();
  void initializePlayer();

private:

  BulletManager* m_bulletManager;
  Player* m_player;
  Spritesheet* m_spritesheet;

};

#endif
