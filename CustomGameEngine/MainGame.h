#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>

class MainGame
{
public:
	MainGame();
	~MainGame();

	void RunGame();

private:
	void InitializeSystems();

	SDL_Window * _window;
	int _screenWidth;
	int _screenHeight;
};

