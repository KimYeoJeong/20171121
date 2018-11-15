#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>

class Game
{
public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }

	//GameObject m_go;
	//Player m_player;




private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	int m_currentFrame;
	//TextureManager m_textureManager;

	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;

	std::vector<GameObject*> m_gameObjects;
};