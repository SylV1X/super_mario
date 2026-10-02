#include "qt_flyable_enemy.hpp"

using biv::QtFlyableEnemy;

QtFlyableEnemy::QtFlyableEnemy(const Coord& top_left, const int width, const int height) 
	: FlyableEnemy(top_left, width, height) {}

void QtFlyableEnemy::paint(QPainter& painter) const {
	static const QPixmap sprite(SPRITES_DIR "cheep_cheep_red.png");
	painter.drawPixmap(get_sprite_rect(sprite.size()), sprite);
}