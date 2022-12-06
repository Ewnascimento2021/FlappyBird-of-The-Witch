#pragma once
#include <SDL_rect.h>
#include <string>
#include "GameObject.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "TextureManager.h"
#include "InputManager.h"

using namespace std;

class Block : public GameObject
{
public:

	Block(SDL_FRect rect, string textureId, string texturePath);
	virtual void draw();
	virtual void update();
	bool checkCollision(SDL_FRect* objectB);
	virtual void clean();
	bool alive = true;

private:
	SDL_FRect m_blockRect;
};
