#pragma once

#include <string>

using namespace std;

class GameStateBase
{
public:
	virtual void update() = NULL;
	virtual void render() = NULL;

	virtual bool onEnter() = NULL;
	virtual bool onExit() = NULL;

	virtual string getStateID() const = NULL;
};