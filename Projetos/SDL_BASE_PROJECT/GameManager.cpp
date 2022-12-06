#include "GameManager.h"

#include "TestMenuState.h"

GameManager* GameManager::s_instance = NULL;

bool GameManager::init(const char* title, int width, int height, bool fullscreen) {

	int flags = 0;

	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		cout << "FAIL TO INIT SDL\n";
		return false;
	}

	m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
	if (m_window == 0) {
		cout << "FAIL TO CREATE WINDOW\n";
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
	if (m_renderer == 0) {
		cout << "FAIL TO CREATE RENDERER\n";
		return false;
	}

	//TODO: Criar o TextManager para cuidar dos textos dentro do jogo
	if (TTF_Init() == -1)
	{
		cout << "FAIL TO INIT TTF\n";
		return false;
	}

	m_isRunning = true;

	m_pGameStateMachine = new GameStateMachine(new TestMenuState());
	
	return true;
}
void GameManager::handleInputEvents() 
{
	InputManager::Instance()->update();
}
void GameManager::update() {
	m_pGameStateMachine->update();
}
void GameManager::render() {
	SDL_SetRenderDrawColor(m_renderer, 0, 136, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(m_renderer);
	m_pGameStateMachine->render();
	SDL_RenderPresent(m_renderer);
}
void GameManager::clearMemory() {
	std::cout << "cleaning the game\n";	
	TTF_Quit();
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
}
void GameManager::quit()
{
	m_isRunning = false;
}
