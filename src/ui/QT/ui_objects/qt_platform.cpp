#include "qt_platform.hpp"

using biv::QtPlatform;

QtPlatform::QtPlatform(const Coord& top_left, const int width, const int height) 
	: Platform(top_left, width, height) {}

void QtPlatform::paint(QPainter& painter) const {
	static const QPixmap sprite(SPRITES_DIR "platform_gray.png");
	painter.drawPixmap(get_scaled_rect(), sprite);
}