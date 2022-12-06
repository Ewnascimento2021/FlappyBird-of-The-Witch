#pragma once

#include "GameObject.h"

using namespace std;

class StaticImage : public GameObject
{
public:
	StaticImage(SDL_FRect rect, string textureId, string texturePath);

	virtual void draw();
	virtual void update();
	virtual void clean();

private:
	~StaticImage() {};
};