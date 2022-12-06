#pragma once

#include "GameObject.h"

using namespace std;

class TextBox : public GameObject
{
public:
	TextBox(SDL_FRect rect, string fontId, string textureId, string fontPath, int size, string initialMsg, SDL_Color color);

	virtual void draw();
	void updateTexture(string fontId, string messageId, string msg, SDL_Color color, SDL_FRect position);
	virtual void clean();
	virtual void update();
	void setAngle(int angle) { m_angle = angle; }
	int getAngle() { return m_angle; }

private:
	~TextBox() {};
	SDL_Surface* m_msgSurface;
	int m_angle = 0;

};

