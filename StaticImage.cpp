#include "StaticImage.h"
#include "TextureManager.h"

StaticImage::StaticImage(SDL_FRect rect, string textureId, string texturePath) : GameObject(rect, textureId)
{
	TextureManager::Instance()->load(textureId, texturePath);
}

void StaticImage::draw()
{
	TextureManager::Instance()->draw(m_textureID, &m_rect);
}

void StaticImage::update()
{
}

void StaticImage::clean()
{
	TextureManager::Instance()->clearFromTextureMap(m_textureID);
	delete this;
}