#include "qt_game_field_widget.hpp"

#include <QKeyEvent>
#include <QPainter>

#include "qt_map_pixel_size.hpp"
#include "qt_game_map.hpp"

using biv::QtGameFieldWidget;
using biv::UserInput;

QtGameFieldWidget::QtGameFieldWidget(
	const int map_height, const int map_width, QWidget* parent)
	: QWidget(parent), map_height(map_height), map_width(map_width) {
	setFixedSize(map_width * CELL_PX, map_height * CELL_PX);
	setFocusPolicy(Qt::StrongFocus);
}

void QtGameFieldWidget::set_game_map(QtGameMap* game_map) {
	this->game_map = game_map;
}

UserInput QtGameFieldWidget::get_user_input() {
	if (pressed_keys.contains(Qt::Key_A)) {
		return UserInput::MAP_RIGHT;
	} else if (pressed_keys.contains(Qt::Key_D)) {
		return UserInput::MAP_LEFT;
	} else if (pressed_keys.contains(Qt::Key_Space)) {
		return UserInput::MARIO_JUMP;
	} else if (pressed_keys.contains(Qt::Key_Q)) {
		return UserInput::EXIT;
	} else {
		return UserInput::NO_INPUT;
	}
}

void QtGameFieldWidget::on() {}

void QtGameFieldWidget::off() {
	pressed_keys.clear();
}

void QtGameFieldWidget::paintEvent(QPaintEvent*) {
	QPainter painter(this);

	// Воздух
	painter.fillRect(rect(), QColor(135, 206, 235));

	// Вода
	int water_height_px = 3 * CELL_PX;
	painter.fillRect(
		QRect(0, height() - water_height_px, width(), water_height_px),
		QColor(0, 105, 148)
	);

	if (game_map != nullptr) {
		for (biv::QtUIObject* obj : game_map->get_objs()) {
			obj->paint(painter);
		}
	}
}

void QtGameFieldWidget::keyPressEvent(QKeyEvent* event) {
	pressed_keys.insert(event->key());
}

void QtGameFieldWidget::keyReleaseEvent(QKeyEvent* event) {
	pressed_keys.remove(event->key());
}