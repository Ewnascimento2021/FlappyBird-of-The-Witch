#pragma once

#include <iostream>
#include <vector>
#include "GameStateBase.h"
#include <SDL.h>

using namespace std;

class GameStateMachine
{
public:
	void pushState(GameStateBase* newState);
	void changeState(GameStateBase* newState);
	void popState();

	void update();
	void render();

	GameStateMachine(GameStateBase* newState);
	~GameStateMachine() {};

private:
	// TODO: Mudar para map<key, value>
	vector<GameStateBase*> m_gameStates;
};
