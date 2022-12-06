#pragma once

#include <vector>

#include "GameObject.h"
#include "GameStateBase.h"

using namespace std;

class TestMenuState : public GameStateBase
{
	// Inherited via GameStateBase
	virtual void update() override;
	virtual void render() override;
	virtual bool onEnter() override;
	virtual bool onExit() override;
	virtual string getStateID() const override;

public:
	TestMenuState() {};
	~TestMenuState() {};

private:
	int skySpeed1 = 40;
	int skySpeed2 = 20;
	int skySpeed3 = 10;
	int skySpeed4 = 5;
	bool buttonClicked;
	static void onMenuPlayButtonClicked();
};
