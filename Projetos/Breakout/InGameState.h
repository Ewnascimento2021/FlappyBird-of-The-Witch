#pragma once
#include <vector>

#include "GameObject.h"
#include "GameStateBase.h"
#include "Block.h"

using namespace std;

class InGameState : public GameStateBase
{
	// Inherited via GameStateBase
	virtual void update() override;
	virtual void render() override;
	virtual bool onEnter() override;
	virtual bool onExit() override;
	virtual string getStateID() const override;


public:
	InGameState() {};
	~InGameState() {};


private:
	bool buttonClicked;
	vector <Block*> brocos;
};

