#include "GameOverState.h"
#include <SDL_rect.h>
#include <SDL.h>
#include "GameManager.h"
#include "SoundManager.h"
#include "InputManager.h"
#include "Button.h"
#include "StaticImage.h"
#include "InGameState.h"

const std::string BG_AUDIO = "SadPiano";
const std::string BG_AUDIO_PATH = "Resources/Audio/bgGameOver.wav";
const std::string BTN_RESTART = "btnRestart";
const std::string BTN_RESTART_PATH = "Resources/Sprites/btnRestart.png";
const std::string BG_GAMEOVER = "bgGameOver";
const std::string BG_GAMEOVER_PATH = "Resources/Textures/bgGameOver.png";



bool GameOverState::onEnter()
{
	// Audio
	SoundManager::Instance()->load(BG_AUDIO, BG_AUDIO_PATH, SoundType::MUSIC);
	SoundManager::Instance()->playMusic(BG_AUDIO, -1);


	// Imagem de fundo
	SDL_FRect bgRect = { 0, 0, 800, 600 };
	StaticImage* bgGameOver = new StaticImage(bgRect, BG_GAMEOVER, BG_GAMEOVER_PATH);
	m_gameObjects.push_back(bgGameOver);




	SDL_FRect buttonRect = {100, 500, 500, 85 };
	Button* button = new Button(buttonRect, BTN_RESTART, BTN_RESTART_PATH, onMenuPlayButtonClicked);
	m_gameObjects.push_back(button);

	return true;
}

bool GameOverState::onExit()
{
	SoundManager::Instance()->stopMusic();

	for (int i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();

	return true;
}

void GameOverState::update()
{
	for (int i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	if (GameManager::Instance()->buttonClicked)
	{
		GameManager::Instance()->buttonClicked = false;
		GameManager::Instance()->getStateMachine()->changeState(new InGameState());
	}
}
void GameOverState::render()
{
	for (int i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

string GameOverState::getStateID() const
{
	return "GameOver";
	//return string();
}

void GameOverState::onMenuPlayButtonClicked()
{
	GameManager::Instance()->buttonClicked = true;
	// Muda o estado para um novo, por exemplo
	// GameManager::Instance()->getStateMachine()->changeState(new PlayState());
}
