#pragma once
#ifndef TETRIS_H_
#define TETRIS_H_

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <ctime>

class Tetris
{
public:
	Tetris()
	{
	}
	~Tetris()
	{
	}

	void setCurrentTime(Uint32 t)
	{
		currentTime = t;
	}

	bool isrunning()
	{
		return running;
	}

	bool isvalid();

	bool init(const char *title);
	void nextTetrimino();
	void handleEvents();
	void setRectPos(SDL_Rect &rect, int x = 0, int y = 0, int w = BlockW, int h = BlockH);
	void moveRectPos(SDL_Rect &rect, int x, int y);
	void gameplay();
	void updateRender();
	void clean();

private:
	enum
	{
		ScreenW = 600,
		ScreenH = 920
	};
	enum
	{
		BlockW = 36,
		BlockH = 36
	};
	enum
	{
		Lines = 20,
		Cols = 10
	};
	SDL_Window *window = NULL;
	SDL_Renderer *render = NULL;
	SDL_Texture *background = NULL, *blocks = NULL;
	SDL_Rect srcR = {0, 0, BlockW, BlockH}, destR = {0, 0, BlockW, BlockH};

	bool running = false;
	int field[Lines][Cols] = {0};
	static const int figures[7][4];
	struct Point
	{
		int x, y;
	} items[4], backup[4];
	int color = 1;
	int dx = 0;
	bool rotate = false;
	unsigned int delay = 300;
	Uint32 startTime = 0, currentTime = 0;
};

#endif // !TETRIS_H_
