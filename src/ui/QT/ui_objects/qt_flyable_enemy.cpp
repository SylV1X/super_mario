#include "qt_flyable_enemy.hpp"

#include <QTransform>

using biv::QtFlyableEnemy;

QtFlyableEnemy::QtFlyableEnemy(const Coord& top_left, const int width, const int height) 
	: FlyableEnemy(top_left, width, height) {}

void QtFlyableEnemy::paint(QPainter& painter) const {
	static const QPixmap facing_left(SPRITES_DIR "cheep_cheep_red.png");
	static const QPixmap facing_right = facing_left.transformed(QTransform().scale(-1, 1));

	if (get_hspeed() > 0) {
		painter.drawPixmap(get_sprite_rect(facing_right.size()), facing_right);
	} else {
		painter.drawPixmap(get_sprite_rect(facing_left.size()), facing_left);
	}
}