#include "Spritesheet.h"

Spritesheet::Spritesheet(const std::string fileName) {
  m_fileName = fileName;
  m_sprites["player"] = new SpriteParameters(4, 400, 66, 62);
  m_sprites["play_game_label"] = new SpriteParameters(480, 385, 100, 20);
  m_sprites["quit_label"] = new SpriteParameters(480, 460, 80, 20);
}

std::string Spritesheet::getFilename() {
  return m_fileName;
}

SpriteParameters* Spritesheet::getSpriteParameters(std::string spriteName) {
  return m_sprites[spriteName];
}
