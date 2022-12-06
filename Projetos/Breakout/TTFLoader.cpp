#include "TTFLoader.h"

TTFLoader* TTFLoader::s_instance = NULL;

bool TTFLoader::load(string id, string path, int size)
{

	TTF_Font* m_Font = TTF_OpenFont(path.c_str(), size);
	if (m_Font == NULL) {
		string error = TTF_GetError();
		cout << error << endl;
	}

	m_fontMap[id] = m_Font;

	return true;
}

void TTFLoader::clearFromTextureMap(string id)
{
	m_fontMap.erase(id);
}
