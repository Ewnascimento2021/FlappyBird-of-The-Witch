#pragma once

#include <iostream>
#include <map>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

#include "GameManager.h"
	
using namespace std;

class TextureManager
{
public:
	static TextureManager* Instance() {
		if (s_instance == NULL)
			s_instance = new TextureManager();

		return s_instance;
	}

	bool load(string id, string path);
	void draw(string id, SDL_FRect* rect, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawframe(string id, SDL_FRect* rect, int currentRow, int currentFrame, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void clearFromTextureMap(string id);

private:
	TextureManager() {};
	~TextureManager() {};

	map<string, SDL_Texture*> m_textureMap;

	static TextureManager* s_instance;
};
