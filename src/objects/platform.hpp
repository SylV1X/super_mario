#pragma once

#include "collisionable.hpp"
#include "game_map.hpp"
#include "movable.hpp"
#include "rect.hpp"
#include "rect_map_movable_adapter.hpp"
#include "speed.hpp"

namespace biv {
	class Platform : public RectMapMovableAdapter, public Movable, public Collisionable {
		private:
			float min_x = biv::GameMap::LEFT_MAP_BOARD;
			float max_x = biv::GameMap::RIGHT_MAP_BOARD;
			
		public:
			Platform(const Coord& top_left, const int width, const int height);
			
			Rect get_rect() const noexcept override;
			Speed get_speed() const noexcept override;
			
		    void move_map_left() noexcept override;
			void move_map_right() noexcept override;
			
			void move_horizontally() noexcept override;
			void move_vertically() noexcept override;
			
			void process_horizontal_static_collision(Rect* obj) noexcept override;
			void process_mario_collision(Collisionable* mario) noexcept override;
			void process_vertical_static_collision(Rect* obj) noexcept override;
	};
}