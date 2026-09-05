#pragma once

#include "collisionable.hpp"
#include "movable.hpp"

namespace biv {
	class MoveCollisionable : public Movable, public Collisionable {
		public:
			MoveCollisionable() = default;

			virtual void process_move_collision(Movable* platform) noexcept = 0;
	};
}