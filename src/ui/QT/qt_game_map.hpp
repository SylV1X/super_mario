#pragma once

#include <vector>

#include "game_map.hpp"
#include "qt_ui_obj.hpp"
#include "qt_game_field_widget.hpp" 

namespace biv {
	class QtGameMap : public GameMap {
		private:
			QtGameFieldWidget* widget;
			
			std::vector<QtUIObject*> objs;
			
		public:
			QtGameMap(const int height, const int width, QtGameFieldWidget* widget);
			
			void add_obj(QtUIObject*);
			void clear() noexcept override;
			void refresh() noexcept override;
			void remove_obj(QtUIObject*);
			void remove_objs() override;
			void show() const noexcept override;
			
			const std::vector<QtUIObject*>& get_objs() const noexcept;
	};
}
