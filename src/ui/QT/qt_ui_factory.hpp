#pragma once

#include "qt_box.hpp"
#include "qt_enemy.hpp"
#include "qt_flyable_enemy.hpp"
#include "qt_jumpable_enemy.hpp"
#include "qt_full_box.hpp"
#include "qt_game_map.hpp"
#include "qt_mario.hpp"
#include "qt_money.hpp"
#include "qt_platform.hpp"
#include "qt_ship.hpp"
#include "qt_game_field_widget.hpp"
#include "ui_factory.hpp"

namespace biv {
	class QtUIFactory : public UIFactory {
		private:
			QtGameFieldWidget* widget;
			QtGameMap* game_map = nullptr;
			std::vector<QtBox*> boxes;
			std::vector<QtFullBox*> full_boxes;
			std::vector<QtShip*> ships;
			QtMario* mario = nullptr;
			std::vector<QtEnemy*> enemies;
			std::vector<QtFlyableEnemy*> flyable_enemies;
			std::vector<QtJumpableEnemy*> jumpable_enemies;
			std::vector<QtMoney*> moneys;
			std::vector<QtPlatform*> platforms;

		public:
			QtUIFactory(Game* game, QtGameFieldWidget* widget);
			
			void clear_data() override;
			void create_box(
				const Coord& top_left, const int width, const int height
			) override;
			void create_enemy(
				const Coord& top_left, const int width, const int height
			) override;			
			void create_flyable_enemy(
				const Coord& top_left, const int width, const int height
			) override;
			void create_jumpable_enemy(
				const Coord& top_left, const int width, const int height
			) override;
			void create_full_box(
				const Coord& top_left, const int width, const int height
			) override;
			void create_mario(
				const Coord& top_left, const int width, const int height
			) override;
			void create_money(
				const Coord& top_left, const int width, const int height
			) override;
			void create_platform(
				const Coord& top_left, const int width, const int height
			) override;
			void create_ship(
				const Coord& top_left, const int width, const int height
			) override;
			GameMap* get_game_map(const int height, const int width) override;
			Mario* get_mario() override;
	};
}
