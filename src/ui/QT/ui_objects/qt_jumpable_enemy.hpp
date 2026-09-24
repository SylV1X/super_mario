#pragma once

#include "qt_ui_obj_rect_adapter.hpp"
#include "jumpable_enemy.hpp"

namespace biv {
	class QtJumpableEnemy : public JumpableEnemy, public QtUIObjectRectAdapter {
		public:
			QtJumpableEnemy(const Coord& top_left, const int width, const int height);

			void paint(QPainter& painter) const override;
	};
}
