#include "SoundManager.h"

SoundManager* SoundManager::s_instance;

SoundManager::SoundManager()
{
	Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);
}
SoundManager::~SoundManager()
{
	Mix_CloseAudio();
}
bool SoundManager::load(string id , string filePath, SoundType type)
{
	Mix_Chunk* mixChunk = Mix_LoadWAV(filePath.c_str());
	if (mixChunk == NULL)
	{
		cout << "ERROR :: Could not load audio: " << Mix_GetError() << std::endl;
		return false;
	}
	switch (type)
	{
		case SoundType::MUSIC:
				m_music[id] = mixChunk;
			break;

		case SoundType::SFX:
				m_sfxs[id] = mixChunk;
			break;

		default:
				cout << "ERROR :: audio type not found" << std::endl;
				return false;
			break;
	}

	return true;
}
void SoundManager::playSound(string id, int loop)
{
	Mix_PlayChannel(-1, m_sfxs[id], loop);
}
void SoundManager::playMusic(string id, int loop)
{
	Mix_PlayChannel(-1, m_music[id], loop);
}
void SoundManager::stopMusic()
{
	Mix_HaltChannel(-1);
}
