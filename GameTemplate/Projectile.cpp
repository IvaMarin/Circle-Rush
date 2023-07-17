#include "Projectile.h"

bool Projectile::is_colliding_with_circle(float x_center, float y_center, float radius) {
	float half_width = width / 2;
	float half_height = height / 2;

	if ((x + half_width - x_center) * (x + half_width - x_center) +
		(y + half_height - y_center) * (y + half_height - y_center) <= radius * radius) {
		return true;
	}

	if ((x - half_width - x_center) * (x - half_width - x_center) +
		(y - half_height - y_center) * (y - half_height - y_center) <= radius * radius) {
		return true;
	}

	if ((x + half_width - x_center) * (x + half_width - x_center) +
		(y - half_height - y_center) * (y - half_height - y_center) <= radius * radius) {
		return true;
	}

	if ((x - half_width - x_center) * (x - half_width - x_center) +
		(y + half_height - y_center) * (y + half_height - y_center) <= radius * radius) {
		return true;
	}

	return false;
}
