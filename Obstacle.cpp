#include "Obstacle.h"
#include <time.h>

Obstacle::Obstacle (SDL_FRect rect, string textureId, string texturePath) : GameObject(rect, textureId)
{
	m_obstacleRect1 = rect;
	m_obstacleRect2.x = m_obstacleRect1.x;
	m_obstacleRect2.y = m_obstacleRect1.y + m_obstacleRect1.h + pointRectHeight;
	m_obstacleRect2.w = m_obstacleRect1.w;
	m_obstacleRect2.h = m_obstacleRect1.h;
	m_obstaclePointRect.x = m_obstacleRect1.x;
	m_obstaclePointRect.y = m_obstacleRect1.y + m_obstacleRect1.h;
	m_obstaclePointRect.w = m_obstacleRect1.w;
	m_obstaclePointRect.h = pointRectHeight;


	TextureManager::Instance()->load(textureId, texturePath);
}
void Obstacle::draw()
{
	TextureManager::Instance()->drawframe(m_textureID, &m_obstacleRect1, m_currentRow, m_currentFrame);
	TextureManager::Instance()->drawframe(m_textureID, &m_obstacleRect2, m_currentRow, m_currentFrame);
}
void Obstacle::update()
{

	if (m_obstacleRect1.x <= 0 - m_obstacleRect1.w)
	{
		m_obstacleRect1.x = 980;
		m_obstacleRect1.y = (rand() % 400) - 400;
		m_obstacleRect2.y = m_obstacleRect1.y + m_obstacleRect1.h + pointRectHeight;
		m_obstaclePointRect.y = m_obstacleRect1.y + m_obstacleRect1.h;
	}

	m_obstacleRect2.x = m_obstacleRect1.x;
	m_obstaclePointRect.x = m_obstacleRect1.x;

	move(); 
}

void Obstacle::clean()
{
}

void Obstacle::move()
{
	m_obstacleRect1.x += m_speed;
	m_obstacleRect2.x += m_speed;
	m_obstaclePointRect.x += m_speed;
}