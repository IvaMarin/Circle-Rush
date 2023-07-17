#pragma once

class Rotator
{
public:
	float angle;
	float radius;
	float speed;

	int direction;
	float direction_switch_timeout;

	Rotator() = default;
	Rotator(float angle, float radius, float speed, int direction, float direction_switch_timeout)
		: angle(angle), radius(radius), speed(speed), direction(direction), direction_switch_timeout(direction_switch_timeout) {}
};
