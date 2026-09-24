#include "qt_money.hpp"

using biv::QtMoney;

QtMoney::QtMoney(const Coord& top_left, const int width, const int height) 
	: Money(top_left, width, height) {}

void QtMoney::paint(QPainter& painter) const {
	painter.fillRect(get_scaled_rect(), QColor(255, 223, 0)); // gold
}
