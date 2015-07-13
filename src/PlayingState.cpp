#include "PlayingState.h"

PlayingState::PlayingState(Spritesheet* spritesheet) : GameState(spritesheet) {
  m_spritesheet = spritesheet;
  m_score = 0;
  m_explosionAnimations.reserve(10);
  m_gameObjects.reserve(50);
  m_scoreSpriteParameters[std::to_string('0')] = m_spritesheet->getSpriteParameters("zero");
  m_scoreSpriteParameters[std::to_string('1')] = m_spritesheet->getSpriteParameters("one");
  m_scoreSpriteParameters[std::to_string('2')] = m_spritesheet->getSpriteParameters("two");
  m_scoreSpriteParameters[std::to_string('3')] = m_spritesheet->getSpriteParameters("three");
  m_scoreSpriteParameters[std::to_string('4')] = m_spritesheet->getSpriteParameters("four");
  m_scoreSpriteParameters[std::to_string('5')] = m_spritesheet->getSpriteParameters("five");
  m_scoreSpriteParameters[std::to_string('6')] = m_spritesheet->getSpriteParameters("six");
  m_scoreSpriteParameters[std::to_string('7')] = m_spritesheet->getSpriteParameters("seven");
  m_scoreSpriteParameters[std::to_string('8')] = m_spritesheet->getSpriteParameters("eight");
  m_scoreSpriteParameters[std::to_string('9')] = m_spritesheet->getSpriteParameters("nine");
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
  // TODO how to avoid these std::string to char conversions?
  for (char& c : s) {
    loadAndDraw(m_scoreSpriteParameters[std::to_string(c)], current_x);
    current_x -= 15;
  }
}

void PlayingState::loadAndDraw(SpriteParameters* sp, int x) {
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
  std::vector<ExplosionAnimation*> to_remove;
  for (std::vector<ExplosionAnimation*>::iterator it = m_explosionAnimations.begin(); it != m_explosionAnimations.end(); ++it) {
    ExplosionAnimation* e = *it;
    if (e->done()) {
      to_remove.push_back(e);
    }
  }
  for (std::vector<ExplosionAnimation*>::const_iterator it = to_remove.begin(); it != to_remove.end(); ++it) {
    m_explosionAnimations.erase(std::remove(m_explosionAnimations.begin(), m_explosionAnimations.end(), *it), m_explosionAnimations.end());
    m_gameObjects.erase(std::remove(m_gameObjects.begin(), m_gameObjects.end(), *it), m_gameObjects.end());
  }

  GameState::update();
}
