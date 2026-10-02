#include "qt_ship.hpp"
#include "qt_map_pixel_size.hpp"

using biv::QtShip;

QtShip::QtShip(const Coord& top_left, const int width, const int height) 
	: Ship(top_left, width, height) {}

void QtShip::paint(QPainter& painter) const {
	static const QPixmap tile = QPixmap(SPRITES_DIR "ground.png").scaled(TILE_PX, TILE_PX);
	painter.drawTiledPixmap(get_scaled_rect(), tile);
}