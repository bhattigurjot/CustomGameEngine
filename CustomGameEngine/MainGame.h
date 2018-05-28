#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>

#include <string>
#include <iostream>

#include "Sprite.h"

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
	void Draw();
	void Failure(std::string);

	SDL_Window * _window;
	SDL_GLContext _gl_context;
	int _screenWidth;
	int _screenHeight;
	GAMESTATE _gameState;

	Sprite _sprite;
};

