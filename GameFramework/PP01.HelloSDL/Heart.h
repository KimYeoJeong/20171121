#pragma once
#include "GameObject.h"
#include "SDLGameObject.h"
#include "SDL.h"

class Heart : public SDLGameObject
{
public:
	Heart(const LoaderParams* pParams);		//Player ��ü�� �����ϴ� �Լ�
	~Heart() {}
	void draw();								//Player�� �׷��ִ� �Լ�
	void update();								//Player�� �� ������ �۵����� �ִ� �Լ�
	void clean();


};
