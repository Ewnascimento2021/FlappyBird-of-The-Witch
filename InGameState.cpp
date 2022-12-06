#include "InGameState.h"
#include <SDL_rect.h>
#include <SDL.h>
#include <time.h>
#include "GameManager.h"
#include "SoundManager.h"
#include "InputManager.h"
#include "StaticImage.h"
#include "Player.h"
#include "Obstacle.h"
#include "GameOverState.h"


//const std::string BG_AUDIO_PATH = "Resources/Audio/bgMenu.wav";
const std::string ON_ENTER_AUDIO = "E_LA_VAMOS_NOS";
const std::string ON_ENTER_AUDIO_PATH = "Resources/Audio/playGame.wav";
const std::string BG_AUDIO = "bgInGame";
const std::string BG_AUDIO_PATH = "Resources/Audio/bgGame.wav";
const std::string BG_IMAGE = "ImageGame";
const std::string BG_IMAGE_PATH = "Resources/Textures/bgGame.png";
const std::string PLAYER_IMAGE = "Player_Bruxa";
const std::string PLAYER_IMAGE_PATH = "Resources/Sprites/Bruxa.png";
const std::string OBSTACLE_IMAGE = "FOGUEIRA";
const std::string OBSTACLE_IMAGE_PATH = "Resources/Sprites/Fogueira.png";


Player* playerWitch;
Obstacle* obstacle1;
Obstacle* obstacle2;
Obstacle* obstacle3;
bool pointArea;


bool InGameState::onEnter()
{
	// Audio
	SoundManager::Instance()->load(ON_ENTER_AUDIO, ON_ENTER_AUDIO_PATH, SoundType::SFX);
	SoundManager::Instance()->playSound(ON_ENTER_AUDIO, 0);
	SoundManager::Instance()->load(BG_AUDIO, BG_AUDIO_PATH, SoundType::MUSIC);
	
	

	// Imagem de fundo
	SDL_FRect bgRect = { 0, 0, 800, 600 };
	StaticImage* bgMenu = new StaticImage(bgRect, BG_IMAGE, BG_IMAGE_PATH);
	m_gameObjects.push_back(bgMenu);


	// Obstaculos 
	SDL_FRect obstacle1Rect = { 800, (rand() % 400) - 400 , 70, 400};
	obstacle1 = new Obstacle (obstacle1Rect, OBSTACLE_IMAGE, OBSTACLE_IMAGE_PATH );
	m_gameObjects.push_back(obstacle1);
	

	SDL_FRect obstacle2Rect = { 1150 ,(rand() % 400) - 400,70, 400};
	obstacle2 = new Obstacle(obstacle2Rect, OBSTACLE_IMAGE, OBSTACLE_IMAGE_PATH);
	m_gameObjects.push_back(obstacle2);


	SDL_FRect obstacle3Rect = { 1500,(rand() % 400) - 400,70, 400};
	obstacle3 = new Obstacle(obstacle3Rect, OBSTACLE_IMAGE, OBSTACLE_IMAGE_PATH);
	m_gameObjects.push_back(obstacle3);

	//Bruxa
	SDL_FRect playerRect = { 200,200,70,70 };
    playerWitch = new Player(playerRect, PLAYER_IMAGE, PLAYER_IMAGE_PATH);
	m_gameObjects.push_back(playerWitch);


	startGame = false;
	GameManager::Instance()->score = 0;
	pointArea = false;


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
	//Start antes da partida
	if (startGame)
	{

		for (int i = 0; i != m_gameObjects.size(); i++)
		{
			m_gameObjects[i]->update();
		}

		if (playerWitch->checkCollision(obstacle1->getObstacleRect1())
			|| playerWitch->checkCollision(obstacle1->getObstacleRect2())
			|| playerWitch->checkCollision(obstacle2->getObstacleRect1())
			|| playerWitch->checkCollision(obstacle2->getObstacleRect2())
			|| playerWitch->checkCollision(obstacle3->getObstacleRect1())
			|| playerWitch->checkCollision(obstacle3->getObstacleRect2()))
		{
			GameManager::Instance()->getStateMachine()->changeState(new GameOverState);
		}
	}
	else
	{
		startGame = isMouseClicked();
		if (startGame)
		{
			SoundManager::Instance()->playMusic(BG_AUDIO, -1);
		}
	}

	checkPoint();
}


bool InGameState::isMouseClicked()
{
	if (InputManager::Instance()->getMouseButtonState(MouseButtons::LEFT))
	{
		return true;
	}
	return false;
}
void InGameState::render()
{
	for (int i = 0; i != m_gameObjects.size(); i++)
		m_gameObjects[i]->draw();
}

string InGameState::getStateID() const
{
	return "InGame";
	
	//return string();
}
void InGameState::checkPoint()
{
	if (playerWitch->checkCollision(obstacle1->getObstaclePointRect())
		|| playerWitch->checkCollision(obstacle2->getObstaclePointRect())
		|| playerWitch->checkCollision(obstacle3->getObstaclePointRect()))
	{
		pointArea = true;
	}

	if (pointArea)
	{
		if (!(playerWitch->checkCollision(obstacle1->getObstaclePointRect())
			|| playerWitch->checkCollision(obstacle2->getObstaclePointRect())
			|| playerWitch->checkCollision(obstacle3->getObstaclePointRect())))
		{
			GameManager::Instance()->score += 1;
			pointArea = false;

			cout << GameManager::Instance()->score << "\n Pontos \n\n";
		}
		
	}
}