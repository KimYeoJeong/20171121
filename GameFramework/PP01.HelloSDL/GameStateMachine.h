#pragma once
#include "GameState.h"

class GameStateMachine
{
public:
	
	void changeState(GameState* pState);
	void pushState(GameState* pState);

	void update();
	void render();

private:
	GameState* m_currentState;
	GameState* m_prevState;

};