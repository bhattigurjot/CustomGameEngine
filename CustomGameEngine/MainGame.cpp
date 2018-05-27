#include "MainGame.h"

MainGame::MainGame()
	:_window(nullptr),
	_gl_context(0),
	_screenWidth(800),
	_screenHeight(600),
	_gameState(GAMESTATE::PLAY)
{
}


MainGame::~MainGame()
{
	// Delete context if global
	SDL_GL_DeleteContext(_gl_context);

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
	_gl_context = SDL_GL_CreateContext(_window);
	if (_gl_context == nullptr)
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

	// Enable double buffer swapping
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// Set the background color to clear
	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
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
		Draw();
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

void MainGame::Draw()
{
	// Clear value for depth buffer
	glClearDepth(1.0);
	// Clear the color buffer bit and depth buffer bit
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	// Draw stuff here

	// Swap the buffers for the window
	SDL_GL_SwapWindow(_window);
}