#pragma once

#include <string>
#include <SDL.h>

#include "Vector2.h"

using namespace std;

class GameObject
{
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;

	SDL_FRect getRect() { return m_rect; }
	SDL_FRect setRect(SDL_FRect value) { m_rect = value; }

	Vector2 getPosition() { return Vector2{ m_rect.x, m_rect.y }; }
	void setPosition(Vector2 value)
	{
		m_rect.x = value.x;
		m_rect.y = value.y;
	}

	Vector2 getDimension() { return Vector2{ m_rect.w, m_rect.h }; }
	void setDimension(Vector2 value)
	{
		m_rect.w = value.x;
		m_rect.h = value.y;
	}

	string getTextureID() { return m_textureID; }

protected:
	GameObject(SDL_FRect rect, string textureID) :
		m_rect(rect),
		m_textureID(textureID) {};

	virtual~GameObject() {};

	//Usado para animação
	int m_currentRow = 0;
	int m_currentFrame = 0;
	bool isDead = false;

	SDL_FRect m_rect;
	string m_textureID;
};