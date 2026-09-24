#pragma once

#include "qt_ui_obj_rect_adapter.hpp"
#include "platform.hpp"

namespace biv {
	class QtPlatform : public Platform, public QtUIObjectRectAdapter {
		public:
			QtPlatform(const Coord& top_left, const int width, const int height);

			void paint(QPainter& painter) const override;
	};
}
