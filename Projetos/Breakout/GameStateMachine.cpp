#include "GameStateMachine.h"

GameStateMachine::GameStateMachine(GameStateBase* newState)
{
	pushState(newState);
}
void GameStateMachine::pushState(GameStateBase* newState)
{
	m_gameStates.push_back(newState);
	m_gameStates.back()->onEnter();
}
void GameStateMachine::changeState(GameStateBase* newState)
{
	if (m_gameStates.empty()) 
	{
		m_gameStates.push_back(newState);
		return;
	}

	if (m_gameStates.back()->getStateID() == newState->getStateID())
		return;

	m_gameStates.back()->onExit();
	m_gameStates.push_back(newState);
	m_gameStates.back()->onEnter();
}
void GameStateMachine::popState()
{
	if (m_gameStates.empty())
		return;

	delete m_gameStates.back();
	m_gameStates.pop_back();
}
void GameStateMachine::update()
{
	if (!m_gameStates.empty())
		m_gameStates.back()->update();
}
void GameStateMachine::render()
{
	if (!m_gameStates.empty())
		m_gameStates.back()->render();
}
