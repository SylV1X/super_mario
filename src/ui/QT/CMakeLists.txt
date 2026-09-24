target_sources(${PROJECT_NAME}
	PRIVATE
		qt_game_map.cpp
		qt_game_field_widget.cpp
		qt_ui_obj_rect_adapter.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}"
)

