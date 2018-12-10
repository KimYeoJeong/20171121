#pragma once
#include "GameState.h"


class GameStateMachine
{
         //srand로 초기화
 
public:

	
	void changeState(GameState* pState);
	void pushState(GameState* pState);

	void update();
	void render();

private:
	GameState* m_currentState;
	GameState* m_prevState;

};