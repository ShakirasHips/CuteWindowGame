#include <iostream>
#include <SDL.h>
#include <thread>
#include "Window.h"


#define log(x) std::cout << x << std::endl

void thread2(Window &window, SDL_Event &e)
{
	for (;;)
	{
		window.update();
		std::cout << window.getYPos() << " , " << window.getXPos() << std::endl;
		if (e.type == SDL_QUIT)
		{
			break;
		}

	}
}

int main(int argc, char** argv)
{
	Window window(800, 600);
	window.init();
	SDL_Event e;
	std::thread th2(thread2, std::ref(window), std::ref(e));
	for (;;)
	{
		SDL_PollEvent(&e);
		if (e.type == SDL_QUIT)
		{
			break;
		}
	}
	th2.join();

	return 0;
}