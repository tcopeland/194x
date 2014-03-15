#include "SoundManager.h"

SoundManager* SoundManager::s_pInstance = 0;

SoundManager::SoundManager() {
  Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);
}

SoundManager::~SoundManager() {
  Mix_CloseAudio();
}

bool SoundManager::load(std::string file_name, std::string id) {
  Mix_Chunk* pChunk = Mix_LoadWAV(file_name.c_str());
  if(pChunk == 0) {
    std::cout << "Couldn't load Special Effect. Error - " << Mix_GetError() << std::endl;
    return false;
  }
  m_sfxs[id] = pChunk;
  return true;
}

void SoundManager::play_sound(std::string id){
  Mix_PlayChannel(-1, m_sfxs[id], 0);
}

