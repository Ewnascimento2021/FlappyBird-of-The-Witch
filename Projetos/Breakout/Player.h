#pragma once

#include <SDL_rect.h>
#include <string>
#include "GameObject.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "TextureManager.h"
#include "InputManager.h"

using namespace std;


class Player : public GameObject
{
public:
	Player(SDL_FRect rect, string textureId, string texturePath);

	virtual void draw();
	virtual void update();
	virtual void clean();
	bool checkCollision(SDL_FRect* obstacles);
	SDL_FRect* getPlayerRect() { return &m_playerRect; }

private:
	SDL_FRect m_playerRect;
	void move();
	int m_speed = 10;
	int m_direction = 0;
};