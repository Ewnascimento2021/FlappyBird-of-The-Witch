#include "Player.h"


Player::Player (SDL_FRect rect, string textureId, string texturePath) : GameObject (rect, textureId)
{
	m_playerRect = rect;
	TextureManager::Instance()->load(textureId, texturePath);
}
void Player::draw()
{
	TextureManager::Instance()->drawframe(m_textureID, &m_playerRect, m_currentRow, m_currentFrame);
}
void Player::update()
{
	if (isMouseClicked())
	{
		if (!k_buttonClicked)
		{
			onMouseClick();
		}
	}
	else
	{
		k_buttonClicked = false;
	}


	t += 1;
	v = vo + (g * t) - jumpForce;
	if (v > m_maxSpeed)
	{
		v = m_maxSpeed;
	}
	if (m_playerRect.y + v > 0 || m_playerRect.y + v < 550)
	{
		move();
	}
}

void Player::clean()
{
}
void Player::jump()
{
	v = 0;
	t = 0;
	jumpForce = 13;
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
	m_playerRect.y += v;
}

bool Player::isMouseClicked()
{
	if (InputManager::Instance()->getMouseButtonState(MouseButtons::LEFT) == true)
	{
		return true;
	}
	return false;
}

void Player::onMouseClick()
{
	k_buttonClicked = true;

	//SoundManager::Instance()->playSound(ICARUS_JUMP, 0);
	jump();
	//m_currentFrame = CLICKED;
	/*if (m_callback != NULL)
		m_callback();*/
}