#include "InGameState.h"
#include <SDL.h>
#include "GameManager.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "StaticImage.h"
#include "TextBox.h"
#include "TTFLoader.h"
#include "Player.h"
#include "Ball.h"
#include "Block.h"


//Start Audio - 
// ON_ENTER_AUDIO = "E_LA_VAMOS_NOS";
// ON_ENTER_AUDIO_PATH = "Resources/Audio/playGame.wav";    
const std::string ON_ENTER_AUDIO = "InGameMusic";
const std::string ON_ENTER_AUDIO_PATH = "Resource Files/Audio/InGameMusic.wav";


//Tela de Fundo
const string BG_IMAGE_ID = "png_test";
const string BG_IMAGE_PATH = "Resource Files/Textures/test_state_bg.png";

//Player
const string PNG_PLAY_PLAYER = "png_Player";
const string PNG_PLAY_PLAYER_PATH = "Resource Files/Sprites/Player.png";

//Ball
const string PNG_PLAY_BALL = "png_Ball";
const string PNG_PLAY_BALL_PATH = "Resource Files/Sprites/Ball.png";

Player* plataforma;
Ball* ballGame;
Block* quadrado[10][10];
int contQuadrados = 0;




bool InGameState::onEnter()
{
	//ÁUDIO
	//SoundManager::Instance()->load(ON_ENTER_AUDIO, ON_ENTER_AUDIO_PATH, SoundType::MUSIC);
	//SoundManager::Instance()->playMusic(ON_ENTER_AUDIO, -1);
	/*
	//TEXT EXAMPLE (xPos, yPos, angle, rotationPoint, id, path, "texto")
	SDL_FRect ttfRect = { 0, 250, 800, 100 };
	msg1 = new TextBox(ttfRect, FONT_ID, TEXTURE_ID, FONT_PATH, 48, "Start Message", msgColor);
	m_gameObjects.push_back(msg1);*/

	//Criando Bola
	SDL_FRect ballRect = { 400,530,20,20 };
	ballGame = new Ball(ballRect, PNG_PLAY_BALL, PNG_PLAY_BALL_PATH);
	m_gameObjects.push_back(ballGame);

	//Criando Player
	SDL_FRect playerRect = { 370,550,80,12 };
	plataforma = new Player(playerRect, PNG_PLAY_PLAYER, PNG_PLAY_PLAYER_PATH);
	m_gameObjects.push_back(plataforma);

	// Criando Blocos
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			SDL_FRect blockRect = {50 + 70 * i,20 + 30 * j,70,30 };
			//quadrado[i][j] = new Block(blockRect, PNG_PLAY_PLAYER, PNG_PLAY_PLAYER_PATH);
			brocos.push_back(new Block(blockRect, PNG_PLAY_PLAYER, PNG_PLAY_PLAYER_PATH));
			m_gameObjects.push_back(brocos.back());
			
		}

	}

	return true;

	}

bool InGameState::onExit()
{
	SoundManager::Instance()->stopMusic();
	for (int i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	return true;
}
void InGameState::update()
{
	for (int i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	//CheckCollision entre Bola e Player

	if (plataforma->checkCollision(ballGame->getBall()))

	{
		ballGame->invertBallY();
	}

	//CheckCollision entre Bola e Blocos



		//Paredes da Tela
		if (ballGame->getRectX() > 780)
		{
			ballGame->invertBall();
		}

		if (ballGame->getRectX() < 0)
		{
			ballGame->invertBall();
		}

		if (ballGame->getRectY() > 590)
		{
			ballGame->invertBall();
		}

		// check Collision bola e blocos
		for (int i = 0; i < brocos.size(); i++)
		{			
			if (brocos[i]->checkCollision(ballGame->getBall())&& brocos[i]->alive)
				{
					ballGame->invertBallY();
					brocos[i]->alive = false;
				}
			}
	}



void InGameState::render()
{
	for (int i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	
}
string InGameState::getStateID() const
{
	return "InGameState";
	//return s_stateID; 
}
