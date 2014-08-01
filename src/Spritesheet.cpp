#include "Spritesheet.h"

Spritesheet::Spritesheet(const std::string fileName) {
  m_fileName = fileName;
  loadPositions();
}

std::string Spritesheet::getFilename() {
  return m_fileName;
}

SpriteParameters* Spritesheet::getSpriteParameters(std::string spriteName) {
  return m_sprites[spriteName];
}

void Spritesheet::loadPositions() {
  std::ifstream file;
  file.open("assets/positions.txt", std::ios::in);
  std::string line;
  while(getline(file, line)) {
    char* cLine = strdup(line.c_str());
    char* savePtr;
    const char* delim = ",";
    char* spriteName = strtok_r(cLine, delim, &savePtr);
    int hoff = atoi(strtok_r(NULL, delim, &savePtr));
    int voff = atoi(strtok_r(NULL, delim, &savePtr));
    int w = atoi(strtok_r(NULL, delim, &savePtr));
    int h = atoi(strtok_r(NULL, delim, &savePtr));
    int imagesToCycle = atoi(strtok_r(NULL, delim, &savePtr));
    m_sprites[spriteName] = new SpriteParameters(hoff, voff, w, h, imagesToCycle);
  }
  file.close();
}
