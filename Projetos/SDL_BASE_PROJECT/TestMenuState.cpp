#include "TestMenuState.h"
#include <SDL.h>
#include "Button.h"
#include "GameManager.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "StaticImage.h"
#include "TextBox.h"
#include "TTFLoader.h"
#pragma region MUSIC
const string MUSIC_TESTMENU = "music_Test_Menu";
const string MUSIC_TESTMENU_PATH = "Resource Files/Audio/music_test.wav";
#pragma endregion
#pragma region Play Button
const string PNG_PLAY_BUTTON = "png_Test_Button";
const string PNG_PLAY_BUTTON_PATH = "Resource Files/Sprites/btn_test.png";
const string SFX_PLAY_BUTTON = "SFX_Play_Button";
const string SFX_PLAY_BUTTON_PATH = "Resource Files/Audio/sfx_test.wav";
#pragma endregion
#pragma region Background
const string BG_IMAGE_ID = "png_test";
const string BG_IMAGE_PATH = "Resource Files/Textures/test_state_bg.png";
#pragma endregion
#pragma region TextBox
const string FONT_ID = "ttf_DIOGENES";
const string FONT_PATH = "Resource Files/Fonts/DIOGENES.ttf";
const string TEXTURE_ID = "teste";
SDL_Color msgColor = { 255, 255, 0};
TextBox* msg1;
SDL_FRect newRect;
#pragma endregion


bool TestMenuState::onEnter()
{
	//ÁUDIO
	//SoundManager::Instance()->load(SFX_PLAY_BUTTON, SFX_PLAY_BUTTON_PATH, SoundType::SFX);
	SoundManager::Instance()->load(MUSIC_TESTMENU, MUSIC_TESTMENU_PATH, SoundType::MUSIC);
	SoundManager::Instance()->playMusic(MUSIC_TESTMENU, -1);
	//BACKGROUND
	SDL_FRect backGroundRect = { 0, 0, 800, 600 };
	StaticImage* backGroundImage = new StaticImage(backGroundRect, BG_IMAGE_ID, BG_IMAGE_PATH);
	m_gameObjects.push_back(backGroundImage);
	//PLAY BUTTON
	SDL_FRect btnPlayRect = { 100, 100, 192, 64 };
	Button* Button1 = new Button(btnPlayRect, PNG_PLAY_BUTTON, PNG_PLAY_BUTTON_PATH, SFX_PLAY_BUTTON, SFX_PLAY_BUTTON_PATH, onMenuPlayButtonClicked);
	m_gameObjects.push_back(Button1);

	//TEXT EXAMPLE (xPos, yPos, angle, rotationPoint, id, path, "texto")
	SDL_FRect ttfRect = { 0, 250, 800, 100 };
	msg1 = new TextBox(ttfRect, FONT_ID, TEXTURE_ID, FONT_PATH,48, "Start Message", msgColor);
	m_gameObjects.push_back(msg1);

	return true;

}
bool TestMenuState::onExit()
{
	SoundManager::Instance()->stopMusic();
	for (int i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	return true;
}
void TestMenuState::update()
{
	msg1->setAngle(msg1->getAngle() + 1);
	
	for (int i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	
	if (GameManager::Instance()->startButtonClicked)
	{
		GameManager::Instance()->startButtonClicked = false;
		//	GameManager::Instance()->getStateMachine()->changeState(new InGameState());
	}
}
void TestMenuState::render()
{
	for (int i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
void TestMenuState::onMenuPlayButtonClicked()
{
	cout << "\nO BOTAO FOI CLICADO" << endl;
	msg1->updateTexture(FONT_ID, TEXTURE_ID, "Updated Message", msgColor, newRect);
	GameManager::Instance()->startButtonClicked = true;
}
string TestMenuState::getStateID() const
{
	return "TestMenuState";
	//return s_stateID;
}