#include "MenuState.h"

const std::string MenuState::s_menuID = "MENU";

MenuState* MenuState::s_pInstance = 0;

void MenuState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void MenuState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/button.png",
		"playbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/exit.png",
		"exitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/sky.jpg",
		"background", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* button1 = new MenuButton(
		new LoaderParams(300, 400, 400, 100, "playbutton"),
		s_menuToPlay);

	GameObject* button2 = new MenuButton(
		new LoaderParams(300, 500, 400, 100, "exitbutton"),
		s_exitFromMenu);

	GameObject* background_ = new background(
		new LoaderParams(0, 0, 1000, 700, "background"));
	m_gameObjects.push_back(background_);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);


	std::cout << "entering MenuState\n";
	return true;

}

bool MenuState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()
		->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()
		->clearFromTextureMap("exitbutton");
	std::cout << "exiting MenuState\n";
	return true;
}

void MenuState::s_menuToPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());

}


void MenuState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
}

std::string MenuState::getStateID() const
{
	return s_menuID;
}


MenuButton::MenuButton(const LoaderParams* pParams, void(*callback)()) : SDLGameObject(pParams), m_callback(callback)
{
}
