#include "qt_platform.hpp"

using biv::QtPlatform;

QtPlatform::QtPlatform(const Coord& top_left, const int width, const int height) 
	: Platform(top_left, width, height) {}

void QtPlatform::paint(QPainter& painter) const {
	painter.fillRect(get_scaled_rect(), QColor(105, 105, 105)); // gray
}