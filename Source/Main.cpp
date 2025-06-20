#include "../Headers/SDLFirstWindow.h"
#include "../Headers/SDLImageOpen.h"

int main(int argc, char* args[])
{
	SDLImageOpen* sdlProg = new SDLImageOpen();
	sdlProg->Run();
	return 0;
}