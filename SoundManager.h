#pragma once

#include <iostream>
#include <map>
#include <SDL.h>
#include <string>
#include <SDL_mixer.h>

using namespace std;

enum class SoundType
{
	MUSIC = 0,
	SFX = 1
};

class SoundManager
{
public:
	static SoundManager* Instance()
	{
		if (s_instance == 0)
			s_instance = new SoundManager();

		return s_instance;
	}

	bool load(string id, string fileName, SoundType type);
	// TODO VS: Criar metodos diferentes em vez de pedir o loop
	void playSound(string id, int loop);
	void playMusic(string id, int loop);
	void stopMusic();

private:
	SoundManager();
	~SoundManager();

	map<string, Mix_Chunk*> m_sfxs;
	map<string, Mix_Chunk*> m_music;

	static SoundManager* s_instance;
};
