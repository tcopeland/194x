#pragma once

#include <map>
#include <iostream>
#include <string>
#include "SDL_mixer.h"

class SoundManager {

public:

  static SoundManager* Instance() {
    if (s_pInstance == 0) {
      s_pInstance = new SoundManager();
    }
    return s_pInstance;
  }

  bool load(std::string filename, std::string id);
  void play_sound(std::string id);

private:

  std::map<std::string, Mix_Chunk*> m_sfxs;

  SoundManager();
  ~SoundManager();

  static SoundManager* s_pInstance;

};

typedef SoundManager TheSoundManager;
