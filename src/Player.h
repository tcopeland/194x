#ifndef __PLAYER__
#define __PLAYER__

#include "SDL.h"
#include "GameObject.h"
#include "LoaderParams.h"
#include "BulletManager.h"

class Player : public GameObject {

public:
	
	Player(const LoaderParams* pParams);
	
  // TODO what does 'virtual void' mean?
	virtual void draw();
	virtual void update();
	virtual void clean();

  void setBulletManager(BulletManager* bulletManager);
	
private:
	
	void handleInput();

  BulletManager* m_bulletManager;
	
};

#endif
