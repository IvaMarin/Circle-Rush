#pragma once

#include "Painter.h"

class Font
{
private:
	int size;
	uint32_t color;

public:
	Font() = default;

	Font(int size, uint32_t color) : size(size), color(color) {}

	void draw_number(int digit, int x, int y, int step);

	void draw_zero(int x, int y);
	void draw_one(int x, int y);
	void draw_two(int x, int y);
	void draw_three(int x, int y);
	void draw_four(int x, int y);
	void draw_five(int x, int y);
	void draw_six(int x, int y);
	void draw_seven(int x, int y);
	void draw_eight(int x, int y);
	void draw_nine(int x, int y);
};
