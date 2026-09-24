#include "qt_box.hpp"

using biv::QtBox;

QtBox::QtBox(const Coord& top_left, const int width, const int height) 
	: Box(top_left, width, height) {}

void QtBox::paint(QPainter& painter) const {
	painter.fillRect(get_scaled_rect(), QColor(160, 82, 45)); // brown
}