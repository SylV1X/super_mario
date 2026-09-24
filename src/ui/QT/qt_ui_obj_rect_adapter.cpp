#include "qt_ui_obj_rect_adapter.hpp"

#include "qt_map_pixel_size.hpp"

using biv::QtUIObjectRectAdapter;

QtUIObjectRectAdapter::QtUIObjectRectAdapter(
	const Coord& top_left, const int width, const int height
) {
	this->top_left = top_left;
	this->width = width;
	this->height = height;
}

QRect QtUIObjectRectAdapter::get_scaled_rect() const noexcept {
	return QRect(
		get_left() * CELL_PX,
		get_top() * CELL_PX,
		(get_right() - get_left()) * CELL_PX,
		(get_bottom() - get_top()) * CELL_PX
	);
}