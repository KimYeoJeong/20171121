#include "background.h"


background::background(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void background::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}


void background::update()
{

	m_velocity.setX(0);
	m_velocity.setY(0);

	m_currentFrame = int(((SDL_GetTicks() / 100) %1));


	SDLGameObject::update();

}
void background::clean()
{
}
