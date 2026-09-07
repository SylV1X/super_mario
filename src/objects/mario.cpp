#include "mario.hpp"

#include "map_movable.hpp"

using biv::Mario;

Mario::Mario(const Coord& top_left, const int width, const int height) 
	: MoveCollisionable() {
	this->top_left = top_left;
	this->width = width;
	this->height = height;
	vspeed = 0;
	hspeed = 0;
}

biv::Rect Mario::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed Mario::get_speed() const noexcept {
	return {vspeed, hspeed};
}

int Mario::get_camera_direction() noexcept {
	if (top_left.x < 15) {
		move_map_left();
		return 1;
	} else if (top_left.x + width > 65) {
		move_map_right();
		return -1;
	}
	return 0;
}

void Mario::move_map_left() noexcept {
	move_horizontal_offset(biv::MapMovable::MAP_STEP);
}

void Mario::move_map_right() noexcept {
	move_horizontal_offset(-biv::MapMovable::MAP_STEP);
}

void Mario::move_vertically() noexcept {
	if (vspeed != 0) {
		hspeed = 0;
	}
	if (vspeed < MAX_V_SPEED) {
		vspeed += V_ACCELERATION;
	}
	top_left.y += vspeed;
}

void Mario::process_horizontal_static_collision(Rect* obj) noexcept {
	hspeed = -hspeed;
	move_horizontally();
}

void Mario::process_mario_collision(Collisionable* mario) noexcept {
}

void Mario::process_move_collision(Movable* platform) noexcept {
	if (vspeed > 0) {
		// Марио упал на платформу.
		top_left.y -= vspeed;
		hspeed = platform->get_hspeed();
	} else if (vspeed < 0) {
		// Марио ударился головой о платформу и после этого должен падать вниз.
		top_left.y -= vspeed;
	}
	vspeed = 0;
}

void Mario::process_vertical_static_collision(Rect* obj) noexcept {
	if (vspeed > 0) {
		// Марио упал на корабль.
		top_left.y -= vspeed;
		hspeed = 0;
	} else if (vspeed < 0) {
		// Марио ударился головой о полку и после этого должен падать вниз.
		top_left.y -= vspeed;
	}
	vspeed = 0;
}
