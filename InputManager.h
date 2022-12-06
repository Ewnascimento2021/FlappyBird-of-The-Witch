#pragma once

#include <SDL.h>
#include <vector>

#include "Vector2.h"

using namespace std;

enum class MouseButtons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputManager
{
public:
	static InputManager* Instance()
	{
		if (s_instance == 0)
			s_instance = new InputManager();

		return s_instance;
	}

	void update();
	void clean();

	bool getMouseButtonState(MouseButtons mouseButton)
	{
		return m_mouseButtonStates[(int)mouseButton];
	}

	Vector2 getMousePosition()
	{
		return m_mousePosition;
	}

	// keyboard events
	bool isKeyDown(SDL_Scancode key) const;

private:
	InputManager();

	Vector2 m_mousePosition;
	const Uint8* m_keystates = 0;
	vector<bool> m_mouseButtonStates;

	//functions that handles the mouse events
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);

	static InputManager* s_instance;
};

