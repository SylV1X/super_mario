#include "platform.hpp"

using biv::Platform;

Platform::Platform(const Coord& top_left, const int width, const int height)
	: RectMapMovableAdapter(top_left, width, height) {
	vspeed = 0;
	hspeed = 0.2;
}

biv::Rect Platform::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed Platform::get_speed() const noexcept {
	return {vspeed, hspeed};
}

void Platform::move_map_left() noexcept {
	RectMapMovableAdapter::move_map_left();
	min_x -= MapMovable::MAP_STEP;
	max_x -= MapMovable::MAP_STEP;
}

void Platform::move_map_right() noexcept {
	RectMapMovableAdapter::move_map_right();
	min_x += MapMovable::MAP_STEP;
	max_x += MapMovable::MAP_STEP;
}

void Platform::move_horizontally() noexcept {
	if (top_left.x + hspeed <= min_x) {
		hspeed = -hspeed;
	} else if (top_left.x + width + hspeed >= max_x) {
		hspeed = -hspeed;
	}
	
	top_left.x += hspeed;
}

void Platform::move_vertically() noexcept {
}

void Platform::process_horizontal_static_collision(Rect* obj) noexcept {
	hspeed = -hspeed;
	move_horizontally();  
}

void Platform::process_mario_collision(Collisionable* mario) noexcept {
}

void Platform::process_vertical_static_collision(Rect* obj) noexcept {
}