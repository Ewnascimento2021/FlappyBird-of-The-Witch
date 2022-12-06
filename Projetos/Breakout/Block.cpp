#include "Block.h"

#include "InGameState.h"


Block::Block(SDL_FRect rect, string textureId, string texturePath) : GameObject(rect, textureId)
{
	m_blockRect = rect;
	TextureManager::Instance()->load(textureId, texturePath);
}
void Block::draw()
{
	if (alive)
	{
		TextureManager::Instance()->draw(m_textureID, &m_blockRect);
	}
	
}

void Block::update()
{


}

bool Block::checkCollision(SDL_FRect* objectB)
{
	if (m_blockRect.x <= objectB->x + objectB->w
		&& m_blockRect.x + m_blockRect.w >= objectB->x
		&& m_blockRect.y <= objectB->y + objectB->h
		&& m_blockRect.y + m_blockRect.h >= objectB->y)
	{
		return true;
	}
	return false;


}

void Block::clean()
{
	
}

