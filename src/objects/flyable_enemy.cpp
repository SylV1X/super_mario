#include "flyable_enemy.hpp"

using biv::FlyableEnemy;

FlyableEnemy::FlyableEnemy(const Coord& top_left, const int width, const int height) 
	: RectMapMovableAdapter(top_left, width, height) {
	vspeed = 0;
	hspeed = 0.2;
}

biv::Rect FlyableEnemy::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed FlyableEnemy::get_speed() const noexcept {
	return {vspeed, hspeed};
}

void FlyableEnemy::move_map_left() noexcept {
	RectMapMovableAdapter::move_map_left();
	min_x -= MapMovable::MAP_STEP;
	max_x -= MapMovable::MAP_STEP;
}

void FlyableEnemy::move_map_right() noexcept {
	RectMapMovableAdapter::move_map_right();
	min_x += MapMovable::MAP_STEP;
	max_x += MapMovable::MAP_STEP;
}

void FlyableEnemy::move_horizontally() noexcept {
	if (top_left.x + hspeed <= min_x) {
		hspeed = -hspeed;
	} else if (top_left.x + width + hspeed >= max_x) {
		hspeed = -hspeed;
	}
	
	top_left.x += hspeed;
}

void FlyableEnemy::move_vertically() noexcept {
	if (!is_active()) {
		if (vspeed < MAX_V_SPEED) {
			vspeed += V_ACCELERATION;
		}
		top_left.y += vspeed;
	}
}

void FlyableEnemy::process_horizontal_static_collision(Rect* obj) noexcept {
	hspeed = -hspeed;
	move_horizontally();
}

void FlyableEnemy::process_mario_collision(Collisionable* mario) noexcept {
	if (mario->get_speed().v > 0 && mario->get_speed().v != V_ACCELERATION) {
		kill();
	} else {
		mario->kill();
	}
}

void FlyableEnemy::process_vertical_static_collision(Rect* obj) noexcept {
}