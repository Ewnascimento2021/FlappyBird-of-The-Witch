#include "InputManager.h"
#include "GameManager.h"

InputManager* InputManager::s_instance = NULL;

bool InputManager::isKeyDown(SDL_Scancode key) const
{
	if (m_keystates[key] == 1)
		return true;

	return false;
}

InputManager::InputManager() : m_mousePosition(Vector2{ 0, 0 })
{
	for (int i = 0; i < 3; i++)
		m_mouseButtonStates.push_back(false);
}

void InputManager::update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			GameManager::Instance()->quit();
			break;
		case SDL_MOUSEBUTTONDOWN:
			onMouseButtonDown(event);
			break;
		case SDL_MOUSEBUTTONUP:
			onMouseButtonUp(event);
			break;
		case SDL_MOUSEMOTION:
			onMouseMove(event);
			break;
		default:
			break;
		}
	}
}

void InputManager::clean()
{
}

void InputManager::onMouseMove(SDL_Event& event)
{
	m_mousePosition.x = event.motion.x;
	m_mousePosition.y = event.motion.y;
}

void InputManager::onMouseButtonDown(SDL_Event& event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
		m_mouseButtonStates[(int)MouseButtons::LEFT] = true;

	if (event.button.button == SDL_BUTTON_MIDDLE)
		m_mouseButtonStates[(int)MouseButtons::MIDDLE] = true;

	if (event.button.button == SDL_BUTTON_RIGHT)
		m_mouseButtonStates[(int)MouseButtons::RIGHT] = true;
}

void InputManager::onMouseButtonUp(SDL_Event& event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
		m_mouseButtonStates[(int)MouseButtons::LEFT] = false;

	if (event.button.button == SDL_BUTTON_MIDDLE)
		m_mouseButtonStates[(int)MouseButtons::MIDDLE] = false;

	if (event.button.button == SDL_BUTTON_RIGHT)
		m_mouseButtonStates[(int)MouseButtons::RIGHT] = false;
}


