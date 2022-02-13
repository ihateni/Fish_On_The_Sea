#ifndef Shop_H
#define Shop_H

#include "raylib.h"

namespace fish {
	namespace shop {

		struct Shop {
			Vector2 mainSize;
			Vector2 mainPos;
			Vector2 leftArrowSize;
			Vector2 leftArrowPos;
			Vector2 rightArrowSize;
			Vector2 rightArrowPos;
			Vector2 closeSize;
			Vector2 closePos;
			Vector2 openSize;
			Vector2 openPos;
		};

		void initShop(Vector2& mainSize, Vector2& mainPos, Vector2& openSize,Vector2& openPos);
		void drawShop(Vector2& mainSize, Vector2& mainPos);
		void drawOpen(Vector2& openSize, Vector2& openPos);
	}
}
#endif