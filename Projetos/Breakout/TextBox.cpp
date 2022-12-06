#include "TextBox.h"
#include "TTFLoader.h"
#include "TextureManager.h"
TextBox::TextBox(SDL_FRect rect, string fontId, string textureId, string fontPath, int size, string initialMsg, SDL_Color color) : GameObject(rect, textureId)
{
	TTFLoader::Instance()->load(fontId, fontPath, size);
	m_msgSurface = TTF_RenderText_Solid(TTFLoader::Instance()->getFont(fontId), initialMsg.c_str(), color);
	TextureManager::Instance()->setTexture(textureId, SDL_CreateTextureFromSurface(GameManager::Instance()->getRenderer(), m_msgSurface));
	SDL_FreeSurface(m_msgSurface);
}

void TextBox::draw()
{
	TextureManager::Instance()->draw(m_textureID, &m_rect, m_angle);
}

void TextBox::updateTexture(string fontId, string textureId, string msg, SDL_Color color, SDL_FRect position)
{
	m_msgSurface = TTF_RenderText_Solid(TTFLoader::Instance()->getFont(fontId), msg.c_str(), color);
	TextureManager::Instance()->setTexture(textureId, SDL_CreateTextureFromSurface(GameManager::Instance()->getRenderer(), m_msgSurface));
	SDL_FreeSurface(m_msgSurface);
}

void TextBox::clean()
{
	TextureManager::Instance()->clearFromTextureMap(m_textureID);

	delete this;
}

void TextBox::update()
{
}
