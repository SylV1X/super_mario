#include "qt_box.hpp"
#include "qt_map_pixel_size.hpp"

using biv::QtBox;

QtBox::QtBox(const Coord& top_left, const int width, const int height) 
	: Box(top_left, width, height) {}

void QtBox::paint(QPainter& painter) const {
	static const QPixmap tile = QPixmap(SPRITES_DIR "brick.png").scaled(TILE_PX, TILE_PX);
	painter.drawTiledPixmap(get_scaled_rect(), tile);
}