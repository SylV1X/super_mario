#pragma once

#include "console_ui_obj_rect_adapter.hpp"
#include "platform.hpp"

namespace biv {
	class ConsolePlatform : public Platform, public ConsoleUIObjectRectAdapter {
		public:
			ConsolePlatform(const Coord& top_left, const int width, const int height);

			char get_brush() const noexcept override;
	};
}
