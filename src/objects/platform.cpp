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