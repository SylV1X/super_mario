#pragma once

#include "qt_ui_obj.hpp"
#include "rect.hpp"

namespace biv {
	class QtUIObjectRectAdapter : virtual public Rect, public QtUIObject {
		public:
			QtUIObjectRectAdapter() = default;
			QtUIObjectRectAdapter(
				const Coord& top_left, const int width, const int height
			);

			QRect get_scaled_rect() const noexcept override;
			
		protected:
			QRect get_sprite_rect(const QSize& sprite_size) const noexcept;
	};
}