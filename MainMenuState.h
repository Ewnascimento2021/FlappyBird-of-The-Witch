#pragma once

#include <vector>

#include "GameObject.h"
#include "GameStateBase.h"

using namespace std;

class MainMenuState : public GameStateBase
{
	// Inherited via GameStateBase
	virtual void update() override;
	virtual void render() override;
	virtual bool onEnter() override;
	virtual bool onExit() override;
	virtual string getStateID() const override;

public:
	MainMenuState() {};
	~MainMenuState() {};

private:
	static void onMenuPlayButtonClicked();

	static const string s_menuID;
	vector<GameObject*> m_gameObjects;

};
