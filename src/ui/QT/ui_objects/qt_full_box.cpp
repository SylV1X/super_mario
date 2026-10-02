#include "qt_full_box.hpp"

using biv::QtFullBox;

QtFullBox::QtFullBox(
	const Coord& top_left,
	const int width, const int height,
	UIFactory* ui_factory
) : FullBox(top_left, width, height, ui_factory) {}

void QtFullBox::paint(QPainter& painter) const {
	static const QPixmap full(SPRITES_DIR "question_block.png");
	static const QPixmap empty(SPRITES_DIR "used_block.png");

	if (is_active_) {
		painter.drawPixmap(get_scaled_rect(), full);
	} else {
		painter.drawPixmap(get_scaled_rect(), empty);
	}
}