#include "qt_full_box.hpp"

using biv::QtFullBox;

QtFullBox::QtFullBox(
	const Coord& top_left,
	const int width, const int height,
	UIFactory* ui_factory
) : FullBox(top_left, width, height, ui_factory) {}

void QtFullBox::paint(QPainter& painter) const {
	if (is_active_) {
		painter.fillRect(get_scaled_rect(), QColor(255, 215, 0)); // yellow
	} else {
		painter.fillRect(get_scaled_rect(), QColor(160, 82, 45));
	}
}