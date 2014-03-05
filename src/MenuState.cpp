#include "MenuState.h"

MenuState::MenuState(Spritesheet* spritesheet) : GameState(spritesheet) {
  SpriteParameters *playGameLabelSpriteParameters = spritesheet->getSpriteParameters("play_game_label");
  m_gameObjects.push_back(new GameObject(new LoaderParams(playGameLabelSpriteParameters->getHorizontalOffset(),
                                                playGameLabelSpriteParameters->getVerticalOffset(),
                                                300, 200,
                                                playGameLabelSpriteParameters->getWidth(),
                                                playGameLabelSpriteParameters->getHeight())));

  SpriteParameters *quitLabelSpriteParameters = spritesheet->getSpriteParameters("quit_label");
  m_gameObjects.push_back(new QuitLabel(new LoaderParams(quitLabelSpriteParameters->getHorizontalOffset(),
                                                quitLabelSpriteParameters->getVerticalOffset(),
                                                300, 300,
                                                quitLabelSpriteParameters->getWidth(),
                                                quitLabelSpriteParameters->getHeight())));
}
