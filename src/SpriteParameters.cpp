#include "SpriteParameters.h"

SpriteParameters::SpriteParameters(int horizontalOffset, int verticalOffset, int width, int height, int imagesToCycle) {
  m_horizontalOffset = horizontalOffset;
  m_verticalOffset = verticalOffset;
  m_width = width;
  m_height = height;
  m_imagesToCycle = imagesToCycle;
}

int SpriteParameters::getHorizontalOffset(){
  return m_horizontalOffset;
}

int SpriteParameters::getVerticalOffset(){
  return m_verticalOffset;
}

int SpriteParameters::getWidth() {
  return m_width;
}

int SpriteParameters::getHeight() {
  return m_height;
}

int SpriteParameters::getImagesToCycle() {
  return m_imagesToCycle;
}
