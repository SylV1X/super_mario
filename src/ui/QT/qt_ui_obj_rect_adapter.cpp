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

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
QRect QtUIObjectRectAdapter::get_sprite_rect(const QSize& sprite_size) const noexcept {
	QRect area = get_scaled_rect();
	QSize size = sprite_size.scaled(area.size(), Qt::KeepAspectRatio);

	return QRect(
		area.left() + (area.width() - size.width()) / 2,
		area.top() + area.height() - size.height(),
		size.width(),
		size.height()
	);
}