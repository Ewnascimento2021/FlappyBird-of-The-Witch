#pragma once

#include <SDL_rect.h>
#include <string>
#include "GameObject.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "TextureManager.h"


using namespace std;


class Player : public GameObject
{
public:
	Player (SDL_FRect rect, string textureId, string texturePath);

	virtual void draw();
	virtual void update();
	virtual void clean();
	void jump();
	bool checkCollision(SDL_FRect* obstacles);


	SDL_FRect* getPlayerRect() { return &m_playerRect; }

private:
	SDL_FRect m_playerRect;
	void move();
	int g = 1;
	int m_maxSpeed = 15;
	int jumpForce = 0;
	int v = 0;
	int vo = 0;
	int points = 0;
	int t = 0;

	

	bool isMouseClicked();
	void onMouseClick();
	bool k_buttonClicked;
};