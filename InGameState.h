#pragma once

#include <vector>

#include "GameObject.h"
#include "GameStateBase.h"

using namespace std;


class InGameState : public GameStateBase
{
	virtual void update() override;
	virtual void render() override;
	virtual bool onEnter() override;
	virtual bool onExit() override;
	virtual string getStateID() const override;
	bool isMouseClicked();
public:
	InGameState() {};
	~InGameState() {};
	void checkPoint();

private:
	static const string s_menuID;
	vector<GameObject*> m_gameObjects;
	bool startGame;
};

