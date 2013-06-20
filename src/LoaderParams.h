#ifndef __LOADER_PARAMS__
#define __LOADER_PARAMS__

#include <iostream>

class LoaderParams {
	
public:
	
	LoaderParams(int offset, int x, int y, int width, int height, std::string textureID) : m_offset(offset), m_x(x), m_y(y), m_width(width), m_height(height), m_textureID(textureID) {}
	~LoaderParams() {}
	
	int getOffset() const { return m_offset; }
	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	std::string getTextureID() const { return m_textureID; }
	
private:
	
	int m_offset;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	std::string m_textureID;
	
};

#endif