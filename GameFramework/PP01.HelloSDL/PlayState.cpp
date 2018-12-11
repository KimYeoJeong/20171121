#include "PlayState.h"
#include "GameOverState.h"

const std::string PlayState::s_playID = "PLAY";
PlayState* PlayState::s_pInstance = 0;

void PlayState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
	if (checkCollision(
		dynamic_cast<SDLGameObject*>(m_gameObjects[1]),
		dynamic_cast<SDLGameObject*>(m_gameObjects[2])
	)==true)
	{
		if (dynamic_cast<SDLGameObject*>(m_gameObjects[2])->state==true)
		{
			dynamic_cast<SDLGameObject*>(m_gameObjects[2])->state = false;
			if (m_gameObjects.size() == 10)
			{
				m_gameObjects.erase(m_gameObjects.begin() + 9);
			}
			else if (m_gameObjects.size() == 9)
			{
				m_gameObjects.erase(m_gameObjects.begin() + 8);
			}
			else if (m_gameObjects.size() == 8)
			{
				m_gameObjects.erase(m_gameObjects.begin() + 7);
			}
			if (m_gameObjects.size() == 7)
			{
				TheGame::Instance()->getStateMachine()->changeState(
					new GameOverState());
			}
		}
	}
	else if (checkCollision(
		dynamic_cast<SDLGameObject*>(m_gameObjects[1]),
		dynamic_cast<SDLGameObject*>(m_gameObjects[3])
	))
	{
		if (dynamic_cast<SDLGameObject*>(m_gameObjects[3])->state == true)
		{
			dynamic_cast<SDLGameObject*>(m_gameObjects[3])->state = false;
			if (m_gameObjects.size() == 10)
			{
				m_gameObjects.erase(m_gameObjects.begin() + 9);
			}
			else if (m_gameObjects.size() == 9)
			{
				m_gameObjects.erase(m_gameObjects.begin() + 8);
			}
			else if (m_gameObjects.size() == 8)
			{
				m_gameObjects.erase(m_gameObjects.begin() + 7);
			}
			if (m_gameObjects.size() == 7)
			{
				TheGame::Instance()->getStateMachine()->changeState(
					new GameOverState());
			}
		}
	}
	else if (checkCollision(
		dynamic_cast<SDLGameObject*>(m_gameObjects[1]),
		dynamic_cast<SDLGameObject*>(m_gameObjects[4])
	))
	{
		if (dynamic_cast<SDLGameObject*>(m_gameObjects[4])->state == true)
		{
			dynamic_cast<SDLGameObject*>(m_gameObjects[4])->state = false;
			if (m_gameObjects.size() == 10)
			{
				m_gameObjects.erase(m_gameObjects.begin() + 9);
			}
			else if (m_gameObjects.size() == 9)
			{
				m_gameObjects.erase(m_gameObjects.begin() + 8);
			}
			else if (m_gameObjects.size() == 8)
			{
				m_gameObjects.erase(m_gameObjects.begin() + 7);
			}
			if (m_gameObjects.size() == 7)
			{
				TheGame::Instance()->getStateMachine()->changeState(
					new GameOverState());
			}
		}
	}
	else if (checkCollision(
		dynamic_cast<SDLGameObject*>(m_gameObjects[1]),
		dynamic_cast<SDLGameObject*>(m_gameObjects[5])
	))
	{
		if (dynamic_cast<SDLGameObject*>(m_gameObjects[5])->state == true)
		{
			dynamic_cast<SDLGameObject*>(m_gameObjects[5])->state = false;
			if (m_gameObjects.size() == 10)
			{
				m_gameObjects.erase(m_gameObjects.begin() + 9);
			}
			else if (m_gameObjects.size() == 9)
			{
				m_gameObjects.erase(m_gameObjects.begin() + 8);
			}
			else if (m_gameObjects.size() == 8)
			{
				m_gameObjects.erase(m_gameObjects.begin() + 7);
			}
			if (m_gameObjects.size() == 7)
			{
				TheGame::Instance()->getStateMachine()->changeState(
					new GameOverState());
			}
		}
	}
	else if (checkCollision(
	dynamic_cast<SDLGameObject*>(m_gameObjects[1]),
	dynamic_cast<SDLGameObject*>(m_gameObjects[6])
	))
	{
	if (dynamic_cast<SDLGameObject*>(m_gameObjects[6])->state == true)
	{
		dynamic_cast<SDLGameObject*>(m_gameObjects[6])->state = false;
		if (m_gameObjects.size() == 10)
		{
			m_gameObjects.erase(m_gameObjects.begin() + 9);
		}
		else if (m_gameObjects.size() == 9)
		{
			m_gameObjects.erase(m_gameObjects.begin() + 8);
		}
		else if (m_gameObjects.size() == 8)
		{
			m_gameObjects.erase(m_gameObjects.begin() + 7);
		}
		if (m_gameObjects.size() == 7)
		{
			TheGame::Instance()->getStateMachine()->changeState(
				new GameOverState());
		}
	}
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->changeState(
			new PauseState());
	}
}


