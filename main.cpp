#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

#include "GameManager.h"

using namespace std;

#pragma region VARIABLES
	//Game window setup
	const char GAME_TITLE[32] = "BRUXAS A SOLTA";
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	const bool IS_FULLSCREEN = false;

	//GAME FPS setup
	const int FPS = 60;
	const int DELAY_TIME = 1000.0f / FPS;
#pragma endregion

int main(int argc, char* args[])
{
	//Usado para controlar o FPS do jogo
	Uint32 frameStart, frameTime;

	if (GameManager::Instance()->init(GAME_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT, IS_FULLSCREEN)) {
		cout << "GAME INIT SUCCESS\n";

		while (GameManager::Instance()->isRunning())
		{
			frameStart = SDL_GetTicks();

			GameManager::Instance()->handleInputEvents();
			GameManager::Instance()->update();
			GameManager::Instance()->render();

			frameTime = SDL_GetTicks() - frameStart;
			if (frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
		}
	}
	else {
		cout << "GAME INIT FAIL - " << SDL_GetError() << "\n";
		return -1;
	}

	cout << "game closing...\n";
	GameManager::Instance()->clearMemory();
	return 0;
}
