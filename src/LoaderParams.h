#ifndef __LOADER_PARAMS__
#define __LOADER_PARAMS__

#include <iostream>

class LoaderParams {
	
public:
	
	// TODO this is mixing the position on the screen (x,y) with the position
	// in the spritesheet (offset, width, height)
	LoaderParams(int horizontalOffset, int verticalOffset, int x, int y, int width, int height, int imagesToCycle) : m_horizontalOffset(horizontalOffset), m_verticalOffset(verticalOffset), m_x(x), m_y(y), m_width(width), m_height(height), m_imagesToCycle(imagesToCycle) {}
	~LoaderParams() {}
	
	int getHorizontalOffset() const { return m_horizontalOffset; }
	int getVerticalOffset() const { return m_verticalOffset; }
	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
  int getImagesToCycle() const { return m_imagesToCycle; }
	
private:
	
	int m_horizontalOffset;
	int m_verticalOffset;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
  int m_imagesToCycle;
	
};

#endif