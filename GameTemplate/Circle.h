#pragma once

class Circle
{
public:
	float x;
	float y;
	float radius;

	Circle() = default;
	Circle(float x, float y, float radius) : x(x), y(y), radius(radius) {}
};
