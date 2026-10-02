#include "qt_jumpable_enemy.hpp"

using biv::QtJumpableEnemy;

QtJumpableEnemy::QtJumpableEnemy(const Coord& top_left, const int width, const int height) 
	: JumpableEnemy(top_left, width, height) {}

void QtJumpableEnemy::paint(QPainter& painter) const {
	static const QPixmap sprite(SPRITES_DIR "koopa_green.png");
	painter.drawPixmap(get_sprite_rect(sprite.size()), sprite);
}