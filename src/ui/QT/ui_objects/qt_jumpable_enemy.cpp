#include "qt_jumpable_enemy.hpp"

using biv::QtJumpableEnemy;

QtJumpableEnemy::QtJumpableEnemy(const Coord& top_left, const int width, const int height) 
	: JumpableEnemy(top_left, width, height) {}

void QtJumpableEnemy::paint(QPainter& painter) const {
	painter.fillRect(get_scaled_rect(), QColor(255, 140, 0)); // orange
}