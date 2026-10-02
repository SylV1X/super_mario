#include "qt_mario.hpp"

using biv::QtMario;

QtMario::QtMario(const Coord& top_left, const int width, const int height)
	: Mario(top_left, width, height) {}

void QtMario::paint(QPainter& painter) const {
	static const QPixmap sprite(SPRITES_DIR "mario_small_walk.png");
	painter.drawPixmap(get_sprite_rect(sprite.size()), sprite);
}