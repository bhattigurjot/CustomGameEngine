#include "MainGame.h"



MainGame::MainGame()
	:_window(nullptr),
	_screenWidth(800),
	_screenHeight(600)
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
}