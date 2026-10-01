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
	QPainter painter(&buffer);
	
	// Воздух
	painter.fillRect(buffer.rect(), QColor(135, 206, 235));
	
	// Вода
	painter.fillRect(
		QRect(0, (height - 3) * CELL_PX, width * CELL_PX, 3 * CELL_PX),
		QColor(0, 105, 148)
	);
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
