#include "platform.hpp"
#include "mario.hpp"

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

void Platform::move_horizontally() noexcept {
	float old_x = top_left.x;
	top_left.x += hspeed;
	
	if (passenger) {
		Rect passenger_rect = passenger->get_rect();
		Rect platform_rect = get_rect();
		
		bool is_standing = 
			passenger_rect.get_bottom() >= platform_rect.get_top() - 1 &&
			passenger_rect.get_bottom() <= platform_rect.get_top() + 5 &&
			passenger_rect.get_right() > platform_rect.get_left() &&
			passenger_rect.get_left() < platform_rect.get_right();
		
		if (is_standing) {
			float delta = top_left.x - old_x;
			passenger->move_horizontal_offset(delta);
		} else {
			passenger = nullptr;
		}
	}
}

void Platform::process_horizontal_static_collision(Rect* obj) noexcept {
	hspeed = -hspeed;
	move_horizontally();  
}

void Platform::process_mario_collision(Collisionable* mario) noexcept {
	Mario* player = dynamic_cast<Mario*>(mario);
	float old_vspeed = player->get_vspeed();

	player->process_vertical_static_collision(this);
	
	if (old_vspeed < 0) {
		passenger = nullptr;
	} else {
		passenger = player;
	}
}
void Platform::process_vertical_static_collision(Rect* obj) noexcept {
}