#include "second_level.hpp"

#include "third_level.hpp"

using biv::SecondLevel;

SecondLevel::SecondLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

biv::GameLevel* SecondLevel::get_next() {
	if (!next) {
		clear_data();
		next = new biv::ThirdLevel(ui_factory);
	}
	return next;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void SecondLevel::init_data() {
	ui_factory->create_mario({39, 10}, 3, 3);
	
	ui_factory->create_ship({20, 20}, 40, 5);
	ui_factory->create_ship({60, 15}, 10, 10);
	ui_factory->create_ship({80, 20}, 20, 5);
	ui_factory->create_ship({120, 15}, 10, 10);
	ui_factory->create_ship({150, 20}, 40, 5);
	ui_factory->create_ship({210, 15}, 10, 10);

	ui_factory->create_enemy({25, 15}, 3, 2);
	ui_factory->create_enemy({90, 15}, 3, 2);
	ui_factory->create_enemy({130, 15}, 3, 2);
	ui_factory->create_enemy({175, 15}, 3, 2);
		
	ui_factory->create_flyable_enemy({65, 12}, 3, 2);
	ui_factory->create_flyable_enemy({125, 12}, 3, 2);
	
	ui_factory->create_jumpable_enemy({85, 15}, 3, 2);
	ui_factory->create_jumpable_enemy({160, 15}, 3, 2);
	
}
