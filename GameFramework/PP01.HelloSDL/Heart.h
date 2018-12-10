#pragma once
#include "GameObject.h"
#include "SDLGameObject.h"
#include "SDL.h"

class Heart : public SDLGameObject
{
public:
	Heart(const LoaderParams* pParams);		//Player 객체를 생성하는 함수
	~Heart() {}
	void draw();								//Player를 그려주는 함수
	void update();								//Player를 매 프레임 작동시켜 주는 함수
	void clean();


};
