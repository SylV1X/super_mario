#include "qt_money.hpp"

using biv::QtMoney;

QtMoney::QtMoney(const Coord& top_left, const int width, const int height) 
	: Money(top_left, width, height) {}

void QtMoney::paint(QPainter& painter) const {
	static const QPixmap sprite(SPRITES_DIR "coin.png");
	painter.drawPixmap(get_sprite_rect(sprite.size()), sprite);
}
