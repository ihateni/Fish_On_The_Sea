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
			Texture2D closeTex1;
			Texture2D closeTex2;
			Texture2D mainTex;
			Texture2D leftTex1;
			Texture2D leftTex2;
			Texture2D rightTex1;
			Texture2D rightTex2;
			Texture2D buyTex1;
			Texture2D buyTex2;
			bool openState;
			bool closeState;
			bool leftState;
			bool rightState;
			bool buyState;
			Font font;

		};

		void initShop(Vector2& mainSize, Vector2& mainPos, Vector2& openSize, Vector2& openPos, Vector2& closeSize, Vector2& closePos,
			Vector2& leftArrowSize, Vector2& leftArrowPos, Vector2& rightArrowSize, Vector2& rightArrowPos, Vector2& itemSize, Vector2& itemPos,
			int& item, Vector2& buySize, Vector2& buyPos, Texture2D& closeTex1, Texture2D& closeTex2, Texture2D& mainTex, Texture2D& leftTex1,
			Texture2D& leftTex2,Texture2D& rightTex1, Texture2D& rightTex2, Texture2D& buyTex1, Texture2D& buyTex2, bool& openState, bool& closeState,
			bool& leftState, bool& rightState, bool& buyState, Font& font);
		void drawShop(Vector2& mainSize, Vector2& mainPos, Texture2D& mainTex);
		void drawOpen(Vector2& openSize, Vector2& openPos, Texture2D& closeTex1, Texture2D& closeTex2, bool& openState);
		void drawClose(Vector2& closeSize, Vector2& closePos, Texture2D& closeTex1, Texture2D& closeTex2, bool& closeState);
		void drawLeftArrow(Vector2& leftArrowSize, Vector2& leftArrowPos, Texture2D& leftTex1, Texture2D& leftTex2, bool& leftState);
		void drawRightArrow(Vector2& rightArrowSize, Vector2& rightArrowPos, Texture2D& rightTex1, Texture2D& rightTex2, bool& rightState);
		void drawItem(Vector2& itemSize, Vector2& itemPos, int& item, Font& font, int& capasity, int& reach);
		void increaseItem(int& item);
		void decreaseItem(int& item);
		void drawBuy(Vector2& buySize, Vector2& buyPos, Texture2D& buyTex1, Texture2D& buyTex2, bool& buytState);
		void upgradeItem(int& item, int& capasity, int& reach, int& points);
		//void shopDeInit();
	}
}
#endif