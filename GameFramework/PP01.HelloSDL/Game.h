#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>


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

	//GameObject m_go;
	//Player m_player;

	std::vector<GameObject*> m_gameObjects;

	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;

public:
	//Game() {}
	//~Game() {}
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }

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