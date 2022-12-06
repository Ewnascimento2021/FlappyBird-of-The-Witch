#pragma once

#include <iostream>
#include <map>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "GameManager.h"
#include "TextureManager.h"

using namespace std;
class TTFLoader
{
public:
	static TTFLoader* Instance()
	{
		if (s_instance == NULL)
		{
			s_instance = new TTFLoader();
		}
		return s_instance;
	}

	bool load(string id, string path, int size);
	

	TTF_Font* getFont(string id) { return m_fontMap[id]; }
	void clearFromTextureMap(string id);
private:
	TTFLoader() {};
	~TTFLoader() {};
	
	map<string, TTF_Font*> m_fontMap;

	static TTFLoader* s_instance;
};

