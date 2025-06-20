#include "../Headers/SDLImageOpen.h"

bool SDLImageOpen::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	Window = SDL_CreateWindow("Image Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (Window == NULL)
	{
		printf("Window Failed to Open! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	ScreenSurface = SDL_GetWindowSurface(Window);
	
	return true;
}

bool SDLImageOpen::LoadMedia()
{
	HelloWorld = SDL_LoadBMP("Resources/hello_world.bmp");
	if (HelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "hello_world.bmp", SDL_GetError());
		return false;
	}

	return true;
}

void SDLImageOpen::close()
{
	SDL_FreeSurface(HelloWorld);
	HelloWorld = NULL;

	SDL_DestroyWindow(Window);
	Window = NULL;

	SDL_Quit();
}

void SDLImageOpen::Run()
{
	if (!Init())
	{
		printf("Failed to initialize!\n");
		return;
	}

	if (!LoadMedia())
	{
		printf("Failed to load media!\n");
		return;
	}

	SDL_BlitSurface(HelloWorld, NULL, ScreenSurface, NULL);
	SDL_UpdateWindowSurface(Window);

	SDL_Event e;
	bool quit = false;

	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}

	close();
}
