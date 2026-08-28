#include "console_platform.hpp"

using biv::ConsolePlatform;

ConsolePlatform::ConsolePlatform(const Coord& top_left, const int width, const int height) 
	: Platform(top_left, width, height) {}

char ConsolePlatform::get_brush() const noexcept {
	return 'p';
}