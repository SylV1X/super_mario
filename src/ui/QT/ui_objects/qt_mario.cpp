#include "qt_mario.hpp"

using biv::QtMario;

QtMario::QtMario(const Coord& top_left, const int width, const int height)
	: Mario(top_left, width, height) {}

void QtMario::paint(QPainter& painter) const {
	painter.fillRect(get_scaled_rect(), QColor(220, 20, 20));
}