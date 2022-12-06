#pragma once

#include <SDL_rect.h>
#include "GameObject.h"
#include "TextureManager.h"



using namespace std;


class Obstacle : public GameObject
{
public:
	Obstacle(SDL_FRect rect, string textureId, string texturePath);

	virtual void draw();
	virtual void update();
	virtual void clean();

	SDL_FRect* getObstacleRect1() {return &m_obstacleRect1;}
	SDL_FRect* getObstacleRect2() {return &m_obstacleRect2;}
	SDL_FRect* getObstaclePointRect() {return &m_obstaclePointRect;}

private:
	SDL_FRect m_obstacleRect1;
	SDL_FRect m_obstacleRect2;
	SDL_FRect m_obstaclePointRect;
	int pointRectHeight=200;
	int m_speed = -3;

	void move();
};

