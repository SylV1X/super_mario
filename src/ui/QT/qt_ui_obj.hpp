#pragma once

#include <QPainter>
#include <QRect>

namespace biv {
	class QtUIObject {
		public:
			virtual QRect get_scaled_rect() const noexcept = 0;
			virtual void paint(QPainter& painter) const = 0;
	};
}