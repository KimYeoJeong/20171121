#pragma once
#include <map>
#include "GameObject.h"
#include "LoaderParams.h"
#include "SDLGameObject.h"
#include "AnimatedGraphic.h"

class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();
	void handleInput();

	int m_numFrames=5;
};