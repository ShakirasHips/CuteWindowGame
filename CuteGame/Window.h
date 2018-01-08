#pragma once
#include <SDL.h>


class Window
{
private:
	SDL_Window* window;
	int x;
	int y;
	int width;
	int height;
	bool resizeable;
	bool minimized;
	bool grabbed;
public:
	Window(int width, int height);
	~Window();

	void init();
	void update();


	SDL_Window* getWindow();
	int getWidth();
	int getHeight();
	int getXPos() const;
	int getYPos() const;
	bool isMinimized();



};

