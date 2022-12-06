#include "Button.h"
#include "TextureManager.h"
#include "InputManager.h"
#include "SoundManager.h"

const std::string BTN_CLICK = "btnClick";
const std::string BTN_CLICK_PATH = "Resources/Audio/btnClick.wav";

Button::Button(SDL_FRect rect, string textureId, string texturePath, void(*callback)()) : GameObject(rect, textureId)
{
	TextureManager::Instance()->load(textureId, texturePath);
	SoundManager::Instance()->load(BTN_CLICK,BTN_CLICK_PATH, SoundType::SFX);

	m_callback = callback;
	m_currentFrame = MOUSE_OUT;
}

void Button::draw()
{
	TextureManager::Instance()->drawframe(m_textureID, &m_rect, m_currentRow, m_currentFrame);
}

void Button::update()
{
	if (isMouseOverButton())
	{
		if (!m_mouseIsOver)
		{
			onMouseEnterButton();
		}
		else
		{
			onMouseOverButton();
		}
	}
	else if(m_mouseIsOver)
	{
		onMouseExitButton();
	}
}

void Button::clean()
{
	TextureManager::Instance()->clearFromTextureMap(m_textureID);
	delete this;
}

void Button::onMouseEnterButton()
{
	m_currentFrame = MOUSE_OVER;
	m_mouseIsOver = true;
}

void Button::onMouseOverButton()
{
	if (InputManager::Instance()->getMouseButtonState(MouseButtons::LEFT))
	{
		onMouseClickButton();
	}
	else
	{
		m_buttonClicked = false;
		m_currentFrame = MOUSE_OVER;
	}
}

void Button::onMouseExitButton()
{
	m_currentFrame = MOUSE_OUT;
	m_mouseIsOver = false;
	m_buttonClicked = false;
}

void Button::onMouseClickButton()
{
	if (m_buttonClicked)
		return;

	SoundManager::Instance()->playSound(BTN_CLICK, 0);
	m_currentFrame = CLICKED;
	m_buttonClicked = true;

	if(m_callback != NULL)
		m_callback();
}

bool Button::isMouseOverButton()
{
	Vector2 mousePosition = InputManager::Instance()->getMousePosition();
	if (mousePosition.x > m_rect.x &&
		mousePosition.x < (m_rect.x + m_rect.w) &&
		mousePosition.y > m_rect.y &&
		mousePosition.y < (m_rect.y + m_rect.h))
	{
		return true;
	}

	return false;
}
