// FirstRPG.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main(int argc, char* argv[])
{
	bool quit = false;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = NULL;
	window = SDL_CreateWindow("My First RPG!", 100, 100, 600, 500, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		std::cout << "Window couldn't be created" << std::endl;
		return 0;
	}

	SDL_Renderer* renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Event* mainEvent = new SDL_Event();

	SDL_Texture* grass_image = NULL;
	grass_image = IMG_LoadTexture(renderer, "data/grass.bmp");

	if (grass_image == NULL)
	{
		std::cout << "Couldn't load grass image!" << std::endl;
	}

	SDL_Rect grass_rect;
	grass_rect.x = 0;
	grass_rect.y = 0;
	grass_rect.w = 600;
	grass_rect.h = 500;


	SDL_Texture* bob_image = NULL;
	bob_image = IMG_LoadTexture(renderer, "data/bob.png");

	if (bob_image == NULL)
	{
		std::cout << "Couldn't load Bob image!" << std::endl;
	}

	SDL_Rect bob_rect;
	bob_rect.x = 300;
	bob_rect.y = 250;
	bob_rect.w = 100;
	bob_rect.h = 180;

	while (!quit && mainEvent->type != SDL_QUIT)
	{
		SDL_PollEvent(mainEvent);

		SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, grass_image, NULL, &grass_rect);
		SDL_RenderCopy(renderer, bob_image, NULL, &bob_rect);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(grass_image);
	SDL_DestroyTexture(bob_image);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;

	return 0;
}

