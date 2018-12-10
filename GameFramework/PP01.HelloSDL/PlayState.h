#pragma once
#include "GameState.h"
#include "Game.h"
#include "GameObject.h"
#include "PauseState.h"
#include "SDLGameObject.h"
#include <stdlib.h>       //srand
#include <time.h>     //time
#include "background.h"
#include "Heart.h"
class GameObject;
class PlayState : public GameState
{
public:
	int randompositionx;
	int randompositionx1;
	int randompositionx2;
	int randompositionx3;
	int randompositionx4;
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }


	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);

	static PlayState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new PlayState();
			return s_pInstance;
		}
		return s_pInstance;
	}
private:
	static const std::string s_playID;
	static PlayState* s_pInstance;
	std::vector<GameObject*> m_gameObjects;
};