#include "MainGame.h"

MainGame::MainGame()
	:_window(nullptr),
	_screenWidth(800),
	_screenHeight(600),
	_gameState(GAMESTATE::PLAY)
{
}


MainGame::~MainGame()
{
	// Destroy the window
	SDL_DestroyWindow(_window);
	
	// Quit SDL
	SDL_Quit();
}


void MainGame::InitializeSystems() 
{
	// Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	// Create a window
	_window = SDL_CreateWindow("Game Engine Test",
				SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED,
				_screenWidth,
				_screenHeight,
				SDL_WINDOW_OPENGL);
}

void MainGame::RunGame()
{
	InitializeSystems();
	GameLoop();
}

void MainGame::GameLoop()
{
	while (_gameState != GAMESTATE::EXIT)
	{
		ProcessInput();
	}
}

void MainGame::ProcessInput()
{
	SDL_Event evt;
	while(SDL_PollEvent(&evt))
	{
		switch (evt.type)
		{
		case SDL_QUIT:
			_gameState = GAMESTATE::EXIT;
			break;
		default:
			break;
		}
	}
}