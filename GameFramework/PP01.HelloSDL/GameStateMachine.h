#pragma once
#include "GameState.h"


class GameStateMachine
{
         //srand�� �ʱ�ȭ
 
public:

	
	void changeState(GameState* pState);
	void pushState(GameState* pState);

	void update();
	void render();

private:
	GameState* m_currentState;
	GameState* m_prevState;

};