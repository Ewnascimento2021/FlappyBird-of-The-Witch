#include "Player.h"
#include "InGameState.h"



Player::Player(SDL_FRect rect, string textureId, string texturePath) : GameObject(rect, textureId)
{
	m_playerRect = rect;
	TextureManager::Instance()->load(textureId, texturePath);
}
void Player::draw()
{
	TextureManager::Instance()->draw(m_textureID, &m_playerRect);
}
void Player::update()
{
	if (InputManager::Instance()->isKeyDown(SDLK_a))
	{
		m_direction = -1;		
	}

	if (InputManager::Instance()->isKeyDown(SDLK_d))
	{
		m_direction = 1;
	}

	if (m_direction != 0 && m_playerRect.x + m_speed * m_direction > 0 && m_playerRect.x + m_speed * m_direction < 800 - m_rect.w && m_rect.x + m_speed * m_direction > 0)
	{
		move();
		m_direction = 0;
	}
}


void Player::clean()
{
}
bool Player::checkCollision(SDL_FRect* objectB)
{
	if (m_playerRect.x <= objectB->x + objectB->w
		&& m_playerRect.x + m_playerRect.w >= objectB->x
		&& m_playerRect.y <= objectB->y + objectB->h
		&& m_playerRect.y + m_playerRect.h >= objectB->y)
	{
		return true;
	}
	return false;


}
void Player::move()
{
	m_playerRect.x += m_speed * m_direction;
}