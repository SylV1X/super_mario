#pragma once

#include <QWidget>
#include <QSet>

#include "keyboard.hpp"

namespace biv {
	class QtGameMap;

	class QtGameFieldWidget : public QWidget, public biv::KeyBoard {
		Q_OBJECT

		private:
			QtGameMap* game_map = nullptr;
			QSet<int> pressed_keys;
			int map_height;
			int map_width;

		public:
			QtGameFieldWidget(
				const int map_height, const int map_width, QWidget* parent = nullptr
			);

			void set_game_map(QtGameMap* game_map);

			UserInput get_user_input() override;
			void on() override;
			void off() override;

		protected:
			void paintEvent(QPaintEvent* event) override;
			void keyPressEvent(QKeyEvent* event) override;
			void keyReleaseEvent(QKeyEvent* event) override;
	};
}