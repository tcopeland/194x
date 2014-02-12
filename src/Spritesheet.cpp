#include "Spritesheet.h"

Spritesheet::Spritesheet(const std::string fileName) {
  m_fileName = fileName;
  m_sprites["player"] = new SpriteParameters(598, 4, 99, 98);
}

std::string Spritesheet::getFilename() {
  return m_fileName;
}

SpriteParameters* Spritesheet::getSpriteParameters(std::string spriteName) {
  return m_sprites[spriteName];
}
