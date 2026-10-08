#include "qt_mario.hpp"

#include <QTransform>

using biv::QtMario;

QtMario::QtMario(const Coord& top_left, const int width, const int height)
	: Mario(top_left, width, height) {}

void QtMario::paint(QPainter& painter) const {
	static const QPixmap facing_right(SPRITES_DIR "mario_small_walk.png");
	static const QPixmap facing_left = facing_right.transformed(QTransform().scale(-1, 1));

	if (is_facing_left()) {
		painter.drawPixmap(get_sprite_rect(facing_left.size()), facing_left);
	} else {
		painter.drawPixmap(get_sprite_rect(facing_right.size()), facing_right);
	}
}