#include "Heart.h"


Heart::Heart(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Heart::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}


void Heart::update()
{

	m_velocity.setX(0);
	m_velocity.setY(0);

	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));


	SDLGameObject::update();

}
void Heart::clean()
{
}
