#include "MainMenuState.h"
#include <SDL_rect.h>
#include <SDL.h>
#include "GameManager.h"
#include "SoundManager.h"
#include "InputManager.h"
#include "Button.h"
#include "StaticImage.h"
#include "InGameState.h"


const std::string BG_AUDIO = "bgAutioMenu";
const std::string BG_AUDIO_PATH = "Resources/Audio/bgMenu.wav";
const std::string BTN_PLAY = "btnPlay";
const std::string BTN_PLAY_PATH = "Resources/Sprites/btnPlay.png";
const std::string BG_MENU = "bgMENU";
const std::string BG_MENU_PATH = "Resources/Textures/bgMenu.png";



bool MainMenuState::onEnter()
{
// Audio
	SoundManager::Instance()->load(BG_AUDIO, BG_AUDIO_PATH, SoundType::MUSIC);
	SoundManager::Instance()->playMusic(BG_AUDIO, -1);


// Imagem de fundo
	SDL_FRect bgRect = { 0, 0, 800, 600 };
	StaticImage* bgMenu = new StaticImage(bgRect, BG_MENU, BG_MENU_PATH);
	m_gameObjects.push_back(bgMenu);




	SDL_FRect buttonRect = { 600, 500, 192, 64 };
	Button* button = new Button(buttonRect, BTN_PLAY, BTN_PLAY_PATH, onMenuPlayButtonClicked);
	m_gameObjects.push_back(button);

	return true;
}

bool MainMenuState::onExit()
{

	SoundManager::Instance()->stopMusic();


	for (int i = 0; i != m_gameObjects.size(); i++)
		m_gameObjects[i]->clean();

	m_gameObjects.clear();
	return true;
}

void MainMenuState::update()
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

void MainMenuState::render()
{
	for (int i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

string MainMenuState::getStateID() const
{
	return "MainMenu";
	//return string();
}

void MainMenuState::onMenuPlayButtonClicked()
{
	GameManager::Instance()->buttonClicked = true;
}
//cout << "MUDA PARA O PLAY STATE" << endl;
	// Muda o estado para um novo, por exemplo
	// GameManager::Instance()->getStateMachine()->changeState(new PlayState());