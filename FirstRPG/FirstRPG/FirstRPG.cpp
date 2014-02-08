// FirstRPG.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main(int argc, char* argv[])
{
	bool quit = false;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = NULL;
	window = SDL_CreateWindow("My First RPG!", 100, 100, 600, 400, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		std::cout << "Window couldn't be created" << std::endl;
		return 0;
	}

	SDL_Renderer* renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Event* mainEvent = new SDL_Event();

	while (!quit && mainEvent->type != SDL_QUIT)
	{
		SDL_PollEvent(mainEvent);

		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;

	return 0;
}

