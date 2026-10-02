#include "qt_enemy.hpp"

using biv::QtEnemy;

QtEnemy::QtEnemy(const Coord& top_left, const int width, const int height) 
	: Enemy(top_left, width, height) {}

void QtEnemy::paint(QPainter& painter) const {
	static const QPixmap sprite(SPRITES_DIR "goomba.png");
	painter.drawPixmap(get_sprite_rect(sprite.size()), sprite);
}