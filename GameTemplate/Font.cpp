#include "Font.h"

void Font::draw_number(int number, int x, int y, int step) {
	int current_number = number;
	int i = 0;
	do {
		int digit = current_number % 10;
		switch (digit) {
		case 0:
			draw_zero(x - step * i, y);
			break;
		case 1:
			draw_one(x - step * i, y);
			break;
		case 2:
			draw_two(x - step * i, y);
			break;
		case 3:
			draw_three(x - step * i, y);
			break;
		case 4:
			draw_four(x - step * i, y);
			break;
		case 5:
			draw_five(x - step * i, y);
			break;
		case 6:
			draw_six(x - step * i, y);
			break;
		case 7:
			draw_seven(x - step * i, y);
			break;
		case 8:
			draw_eight(x - step * i, y);
			break;
		case 9:
			draw_nine(x - step * i, y);
			break;
		}
		current_number /= 10;
		i++;
	} while (current_number > 0);
}

void Font::draw_zero(int x, int y) {
	for (int i = 0; i < 3; i++)
	{
		draw_rectangle(x + i * size, y - size, size, size, color);
		draw_rectangle(x + i * size, y + 5 * size, size, size, color);
	}

	for (int i = 0; i < 5; i++)
	{
		draw_rectangle(x - size, y + i * size, size, size, color);
		draw_rectangle(x + 3 * size, y + i * size, size, size, color);
	}
}

void Font::draw_one(int x, int y) {
	for (int i = 0; i < 2; i++)
	{
		draw_rectangle(x + (i - 1) * size, y, size, size, color);
	}

	for (int i = 0; i < 5; i++)
	{
		draw_rectangle(x + (i - 1) * size, y + 5 * size, size, size, color);
	}

	for (int i = 0; i < 6; i++)
	{
		draw_rectangle(x + size, y + (i - 1) * size, size, size, color);
	}
}

void Font::draw_two(int x, int y) {
	for (int i = 0; i < 3; i++)
	{
		draw_rectangle(x + i * size, y - size, size, size, color);
	}

	draw_rectangle(x - size, y, size, size, color);

	for (int i = 0; i < 5; i++)
	{
		draw_rectangle(x - (i - 3) * size, y + i * size, size, size, color);
	}

	for (int i = 0; i < 5; i++)
	{
		draw_rectangle(x + (i - 1) * size, y + 5 * size, size, size, color);
	}
}

void Font::draw_three(int x, int y) {
	for (int i = 0; i < 3; i++)
	{
		draw_rectangle(x + i * size, y - size, size, size, color);
		draw_rectangle(x + i * size, y + 5 * size, size, size, color);
	}

	draw_rectangle(x - size, y, size, size, color);
	draw_rectangle(x - size, y + 4 * size, size, size, color);

	for (int i = 0; i < 2; i++)
	{
		draw_rectangle(x + (i + 1) * size, y + 2 * size, size, size, color);
	}

	for (int i = 0; i < 2; i++)
	{
		draw_rectangle(x + 3 * size, y + i * size, size, size, color);
		draw_rectangle(x + 3 * size, y + (i + 3) * size, size, size, color);
	}
}

void Font::draw_four(int x, int y) {
	for (int i = 0; i < 4; i++)
	{
		draw_rectangle(x + i * size, y + 3 * size, size, size, color);
	}

	for (int i = 0; i < 5; i++)
	{
		draw_rectangle(x - size, y + (i - 1) * size, size, size, color);
		draw_rectangle(x + 2 * size, y + (i + 1) * size, size, size, color);
	}
}

void Font::draw_five(int x, int y) {
	for (int i = 0; i < 5; i++)
	{
		draw_rectangle(x + (i - 1) * size, y - size, size, size, color);
	}

	for (int i = 0; i < 4; i++)
	{
		draw_rectangle(x + (i - 1) * size, y + 2 * size, size, size, color);
		draw_rectangle(x + (i - 1) * size, y + 5 * size, size, size, color);
	}

	for (int i = 0; i < 2; i++)
	{
		draw_rectangle(x - size, y + i * size, size, size, color);
		draw_rectangle(x + 3 * size, y + (i + 3) * size, size, size, color);
	}
}

void Font::draw_six(int x, int y) {
	draw_rectangle(x + 3 * size, y, size, size, color);

	for (int i = 0; i < 3; i++)
	{
		draw_rectangle(x + i * size, y - size, size, size, color);
		draw_rectangle(x + i * size, y + 5 * size, size, size, color);
	}

	for (int i = 0; i < 4; i++)
	{
		draw_rectangle(x + (i - 1) * size, y + 2 * size, size, size, color);
	}

	for (int i = 0; i < 2; i++)
	{
		draw_rectangle(x - size, y + i * size, size, size, color);
		draw_rectangle(x + 3 * size, y + (i + 3) * size, size, size, color);
		draw_rectangle(x - size, y + (i + 3) * size, size, size, color);
	}
}

void Font::draw_seven(int x, int y) {
	for (int i = 0; i < 5; i++)
	{
		draw_rectangle(x + (i - 1) * size, y - size, size, size, color);
	}

	for (int i = 0; i < 3; i++)
	{
		draw_rectangle(x - (i - 3) * size, y + i * size, size, size, color);
	}

	for (int i = 0; i < 3; i++)
	{
		draw_rectangle(x + size, y + (i + 3) * size, size, size, color);
	}
}

void Font::draw_eight(int x, int y) {
	for (int i = 0; i < 3; i++)
	{
		draw_rectangle(x + i * size, y - size, size, size, color);
		draw_rectangle(x + i * size, y + 5 * size, size, size, color);
		draw_rectangle(x + i * size, y + 2 * size, size, size, color);
	}

	for (int i = 0; i < 2; i++)
	{
		draw_rectangle(x - size, y + i * size, size, size, color);
		draw_rectangle(x + 3 * size, y + (i + 3) * size, size, size, color);
		draw_rectangle(x - size, y + (i + 3) * size, size, size, color);
		draw_rectangle(x + 3 * size, y + i * size, size, size, color);
	}
}

void Font::draw_nine(int x, int y) {
	draw_rectangle(x - size, y + 4 * size, size, size, color);

	for (int i = 0; i < 3; i++)
	{
		draw_rectangle(x + i * size, y - size, size, size, color);
		draw_rectangle(x + i * size, y + 5 * size, size, size, color);
	}

	for (int i = 0; i < 4; i++)
	{
		draw_rectangle(x + i * size, y + 2 * size, size, size, color);
	}

	for (int i = 0; i < 2; i++)
	{
		draw_rectangle(x + 3 * size, y + i * size, size, size, color);
		draw_rectangle(x + 3 * size, y + (i + 3) * size, size, size, color);
		draw_rectangle(x - size, y - (i - 1) * size, size, size, color);
	}
}
