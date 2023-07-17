#pragma once

#include "Engine.h"

enum COLOR {
	BLACK = 0,
	WHITE = 2147483647,
	GREY = 123123123,
	PURPLE = 192123123,
};

void paint_pixel(int x, int y, uint32_t color);

void draw_circle(int x_center, int y_center, int radius, uint32_t color);
void draw_rectangle(int x_center, int y_center, int width, int height, uint32_t color);
