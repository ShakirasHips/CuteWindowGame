#include "Window.h"

Window::Window(int width, int height): width(width), height(height)
{
}

//TODO: may not have to reinit and destoy sdl between windows
Window::~Window()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Window::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Memes", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

}

void Window::update()
{
	SDL_GetWindowSize(window, &width, &height);
	SDL_GetWindowPosition(window, &x, &y);
	minimized = SDL_GetWindowFlags(window) & SDL_WINDOW_MINIMIZED;

}

SDL_Window * Window::getWindow()
{
	return window;
}

int Window::getWidth()
{
	return width;
}

int Window::getHeight()
{
	return height;
}

int Window::getXPos() const
{
	return x;
}

int Window::getYPos() const
{
	return y;
}

bool Window::isMinimized()
{
	return minimized;
}
