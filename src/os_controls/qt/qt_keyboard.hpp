#pragma once

#include <set>
#include <QEvent>
#include <QObject>

#include "keyboard.hpp"

namespace biv {
	class QtKeyBoard : public QObject, public KeyBoard {
		Q_OBJECT
		
		private:
			std::set<int> pressed_keys;
			bool window_closed = false;
			bool eventFilter(QObject* obj, QEvent* event) override;
			
		public:
			UserInput get_user_input() override;
			void on() override;
			void off() override;
	};
}
