#pragma once

#include <SDL_rect.h>
#include <string>
#include "GameObject.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "TextureManager.h"
#include "InputManager.h"

using namespace std;


class Ball : public GameObject
{
public:
	Ball(SDL_FRect rect, string textureId, string texturePath);

	virtual void draw();
	virtual void update();
	virtual void clean();
	SDL_FRect* getBall() { return &m_ballRect; }
	void setRectX(int posX) { m_ballRect.x = posX; }
	void setRectY(int posY) { m_ballRect.y = posY; }
	void invertBall() { m_speedX *= -1; }
	void invertBallY() { m_speedY *= -1; }
	int getRectX() { return m_ballRect.x; }
	int getRectY() { return m_ballRect.y; }

private:
	SDL_FRect m_ballRect;
	void move();
	int m_speedX = 10;
	int m_speedY = 10;
};

