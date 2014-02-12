#ifndef __GAME_OBJECT__
#define __GAME_OBJECT__

#include "LoaderParams.h"
#include "Vector2D.h"

class GameObject {
	
public:
	
	GameObject(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	
protected:
	
	int m_horizontalOffset;
	int m_verticalOffset;
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	Vector2D m_velocity;
	Vector2D m_position;
	Vector2D m_acceleration;
	
};
#endif