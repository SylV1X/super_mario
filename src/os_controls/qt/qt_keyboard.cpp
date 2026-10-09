#include "qt_keyboard.hpp"

#include <QCoreApplication>
#include <QKeyEvent>

using biv::QtKeyBoard;
using biv::UserInput;


const int KEY_A = 65;
const int KEY_D = 68;
const int KEY_Q = 81;
const int KEY_SPACE = 32;

bool QtKeyBoard::eventFilter(QObject* obj, QEvent* event) {
	if (event->type() == QEvent::WindowDeactivate) {
		pressed_keys.clear();
		return false;
	}

	if (event->type() != QEvent::KeyPress && event->type() != QEvent::KeyRelease) {
		return false;
	}

	QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
	int key = key_event->nativeVirtualKey();

	if (event->type() == QEvent::KeyPress) {
		pressed_keys.insert(key);
	} else if (!key_event->isAutoRepeat()) {
		pressed_keys.erase(key);
	}

	return false;
}

UserInput QtKeyBoard::get_user_input() {
	if (pressed_keys.count(KEY_A) > 0) {
		return UserInput::MAP_RIGHT;
	} else if (pressed_keys.count(KEY_D) > 0) {
		return UserInput::MAP_LEFT;
	} else if (pressed_keys.count(KEY_SPACE) > 0) {
		return UserInput::MARIO_JUMP;
	} else if (pressed_keys.count(KEY_Q) > 0) {
		return UserInput::EXIT;
	} else {
		return UserInput::NO_INPUT;
	}
}

void QtKeyBoard::on() {
	QCoreApplication::instance()->installEventFilter(this);
}

void QtKeyBoard::off() {
	QCoreApplication::instance()->removeEventFilter(this);
	pressed_keys.clear();
}
