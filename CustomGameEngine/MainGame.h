#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>

enum class GAMESTATE {
	PLAY,
	EXIT
};

class MainGame
{
public:
	MainGame();
	~MainGame();

	void RunGame();

private:
	void InitializeSystems();
	void GameLoop();
	void ProcessInput();

	SDL_Window * _window;
	int _screenWidth;
	int _screenHeight;
	GAMESTATE _gameState;
};

