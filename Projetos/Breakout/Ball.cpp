#include "Ball.h"
#include "InGameState.h"

Ball::Ball(SDL_FRect rect, string textureId, string texturePath) : GameObject(rect, textureId)
{
	m_ballRect = rect;
	TextureManager::Instance()->load(textureId, texturePath);
}
void Ball::draw()
{
	TextureManager::Instance()->draw(m_textureID, &m_ballRect);
}

void Ball::update()
{

	if (m_ballRect.y > 590 - m_ballRect.h || m_ballRect.y < 0)
	{
		m_speedY *= -1;
	}

	move();
}


void Ball::clean()
{
}

void Ball::move()
{
	m_ballRect.x += m_speedX;
	m_ballRect.y += m_speedY;
}
