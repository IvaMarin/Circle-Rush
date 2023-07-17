#include "Painter.h"

void paint_pixel(int x, int y, uint32_t color) {
	buffer[y][x] = color;
}

void draw_circle(int x_center, int y_center, int radius, uint32_t color) {
	for (int x = x_center - radius; x <= x_center + radius; x++) {
		for (int y = y_center - radius; y <= y_center + radius; y++) {

			if (x >= SCREEN_WIDTH || x < 0 || y >= SCREEN_HEIGHT || y < 0) {
				continue;
			}

			if (((x - x_center) * (x - x_center) + (y - y_center) * (y - y_center)) <= radius * radius) {
				paint_pixel(x, y, color);
				continue;
			}
		}
	}
}

void draw_rectangle(int x_center, int y_center, int width, int height, uint32_t color) {
	int half_width = width / 2;
	int half_height = height / 2;

	for (int x = x_center - half_width; x <= x_center + half_width; x++) {
		for (int y = y_center - half_height; y <= y_center + half_height; y++) {

			if (x >= SCREEN_WIDTH || x < 0 || y >= SCREEN_HEIGHT || y < 0) {
				continue;
			}

			paint_pixel(x, y, color);
		}
	}
}
