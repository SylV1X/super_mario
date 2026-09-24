#include "qt_enemy.hpp"

using biv::QtEnemy;

QtEnemy::QtEnemy(const Coord& top_left, const int width, const int height) 
	: Enemy(top_left, width, height) {}

void QtEnemy::paint(QPainter& painter) const {
	painter.fillRect(get_scaled_rect(), QColor(101, 67, 33)); // brown 2
}