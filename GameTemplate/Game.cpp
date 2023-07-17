#include "Engine.h"
#include "FONT.h"
#include "Circle.h"
#include "Rotator.h"
#include "Projectile.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include <vector>


const int CENTER_X = SCREEN_WIDTH / 2;
const int CENTER_Y = SCREEN_HEIGHT / 2;
const int CIRCLES_COUNT = 2;

int SCORE;
Font FONT;
Rotator ROTATOR;

float Projectile::timer;

std::vector<Projectile> PROJECTILES;
Circle CIRCLES[CIRCLES_COUNT];


//  is_key_pressed(int button_vk_code) - check if a key is pressed,
//                                       use keycodes (VK_SPACE, VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN, 'A', 'B')
//
//  get_cursor_x(), get_cursor_y() - get mouse cursor position
//  is_mouse_button_pressed(int button) - check if mouse button is pressed (0 - left button, 1 - right button)
//  clear_buffer() - set all pixels in buffer to 'black'
//  is_window_active() - returns true if window is active
//  schedule_quit_game() - quit game after act()


// initialize game data in this function
void initialize() {
	srand((unsigned int)time(NULL));

	SCORE = 0;
	FONT = Font(10, PURPLE);

	ROTATOR = Rotator(0.f, 200.f, 3.f, 1, 0.2f);

	for (size_t i = 0; i < CIRCLES_COUNT; i++)
	{
		CIRCLES[i] = Circle((float)CENTER_X, (float)CENTER_Y, 40.f);
	}

	Projectile::timer = 0.f;
}


void handle_projectiles(float dt) {
	if (Projectile::timer >= 0.f) {
		Projectile::timer -= dt;
	}

	if (Projectile::timer <= 0.f) {
		PROJECTILES.push_back(Projectile((float)SCREEN_WIDTH, (float)(rand() % SCREEN_HEIGHT), 50.f, 50.f, 200.f, rand() % 2));
		Projectile::timer = 2.f;
	}

	for (size_t i = 0; i < PROJECTILES.size(); i++)
	{
		PROJECTILES[i].x -= (SCREEN_WIDTH / PROJECTILES[i].direction_length) * PROJECTILES[i].speed * dt;
		PROJECTILES[i].y += ((PROJECTILES[i].destination_position_y - PROJECTILES[i].starting_position_y) /
			PROJECTILES[i].direction_length) * PROJECTILES[i].speed * dt;

		if (PROJECTILES[i].x < PROJECTILES[i].width / 2) {
			PROJECTILES.erase(PROJECTILES.begin() + i);
			continue;
		}

		if (!(PROJECTILES[i].is_colliding_with_circle(CIRCLES[0].x, CIRCLES[0].y, CIRCLES[0].radius) ||
			PROJECTILES[i].is_colliding_with_circle(CIRCLES[1].x, CIRCLES[1].y, CIRCLES[1].radius))) {
			continue;
		}

		if (PROJECTILES[i].is_bad) {
			SCORE = 0;
		}
		else {
			SCORE++;
		}

		PROJECTILES.erase(PROJECTILES.begin() + i);
	}
}

void handle_rotating_circles(float dt) {
	if (ROTATOR.direction_switch_timeout >= 0.f) {
		ROTATOR.direction_switch_timeout -= dt;
	}

	if (is_key_pressed(VK_SPACE) && ROTATOR.direction_switch_timeout <= 0.f) {
		ROTATOR.direction *= -1;
		ROTATOR.direction_switch_timeout = 0.2f;
	}

	ROTATOR.angle += ROTATOR.speed * ROTATOR.direction * dt;
	if (ROTATOR.angle > 360.f || ROTATOR.angle < -360.f) {
		ROTATOR.angle = 0.f;
	}

	int position = 1;
	for (size_t i = 0; i < CIRCLES_COUNT; i++)
	{
		CIRCLES[i].x = CENTER_X + position * cosf(ROTATOR.angle) * ROTATOR.radius;
		CIRCLES[i].y = CENTER_Y + position * sinf(ROTATOR.angle) * ROTATOR.radius;
		position *= -1;
	}
}

// this function is called to update game data,
// dt - time elapsed since the previous update (in seconds)
void act(float dt)
{
	if (is_key_pressed(VK_ESCAPE))
		schedule_quit_game();

	handle_rotating_circles(dt);
	handle_projectiles(dt);
}


void draw_projectiles() {
	for (size_t i = 0; i < PROJECTILES.size(); i++)
	{
		if (PROJECTILES[i].is_bad) {
			draw_rectangle((int)PROJECTILES[i].x, (int)PROJECTILES[i].y, (int)PROJECTILES[i].width, (int)PROJECTILES[i].height,
				BLACK);
		}
		else {
			draw_rectangle((int)PROJECTILES[i].x, (int)PROJECTILES[i].y, (int)PROJECTILES[i].width, (int)PROJECTILES[i].height,
				WHITE);
		}
	}
}

// fill buffer in this function
// uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH] - is an array of 32-bit colors (8 bits per R, G, B)
void draw() {
	// clear backbuffer
	memset(buffer, GREY, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(uint32_t));

	draw_circle(CENTER_X, CENTER_Y, (int)ROTATOR.radius, PURPLE);

	for (size_t i = 0; i < CIRCLES_COUNT; i++)
	{
		draw_circle((int)CIRCLES[i].x, (int)CIRCLES[i].y, (int)CIRCLES[i].radius, WHITE);
	}

	draw_projectiles();

	FONT.draw_number(SCORE, CENTER_X + 450, 50, 60);
}


// free game data in this function
void finalize() {}
