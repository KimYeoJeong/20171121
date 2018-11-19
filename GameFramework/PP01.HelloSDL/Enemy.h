#pragma once
#include <map>
#include "GameObject.h"
#include "LoaderParams.h"
#include "SDLGameObject.h"


class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();

	void handleInput();
};