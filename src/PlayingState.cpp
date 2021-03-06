#include "PlayingState.h"

PlayingState::PlayingState(Spritesheet* spritesheet) : GameState(spritesheet) {
  m_spritesheet = spritesheet;
  m_enemyGenerator = new EnemyGenerator(spritesheet);
  m_score = 0;
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
  m_gameObjects.insert(m_player);
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
  for (auto c : s) {
    loadAndDraw(m_scoreSpriteParameters[std::to_string(c)], current_x);
    current_x -= 15;
  }
}

void PlayingState::loadAndDraw(SpriteParameters* sp, int x) {
  (new GameObject(new LoaderParams(sp->getHorizontalOffset(), sp->getVerticalOffset(), x, 5, sp->getWidth(), sp->getHeight(), sp->getImagesToCycle())))->draw();
}

void PlayingState::update() {
  Enemy* newEnemy = m_enemyGenerator->generate();
  if (newEnemy) {
    m_gameObjects.insert(newEnemy);
    m_enemies.insert(newEnemy);
  }

  m_bulletManager->update();

  std::set<GameObject*> enemies_to_remove;
  for (auto& enemy : m_enemies) {

  // Did player hit enemy?
    if (m_bulletManager->collided(m_player, enemy)) {
      ExplosionAnimation* explosionAnimation = ExplosionAnimation::createAtPosition(m_spritesheet, m_player->getPosition());
      m_explosionAnimations.insert(explosionAnimation);
      m_gameObjects.insert(explosionAnimation);
      enemies_to_remove.insert(enemy);
      if (m_score >= 100) {
        m_score -= 100;
      }
      m_bulletManager->clear();
    }

  // Did bullet hit enemy?
    Collision* c = m_bulletManager->checkHit(enemy);
    if (c->hitOccurred()) {
      if (std::find(m_gameObjects.begin(), m_gameObjects.end(), enemy) != m_gameObjects.end()) {
        // TODO needs to be midpoint of enemy sprite
        ExplosionAnimation* explosionAnimation = ExplosionAnimation::createAtPosition(m_spritesheet, enemy->getPosition());
        m_explosionAnimations.insert(explosionAnimation);
        m_gameObjects.insert(explosionAnimation);
        enemies_to_remove.insert(enemy);
        m_gameObjects.erase(enemy);
        m_score += 100;
        m_bulletManager->removeBullet(c->getBullet());
      }
    }
  }

  while (!enemies_to_remove.empty()) {
    GameObject* obj = *enemies_to_remove.begin();
    m_enemies.erase(obj);
    m_gameObjects.erase(obj);
    enemies_to_remove.erase(obj);
  }

  // TODO possible to use RTTI to identify explosions in game objects list?
  std::set<ExplosionAnimation*> to_remove;
  for (auto& e : m_explosionAnimations) {
    if (e->done()) {
      to_remove.insert(e);
    }
  }
  while (!to_remove.empty()) {
    //std::cout << "There are " << m_explosionAnimations.size() << " m_explosionAnimations in a vector of capacity " << m_explosionAnimations.capacity() << std::endl;
    ExplosionAnimation* obj = *to_remove.begin();
    m_explosionAnimations.erase(obj);
    to_remove.erase(obj);
    m_gameObjects.erase(obj);
  }

  GameState::update();
}
