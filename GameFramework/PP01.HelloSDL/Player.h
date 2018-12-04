#pragma once
#include "GameObject.h"
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "SDL.h"

class Player : public SDLGameObject
{
public:
	Player(const LoaderParams* pParams);		//Player 객체를 생성하는 함수
	void draw();								//Player를 그려주는 함수
	void update();								//Player를 매 프레임 작동시켜 주는 함수
	void clean();

private:
	void handleInput();//Player의 조작을 담당하는 함수 
};
