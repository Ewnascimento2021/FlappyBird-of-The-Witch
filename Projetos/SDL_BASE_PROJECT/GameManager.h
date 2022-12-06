#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "GameObject.h"
#include "GameStateMachine.h"
#include "TextureManager.h"
#include "InputManager.h"
#include "TTFLoader.h"

using namespace std;

class GameManager
{
public:
	static GameManager* Instance() 
	{
		if (s_instance == NULL)
		{
			s_instance = new GameManager();
		}
		return s_instance;
	}

	bool init(const char* title, int width, int height, bool fullscreen);
	void handleInputEvents();
	void update();
	void render();
	void clearMemory();
	void quit();
	
	bool isRunning() { return m_isRunning; }
	SDL_Renderer* getRenderer() const { return m_renderer; }

	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }
	bool startButtonClicked;
private:
	GameManager() {};
	~GameManager() {};

	SDL_Window* m_window = NULL;
	SDL_Renderer* m_renderer = NULL;

	bool m_isRunning = false;
	
	GameStateMachine* m_pGameStateMachine = NULL;

	static GameManager* s_instance;
};
