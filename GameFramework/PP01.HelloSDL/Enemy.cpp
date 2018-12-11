#include "Enemy.h"
#include "InputHandler.h"


Enemy::Enemy(const LoaderParams* pParams, float Createspeed) : SDLGameObject(pParams)
{
	m_numSpeed = Createspeed;
	m_velocity.setY(m_numSpeed);
	m_velocity.setX(0.001);
}
void Enemy::draw()
{
	SDLGameObject::draw();
}
void Enemy::update()
{
	srand((unsigned)time(NULL));

	setX = rand() % 1+100;
	m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));
	if (m_position.getY() < 0) {

		m_velocity.setY(m_numSpeed);
	}
	else if (m_position.getY() > 700) {
		m_position.setY(0);

		state = true;
		m_velocity.setY(m_numSpeed + speedtest);
		positionUpdate += 100;
		m_position.setX(m_position.getX() + setX);
	
		if (positionUpdate >= 400)
		{
			speedtest += 0.5f;
			positionUpdate = 0;
			m_position.setX(m_position.getX() - 400);
		}
	}
	SDLGameObject::update();
}


void Enemy::clean()
{
}

void Enemy::handleInput()
{
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity.setX(1);
	}

}