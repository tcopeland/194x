#ifndef __SPRITE_PARAMETERS__
#define __SPRITE_PARAMETERS__

class SpriteParameters {

public:

  SpriteParameters(int horizontalOffset, int verticalOffset, int width, int height, int imagesToCycle);

  int getHorizontalOffset();
  int getVerticalOffset();
  int getWidth();
  int getHeight();
  int getImagesToCycle();

private:

  int m_horizontalOffset;
  int m_verticalOffset;
  int m_width;
  int m_height;
  int m_imagesToCycle;

};


#endif
