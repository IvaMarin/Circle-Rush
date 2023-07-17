#pragma once

#include "Engine.h"

#include <stdlib.h>
#include <math.h>

class Projectile
{
public:
	float x;
	float y;

	float width;
	float height;

	float speed;

	bool is_bad;

	float starting_position_y;
	float destination_position_y;
	float direction_length;

	static float timer;

	Projectile() = default;

	Projectile(float x, float y, float width, float height, float speed, bool is_bad)
		: x(x), y(y), width(width), height(height), speed(speed), is_bad(is_bad)
	{
		starting_position_y = y;
		destination_position_y = (float)(rand() % SCREEN_HEIGHT);

		direction_length = sqrtf(SCREEN_WIDTH * SCREEN_WIDTH +
			(destination_position_y - starting_position_y) * (destination_position_y - starting_position_y));
	}

	bool is_colliding_with_circle(float x_center, float y_center, float radius);
};
