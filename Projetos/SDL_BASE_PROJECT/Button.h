#pragma once

#include <SDL_rect.h>
#include <string>
#include "GameObject.h"
using namespace std;
class Button : public GameObject
{
public:
	Button(SDL_FRect rect, string textureId, string texturePath, string SFXId, string SFXPath, void (*callback)());

	virtual void draw();
	virtual void update();
	virtual void clean();

private:
	enum states
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};
	void(*m_callback)();
	bool isMouseOverButton();
	void onMouseEnterButton();
	void onMouseOverButton();
	void onMouseExitButton();
	void onMouseClickButton();
	bool m_buttonClicked;
	bool m_mouseIsOver = false;
	string sfxId;
};

