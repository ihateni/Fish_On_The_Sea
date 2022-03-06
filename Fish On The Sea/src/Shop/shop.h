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
			Vector2 itemSize;
			Vector2 itemPos;
			Vector2 buySize;
			Vector2 buyPos;
			int item;
			Texture2D CloseTex1;
			Texture2D CloseTex2;

		};

		void initShop(Vector2& mainSize, Vector2& mainPos, Vector2& openSize, Vector2& openPos, Vector2& closeSize, Vector2& closePos, 
			Vector2& leftArrowSize, Vector2& leftArrowPos, Vector2& rightArrowSize, Vector2& rightArrowPos, Vector2& itemSize, Vector2& itemPos,
			int& item, Vector2& buySize, Vector2& buyPos, Texture2D& CloseTex1, Texture2D& CloseTex2);
		void drawShop(Vector2& mainSize, Vector2& mainPos);
		void drawOpen(Vector2& openSize, Vector2& openPos, Texture2D& CloseTex1, Texture2D& CloseTex2);
		void drawClose(Vector2& closeSize, Vector2& closePos, Texture2D& CloseTex1, Texture2D& CloseTex2);
		void drawLeftArrow(Vector2& leftArrowSize, Vector2& leftArrowPos);
		void drawRightArrow(Vector2& rightArrowSize, Vector2& rightArrowPos);
		void drawItem(Vector2& itemSize, Vector2& itemPos, int& item);
		void increaseItem(int& item);
		void decreaseItem(int& item);
		void drawBuy(Vector2& buySize, Vector2& buyPos);
		void upgradeItem(int& item, int& capasity, int& reach, int& points);

	}
}
#endif