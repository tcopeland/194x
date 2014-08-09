#ifndef __EXPLOSION_ANIMATION__
#define __EXPLOSION_ANIMATION__

#include "GameObject.h"
#include "Vector2D.h"
#include "Spritesheet.h"

class ExplosionAnimation : public GameObject {

  public:

  ExplosionAnimation(const LoaderParams* pParams);

  static ExplosionAnimation* createAtPosition(Spritesheet* spritesheet, Vector2D initialPosition) {
    SpriteParameters* sp = spritesheet->getSpriteParameters("explosion");
    LoaderParams* params = new LoaderParams(sp->getHorizontalOffset(),
    sp->getVerticalOffset(),
    initialPosition.getX(),
    initialPosition.getY(),
    sp->getWidth(),
    sp->getHeight(),
    sp->getImagesToCycle());
    return new ExplosionAnimation(params);
  }
};

#endif
