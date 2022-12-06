#include "TextureManager.h"

TextureManager* TextureManager::s_instance = NULL;

bool TextureManager::load(string id, string path)
{
	SDL_Surface* tempSurface = IMG_Load(path.c_str());
	if (tempSurface == NULL) 
	{
		cout << "Fail to load " << path.c_str() << "\n";
		return false;
	}

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(GameManager::Instance()->getRenderer(), tempSurface);
	if (pTexture == NULL) 
	{
		cout << "Fail to create SDL_Texture with " << path.c_str() << "\n";
		return false;
	}

	// TODO: Verificar se o ID já existe
	m_textureMap[id] = pTexture;
	SDL_FreeSurface(tempSurface);

	return true;
}

void TextureManager::draw(string id, SDL_FRect* rect, double angle, SDL_RendererFlip flip)
{
	SDL_RenderCopyExF(GameManager::Instance()->getRenderer(), m_textureMap[id], NULL, rect, angle, 0, flip);
}

void TextureManager::drawframe(string id, SDL_FRect* rect, int currentRow, int currentFrame, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	srcRect.x = rect->w * currentFrame;
	srcRect.y = rect->h * currentRow;
	srcRect.w = rect->w;
	srcRect.h = rect->h;

	SDL_RenderCopyExF(GameManager::Instance()->getRenderer(), m_textureMap[id], &srcRect, rect, 0, 0, flip);
}

void TextureManager::clearFromTextureMap(string id)
{
	// TODO: Remover texture da memoria
	m_textureMap.erase(id);
}
