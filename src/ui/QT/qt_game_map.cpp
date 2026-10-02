#include "qt_game_map.hpp"

#include <algorithm>

#include <QColor>
#include <QPainter>
#include <QRect>

#include "qt_map_pixel_size.hpp"

using biv::QtGameMap;

QtGameMap::QtGameMap(const int height, const int width)
	: GameMap(height, width), buffer(width * CELL_PX, height * CELL_PX) {

	screen = new QLabel();
	screen->setFixedSize(buffer.size());
	screen->setWindowTitle("Super Mario");
	
	clear();
}

QtGameMap::~QtGameMap() {
	delete screen;
}

void QtGameMap::add_obj(QtUIObject* obj) {
	objs.push_back(obj);
}

void QtGameMap::clear() noexcept {
	static const QPixmap sky = QPixmap(SPRITES_DIR "sky.png").scaled(TILE_PX, TILE_PX);
	static const QPixmap water = QPixmap(SPRITES_DIR "water.png").scaled(TILE_PX, TILE_PX);
	static const QPixmap waves = QPixmap(SPRITES_DIR "water_top.png").scaled(TILE_PX, TILE_PX);
		
	QPainter painter(&buffer);
	
	// Воздух
	painter.drawTiledPixmap(buffer.rect(), sky);
	
	// Вода
	QRect water_rect(0, (height - 3) * CELL_PX, width * CELL_PX, 3 * CELL_PX);
	painter.drawTiledPixmap(water_rect, water);
	
	QRect waves_rect = water_rect;
	waves_rect.setHeight(std::min(TILE_PX, water_rect.height()));
	painter.drawTiledPixmap(waves_rect, waves);
}

void QtGameMap::refresh() noexcept {
	clear();

	QPainter painter(&buffer);
	for (QtUIObject* obj: objs) {
		obj->paint(painter);
	}
}


void QtGameMap::remove_obj(QtUIObject* obj) {
	objs.erase(std::remove(objs.begin(), objs.end(), obj), objs.end());
}

void QtGameMap::remove_objs() {
	objs.clear();
}
void QtGameMap::show() const noexcept {
	if (!screen->isVisible()) {
		screen->show();
	}
	screen->setPixmap(buffer);
}
