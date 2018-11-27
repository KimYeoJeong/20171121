#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include "GameStateMachine.h"
#include "MenuState.h"
#include "PlayState.h"

class Game
{
private:

	Game() {};
	// create the s_pInstance member variable
	static Game* s_pInstance;
	// create the typedef

	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	int m_currentFrame;



	std::vector<GameObject*> m_gameObjects;

	GameStateMachine* m_pGameStateMachine;


public:

	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	void quit();
	bool running() { return m_bRunning; }


	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
};

#pragma once

typedef Game TheGame;