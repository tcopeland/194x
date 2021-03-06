#pragma once

#include "LoaderParams.h"
#include "Vector2D.h"

class GameObject {

public:

  GameObject(const LoaderParams* pParams);
  virtual void draw();
  virtual void update();
  virtual void clean();
  virtual void setVelocity(Vector2D velocity);
  Vector2D getPosition();
  int getWidth();
  int getHeight();

protected:

  int m_horizontalOffset;
  int m_verticalOffset;
  int m_width;
  int m_height;
  int m_currentRow;
  int m_currentFrame;
  int m_imagesToCycle;
  Vector2D m_velocity;
  Vector2D m_position;
  Vector2D m_acceleration;

};
