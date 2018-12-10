#pragma once
#include "GameObject.h"
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "SDL.h"

class background : public SDLGameObject
{
public:
	background(const LoaderParams* pParams);		//Player ��ü�� �����ϴ� �Լ�
	void draw();								//Player�� �׷��ִ� �Լ�
	void update();								//Player�� �� ������ �۵����� �ִ� �Լ�
	void clean();


};
