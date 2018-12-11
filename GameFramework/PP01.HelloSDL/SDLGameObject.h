#pragma once
#include"GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	void draw(SDL_Renderer* pRenderer) {};
	virtual void draw();
	virtual void update();
	virtual void clean() {};

	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;

	Vector2D& getPosition() { return m_position; }
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
	
	bool state = true;
protected:

	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;

	std::string m_textureID;
};