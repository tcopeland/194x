#include "PlayingState.h"

PlayingState::PlayingState(Spritesheet* spritesheet) : GameState(spritesheet) {
  m_spritesheet = spritesheet;
  m_score = 0;
}

void PlayingState::initializeBulletManager() {
  m_bulletManager = new BulletManager(m_spritesheet);
}

void PlayingState::initializePlayer() {
  SpriteParameters *spriteParameters = m_spritesheet->getSpriteParameters("player");
  LoaderParams *loaderParams = new LoaderParams(spriteParameters->getHorizontalOffset(),
                                                spriteParameters->getVerticalOffset(),
                                                350, 450,
                                                spriteParameters->getWidth(),
                                                spriteParameters->getHeight(),
                                                spriteParameters->getImagesToCycle());

  m_player = new Player(loaderParams);
  m_player->setBulletManager(m_bulletManager);
  m_gameObjects.push_back(m_player);
}

void PlayingState::initializeNewEnemy() {
  SpriteParameters *spriteParameters = m_spritesheet->getSpriteParameters("enemy");
  int randX = 200 + (rand() % 600 );
  LoaderParams* loaderParams = new LoaderParams(spriteParameters->getHorizontalOffset(),
                                                spriteParameters->getVerticalOffset(),
                                                randX, 50,
                                                spriteParameters->getWidth(),
                                                spriteParameters->getHeight(),
                                                spriteParameters->getImagesToCycle());
   GameObject* enemy = new Enemy(loaderParams);
   m_gameObjects.push_back(enemy);
   m_enemies.push_back(enemy);
}

void PlayingState::draw() {
  m_bulletManager->draw();
  drawScore();
  GameState::draw();
}

void PlayingState::drawScore() {
  std::string s = std::to_string(m_score);
  std::reverse(s.begin(), s.end());
  int current_x = 65;
  for (char& c : s) {
    // TODO use a map
    if (c == '0') {
      loadAndDraw("zero", current_x);
    } else if (c == '1') {
      loadAndDraw("one", current_x);
    } else if (c == '2') {
      loadAndDraw("two", current_x);
    } else if (c == '3') {
      loadAndDraw("three", current_x);
    } else if (c == '4') {
      loadAndDraw("four", current_x);
    } else if (c == '5') {
      loadAndDraw("five", current_x);
    } else if (c == '6') {
      loadAndDraw("six", current_x);
    } else if (c == '7') {
      loadAndDraw("seven", current_x);
    } else if (c == '8') {
      loadAndDraw("eight", current_x);
    } else if (c == '9') {
      loadAndDraw("nine", current_x);
    }
    current_x -= 15;
  }
}

void PlayingState::loadAndDraw(std::string str, int x) {
  SpriteParameters* sp = m_spritesheet->getSpriteParameters(str);
  (new GameObject(new LoaderParams(sp->getHorizontalOffset(), sp->getVerticalOffset(), x, 5, sp->getWidth(), sp->getHeight(), sp->getImagesToCycle())))->draw();
}

void PlayingState::update() {
  if ((rand() % 1000) > 900) {
    initializeNewEnemy();
  }
  m_bulletManager->update();
  // Did bullet hit enemy?
  for (std::vector<GameObject*>::iterator i = m_enemies.begin(); i != m_enemies.end(); i++) {
    GameObject* enemy = *i;
    Collision* c = m_bulletManager->checkHit(enemy);
    if (c->hitOccurred()) {
      if (std::find(m_gameObjects.begin(), m_gameObjects.end(), enemy) != m_gameObjects.end()) {
        // TODO needs to be midpoint of enemy sprite
        ExplosionAnimation* explosionAnimation = ExplosionAnimation::createAtPosition(m_spritesheet, enemy->getPosition());
        m_explosionAnimations.push_back(explosionAnimation);
        m_gameObjects.push_back(explosionAnimation);
        // TODO if game objects are not ordered, a std::set has simpler removal functions
        // TODO what are the semantics of erase?  does it null out the object?  because it seems like the line below
        // causes segfaults because it's attempting to delete the object twice.
        //m_enemies.erase(std::remove(m_enemies.begin(), m_enemies.end(), enemy), m_enemies.end());
        m_gameObjects.erase(std::remove(m_gameObjects.begin(), m_gameObjects.end(), enemy), m_gameObjects.end());
        m_score += 100;
        m_bulletManager->removeBullet(c->getBullet());
      }
    }
  }
  // TODO possible to use RTTI to identify explosions in game objects list?
  for (std::vector<ExplosionAnimation*>::iterator it = m_explosionAnimations.begin(); it != m_explosionAnimations.end(); ++it) {
    ExplosionAnimation* e = *it;
    if (e->done()) {
      std::remove(m_explosionAnimations.begin(), m_explosionAnimations.end(), e), m_explosionAnimations.end();
      m_gameObjects.erase(std::remove(m_gameObjects.begin(), m_gameObjects.end(), e), m_gameObjects.end());
    }
  }
  GameState::update();
}
