#ifndef __PLAYER__
#define __PLAYER__

#include "GameObject.h"
#include "InputHandler.h"

class Player : public GameObject {

public:
	
	Player(const LoaderParams* pParams);
	
	virtual void draw();
	virtual void update();
	virtual void clean();
	
private:
	
	void handleInput();
	
};

#endif
