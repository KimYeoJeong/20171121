#pragma once
#include "GameState.h"
#include "GameOverState.h"
#include "PauseState.h"

class GameStateMachine
{
public:
	
	void changeState(GameState* pState);
	void popState(PauseState* PState);
	void push(GameOverState* GState);

	void update();
	void render();

private:
	GameState* m_currentState;
	GameState* m_prevState;

};