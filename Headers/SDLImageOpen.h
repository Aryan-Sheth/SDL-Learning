#pragma once
#include <SDL.h>
#include <stdio.h>

class SDLImageOpen
{
private:

	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	SDL_Window* Window = NULL;
	SDL_Surface* ScreenSurface = NULL;
	SDL_Surface* HelloWorld = NULL;

	bool Init();
	bool LoadMedia();
	void close();

public:
	void Run();
};

