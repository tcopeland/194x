#include "EnemyGenerator.h"

EnemyGenerator::EnemyGenerator(Spritesheet* spriteSheet) {
  m_spritesheet = spriteSheet;
}

Enemy* EnemyGenerator::generate() {
  m_ticksSinceLast += 1;
  if (m_ticksSinceLast > 30) {
    m_ticksSinceLast = 0;
    SpriteParameters *spriteParameters = m_spritesheet->getSpriteParameters("enemy");
    int initialXPosition = 10;
    FlightPath* flightPath = new FlightPath();
    LoaderParams* loaderParams = new LoaderParams(spriteParameters->getHorizontalOffset(),
                                                  spriteParameters->getVerticalOffset(),
                                                  initialXPosition, 50,
                                                  spriteParameters->getWidth(),
                                                  spriteParameters->getHeight(),
                                                  spriteParameters->getImagesToCycle());
     return new Enemy(loaderParams, flightPath);
  } else {
    return NULL;
  }
}
