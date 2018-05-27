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

void MainGame::Failure(std::string str)
{
	std::cout << str << std::endl;
	
	// Quit SDL
	SDL_Quit();
	
	// exit
	exit(1);
}

void MainGame::InitializeSystems() 
{
	// Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) // 0 is success
	{
		SDL_Log("Unable to initialize SDL: %s\n", SDL_GetError());
	}
	

	// Create a window
	_window = SDL_CreateWindow("Game Engine Test",
				SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED,
				_screenWidth,
				_screenHeight,
				SDL_WINDOW_OPENGL);

	if (_window == nullptr)
	{
		Failure("SDL Window could not be created!");
	}

	// Create OpenGL context
	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if (glContext == nullptr)
	{
		Failure("SDL Context could not be created!");
	}

	// Initialize GLEW
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		SDL_Log("Glew could not be initalized: %s\n", glewGetErrorString(err));
	}
	SDL_Log("Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
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
		case SDL_MOUSEMOTION:
			std::cout << evt.motion.x << " " << evt.motion.y << std::endl;
		default:
			break;
		}
	}
}