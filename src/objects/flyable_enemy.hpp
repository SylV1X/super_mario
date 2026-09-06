#pragma once

#include "collisionable.hpp"
#include "movable.hpp"
#include "rect.hpp"
#include "rect_map_movable_adapter.hpp"
#include "speed.hpp"

namespace biv {
	class FlyableEnemy : public RectMapMovableAdapter, public Movable, public Collisionable {
		private:
			float min_x = 0;
			float max_x = 250;
			
		public:
			FlyableEnemy(const Coord& top_left, const int width, const int height);
			
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