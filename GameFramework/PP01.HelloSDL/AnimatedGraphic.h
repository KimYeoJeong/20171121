#pragma once
#include "LoaderParams.h"
#include "GameObject.h"
#include "SDLGameObject.h"
#include "Enemy.h"

class AnimatedGraphic: public SDLGameObject
{	
public:

	AnimatedGraphic(const LoaderParams* pParams, int animSpeed);
	void update();

	int m_numFrames=100;
	int m_animSpeed=5;

private:

};