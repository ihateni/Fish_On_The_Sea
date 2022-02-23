#include "shop.h"


namespace fish {
	namespace shop {

		void initShop(Vector2& mainSize, Vector2& mainPos,Vector2& openSize, Vector2& openPos, Vector2& closeSize, Vector2& closePos,
			Vector2& leftArrowSize, Vector2& leftArrowPos) {
			mainSize = { static_cast<float> (GetScreenWidth()) - ((static_cast<float>(GetScreenWidth()) / 10 )* 2 ),
			static_cast<float> (GetScreenHeight()) - ((static_cast<float>(GetScreenHeight()) / 10) * 2) };

			mainPos = { static_cast<float>(GetScreenWidth())/10,static_cast<float> (GetScreenHeight()) / 10};

			openSize = { static_cast<float>(GetScreenWidth()) / 10 , (static_cast<float>(GetScreenWidth()) / 10)};
			openPos = { static_cast<float>(GetScreenWidth()) / 10 , (static_cast<float>(GetScreenHeight()) / 10) };

			closeSize = { static_cast<float>(GetScreenWidth()) / 10 , (static_cast<float>(GetScreenWidth()) / 10) };
			closePos = { static_cast<float>(GetScreenWidth()) / 10 , (static_cast<float>(GetScreenHeight()) / 10) };


		}

		void drawShop(Vector2& mainSize, Vector2& mainPos) {
			DrawRectangle(static_cast<int>(mainPos.x), static_cast<int>(mainPos.y), static_cast<int>(mainSize.x), static_cast<int>(mainSize.y), ORANGE);
		}

		void drawOpen(Vector2& openSize, Vector2& openPos){
			DrawRectangle(static_cast<int>(openPos.x), static_cast<int>(openPos.y), static_cast<int>(openSize.x), static_cast<int>(openSize.y), ORANGE);
		}

		void drawClose(Vector2& closeSize, Vector2& closePos) {
			DrawRectangle(static_cast<int>(closePos.x), static_cast<int>(closePos.y), static_cast<int>(closeSize.x), static_cast<int>(closeSize.y), RED);
		}
	}
}