void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter()
{
	srand((unsigned)time(NULL));
	randompositionx = rand() % 1000;
	randompositionx1=rand() % 1000;
	randompositionx2=rand() % 1000;
	randompositionx3=rand() % 1000;
	randompositionx4 = rand() % 1000;
	if (!TheTextureManager::Instance()->load("assets/man.png",
		"man", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/bird.png",
		"bird", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/sky.jpg",
		"background", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/heart.png",
		"heart", TheGame::Instance()->getRenderer())) {
		return false;
	}

	GameObject* background_ = new background(
		new LoaderParams(0, 0, 1000, 700, "background"));
	GameObject* player = new Player(
		new LoaderParams(300, 400, 134, 145, "man"));
	GameObject* enemy1 = new Enemy(
		new LoaderParams(randompositionx, 10, 65, 100, "bird"),1.0f);
	GameObject* enemy2 = new Enemy(
		new LoaderParams(randompositionx1, 20, 65, 100, "bird"),0.7f);
	GameObject* enemy3= new Enemy(
		new LoaderParams(randompositionx2, 25, 65, 100, "bird"),1.5f);
	GameObject* enemy4 = new Enemy(
		new LoaderParams(randompositionx3, 15, 65, 100, "bird"),1.7f);
	GameObject* enemy5 = new Enemy(
		new LoaderParams(randompositionx4, 55, 65, 100, "bird"), 1.7f);

	GameObject* heart1 = new Heart(
		new LoaderParams(10, 30, 30, 30, "heart"));
	GameObject* heart2 = new Heart(
		new LoaderParams(10, 60, 30, 30, "heart"));
	GameObject* heart3 = new Heart(
		new LoaderParams(10, 90, 30, 30, "heart"));
	m_gameObjects.push_back(background_);
	m_gameObjects.push_back(player);
	m_gameObjects.push_back(enemy1);
	m_gameObjects.push_back(enemy2);
	m_gameObjects.push_back(enemy3);
	m_gameObjects.push_back(enemy4);
	m_gameObjects.push_back(enemy5);

	m_gameObjects.push_back(heart1);
	m_gameObjects.push_back(heart2);
	m_gameObjects.push_back(heart3);

	std::cout << "entering PlayState\n";
	return true;
}


bool PlayState::onExit()
{

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("man");
	std::cout << "exiting PlayState\n";
	return true;

}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2) //SDLGameObject* p3, SDLGameObject* p4, SDLGameObject* p5)
{
		int leftA, leftB, leftC, leftD;
		int rightA, rightB, rightC, rightD;
		int topA, topB, topC, topD;
		int bottomA, bottomB, bottomC, bottomD;

		leftA = p1->getPosition().getX();
		rightA = p1->getPosition().getX() + p1->getWidth();
		topA = p1->getPosition().getY();
		bottomA = p1->getPosition().getY() + p1->getHeight();

		//Calculate the sides of rect B
		leftB = p2->getPosition().getX();
		rightB = p2->getPosition().getX() + p2->getWidth();
		topB = p2->getPosition().getY();
		bottomB = p2->getPosition().getY() + p2->getHeight();
		//If any of the sides from A are outside of B
		if (bottomA <= topB) { return false; }
		if (topA >= bottomB) { return false; }
		if (rightA <= leftB) { return false; }
		if (leftA >= rightB) { return false; }

	/*
	if (bottomA <= topC) { return false; }
	if (topA >= bottomC) { return false; }
	if (rightA <= leftC) { return false; }
	if (leftA >= rightC) { return false; }

	if (bottomA <= topD) { return false; }
	if (topA >= bottomD) { return false; }
	if (rightA <= leftD) { return false; }
	if (leftA >= rightD) { return false; }
	*/
	return true;
}

