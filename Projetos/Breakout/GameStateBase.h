#pragma once
#include <vector>
#include <string>
#include "GameObject.h"

using namespace std;

class GameStateBase
{
public:
	virtual void update() = NULL;
	virtual void render() = NULL;

	virtual bool onEnter() = NULL;
	virtual bool onExit() = NULL;

	virtual string getStateID() const = NULL;

protected:
	const string s_stateID;

	vector<GameObject*> m_gameObjects;
};