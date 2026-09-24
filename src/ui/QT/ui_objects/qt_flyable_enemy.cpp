#include "qt_flyable_enemy.hpp"

using biv::QtFlyableEnemy;

QtFlyableEnemy::QtFlyableEnemy(const Coord& top_left, const int width, const int height) 
	: FlyableEnemy(top_left, width, height) {}

void QtFlyableEnemy::paint(QPainter& painter) const {
	painter.fillRect(get_scaled_rect(), QColor(148, 0, 211)); // purple
}