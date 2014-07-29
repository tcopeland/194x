#ifndef __SPRITESHEET__
#define __SPRITESHEET__

#include <iostream>
#include <map>
#include "SpriteParameters.h"
#include <fstream>
#include <string>

class Spritesheet {

public:

  Spritesheet(const std::string fileName);

  std::string getFilename();
  SpriteParameters* getSpriteParameters(std::string spriteName);


private:

  void loadPositions();

  std::string m_fileName;
  std::map<std::string, SpriteParameters*> m_sprites;

};

#endif
