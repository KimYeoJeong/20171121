#pragma once
#include <map>
#include "GameObject.h"
#include "LoaderParams.h"
#include "SDLGameObject.h"
#include "AnimatedGraphic.h"
#include <stdlib.h>       //srand
#include <time.h>     //time

class Enemy : public SDLGameObject
{
public:
	int positionUpdate=0;
	Enemy(const LoaderParams* pParams, float Createspeed);
	void draw();
	void update();
	void clean();
	void handleInput();
	
	int m_numFrames=2;
	float m_numSpeed = 1.0f;
	float speedtest=0;
	int setX=0;
};