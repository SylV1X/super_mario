#include "qt_game_map.hpp"

#include <algorithm>

using biv::QtGameMap;

QtGameMap::QtGameMap(const int height, const int width, QtGameFieldWidget* widget)
	: GameMap(height, width), widget(widget) {}

void QtGameMap::add_obj(QtUIObject* obj) {
	objs.push_back(obj);
}

void QtGameMap::clear() noexcept {
}

void QtGameMap::refresh() noexcept {
}

void QtGameMap::remove_obj(QtUIObject* obj) {
	objs.erase(std::remove(objs.begin(), objs.end(), obj), objs.end());
}

void QtGameMap::remove_objs() {
	objs.clear();
}

void QtGameMap::show() const noexcept {
	widget->update();
}

const std::vector<biv::QtUIObject*>& QtGameMap::get_objs() const noexcept {
	return objs;
}