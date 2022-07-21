#include "shop.h"

#include <iostream>
namespace fish {
	namespace shop {

		float fonstSize = 25;
		float fonstSizeBig = 40;
		float fontSpacing = 3;

		int price[] = { 100, 500, 1300, 600, 1500, 2000, 200, 2000, 3000};
		float textPosX[] = { 70, 220};
		float textPosY[] = { 135, 160, 185, 210, 215, 240, 290, 400};

		int drawTextureOffset = 43;

		Color qiColor = RED;
		Color qiFinalStageColor = GOLD;
		Color textColor = BLACK;

		void initShop(Vector2& mainSize, Vector2& mainPos, Vector2& openSize, Vector2& openPos, Vector2& closeSize, Vector2& closePos,
			Vector2& leftArrowSize, Vector2& leftArrowPos, Vector2& rightArrowSize, Vector2& rightArrowPos, Vector2& itemSize, Vector2& itemPos,
			int& item, Vector2& buySize, Vector2& buyPos, Texture2D& CloseTex1, Texture2D& CloseTex2, Texture2D& mainTex, Texture2D& leftTex1,
			Texture2D& leftTex2, Texture2D& rightTex1, Texture2D& rightTex2, Texture2D& buyTex1, Texture2D& buyTex2,
			bool& openState, bool& closeState, bool& leftState, bool& rightState, bool& buyState, Font& font) {

			mainSize = { static_cast<float> (GetScreenWidth()) - ((static_cast<float>(GetScreenWidth()) / 10) * 2),
			static_cast<float> (GetScreenHeight()) - ((static_cast<float>(GetScreenHeight()) / 10) * 2) };
			mainPos = { static_cast<float>(GetScreenWidth()) / 10,static_cast<float> (GetScreenHeight()) / 10 };
			mainTex = LoadTexture("res/Shop_buttons/box.png");

			openSize = { static_cast<float>(GetScreenWidth()) / 10 , (static_cast<float>(GetScreenWidth()) / 10) };
			openPos = { static_cast<float>(GetScreenWidth()) / 10 , (static_cast<float>(GetScreenHeight()) / 10) };
			openState = true;

			closeSize = { static_cast<float>(GetScreenWidth()) / 10 , (static_cast<float>(GetScreenWidth()) / 10) };
			closePos = { static_cast<float>(GetScreenWidth()) / 10 , (static_cast<float>(GetScreenHeight()) / 10) };
			closeState = true;

			CloseTex1 = LoadTexture("res/Shop_buttons/x1.png");
			CloseTex2 = LoadTexture("res/Shop_buttons/x2.png");

			leftArrowSize = { (static_cast<float> (GetScreenWidth()) - ((static_cast<float>(GetScreenWidth()) / 10) * 2)) / 3 ,
				(static_cast<float> (GetScreenHeight()) - ((static_cast<float>(GetScreenHeight()) / 10) * 2)) / 15 };
			leftArrowPos = { mainPos.x,mainSize.y };
			leftTex1 = LoadTexture("res/Shop_buttons/left1.png");
			leftTex2 = LoadTexture("res/Shop_buttons/left2.png");
			leftState = true;

			rightArrowSize = { (static_cast<float> (GetScreenWidth()) - ((static_cast<float>(GetScreenWidth()) / 10) * 2)) / 3,
				(static_cast<float> (GetScreenHeight()) - ((static_cast<float>(GetScreenHeight()) / 10) * 2)) / 15 };
			rightArrowPos = { static_cast<float> (GetScreenWidth()) - ((static_cast<float>(GetScreenWidth()) / 10) * 2) - 83, leftArrowPos.y };
			rightTex1 = LoadTexture("res/Shop_buttons/right1.png");
			rightTex2 = LoadTexture("res/Shop_buttons/right2.png");
			rightState = true;

			itemSize = { mainSize.x , mainSize.y - leftArrowSize.y * 2 };
			itemPos = { mainPos.x, mainPos.y };

			item = 1;

			buySize = { (static_cast<float> (GetScreenWidth()) - ((static_cast<float>(GetScreenWidth()) / 10) * 2)) / 3,
				(static_cast<float> (GetScreenHeight()) - ((static_cast<float>(GetScreenHeight()) / 10) * 2)) / 15 };
			buyPos = { mainSize.x / 2 - buySize.x / 9, leftArrowPos.y - buySize.y };
			buyTex1 = LoadTexture("res/Shop_buttons/buy1.png");
			buyTex2 = LoadTexture("res/Shop_buttons/buy2.png");
			buyState = true;

			font = LoadFont("res/Font/aAsianNinja.otf");

		}

		void drawShop(Vector2& mainSize, Vector2& mainPos, Texture2D& mainTex) {
#if _DEBUG
			DrawRectangleLines(static_cast<int>(mainPos.x), static_cast<int>(mainPos.y), static_cast<int>(mainSize.x), static_cast<int>(mainSize.y),
				ORANGE);
#endif
			DrawTexture(mainTex, static_cast<int>(mainPos.x), static_cast<int>(mainPos.y), WHITE);

		}

		void drawOpen(Vector2& openSize, Vector2& openPos, Texture2D& closeTex1, Texture2D& closeTex2, bool& openState) {
#if _DEBUG
			DrawRectangleLines(static_cast<int>(openPos.x), static_cast<int>(openPos.y), static_cast<int>(openSize.x), static_cast<int>(openSize.y),
				ORANGE);
#endif
			if (openState) {
				DrawTexture(closeTex1, static_cast<int>(openPos.x), static_cast<int>(openPos.y), WHITE);

			}
			else {
				DrawTexture(closeTex2, static_cast<int>(openPos.x), static_cast<int>(openPos.y), WHITE);
			}
		}

		void drawClose(Vector2& closeSize, Vector2& closePos, Texture2D& closeTex1, Texture2D& closeTex2, bool& closeState) {
#if _DEBUG
			DrawRectangleLines(static_cast<int>(closePos.x), static_cast<int>(closePos.y), static_cast<int>(closeSize.x), static_cast<int>(closeSize.y),
				RED);
#endif
			if (closeState) {
				DrawTexture(closeTex1, static_cast<int>(closePos.x), static_cast<int>(closePos.y), WHITE);
			}
			else {
				DrawTexture(closeTex2, static_cast<int>(closePos.x), static_cast<int>(closePos.y), WHITE);
			}

		}

		void drawLeftArrow(Vector2& leftArrowSize, Vector2& leftArrowPos, Texture2D& leftTex1, Texture2D& leftTex2, bool& leftState) {
#if _DEBUG

			DrawRectangleLines(static_cast<int>(leftArrowPos.x), static_cast<int>(leftArrowPos.y), static_cast<int>(leftArrowSize.x),
				static_cast<int>(leftArrowSize.y), RED);
#endif
			if (leftState) {
				DrawTexture(leftTex1, static_cast<int>(leftArrowPos.x), static_cast<int>(leftArrowPos.y) - drawTextureOffset, WHITE);
			}
			else {
				DrawTexture(leftTex2, static_cast<int>(leftArrowPos.x), static_cast<int>(leftArrowPos.y) - drawTextureOffset, WHITE);
			}
		}

		void drawRightArrow(Vector2& rightArrowSize, Vector2& rightArrowPos, Texture2D& rightTex1, Texture2D& rightTex2, bool& rightState) {
#if _DEBUG

			DrawRectangleLines(static_cast<int>(rightArrowPos.x), static_cast<int>(rightArrowPos.y), static_cast<int>(rightArrowSize.x),
				static_cast<int>(rightArrowSize.y), RED);
#endif
			if (rightState) {
				DrawTexture(rightTex1, static_cast<int>(rightArrowPos.x), static_cast<int>(rightArrowPos.y) - drawTextureOffset, WHITE);
			}
			else {
				DrawTexture(rightTex2, static_cast<int>(rightArrowPos.x), static_cast<int>(rightArrowPos.y) - drawTextureOffset, WHITE);
			}
		}

		void drawItem(Vector2& itemSize, Vector2& itemPos, int& item, Font& font, int& capasity, int& reach, int& evolution) {
			switch (item) {
			case 1:
#if _DEBUG

				DrawRectangleLines(static_cast<int>(itemPos.x), static_cast<int>(itemPos.y), static_cast<int>(itemSize.x),
					static_cast<int>(itemSize.y), BLUE);
#endif
				DrawTextEx(font, "Pres buy to train your mind ", { textPosX[0],textPosY[0] }, fonstSize, fontSpacing, textColor);
				DrawTextEx(font, "hand to catch more fish", { textPosX[0],textPosY[1] }, fonstSize, fontSpacing, textColor);
				switch (capasity) {
				case 1:
					DrawTextEx(font, TextFormat("QI: %i", price[0]), { textPosX[0],textPosY[2] }, fonstSizeBig, fontSpacing, qiColor);

					DrawTextEx(font, "1 / 4", { textPosX[1],textPosY[7] }, fonstSizeBig, fontSpacing, textColor);
					break;
				case 2:
					DrawTextEx(font, TextFormat("QI: %i", price[1]), { textPosX[0],textPosY[2] }, fonstSizeBig, fontSpacing, qiColor);

					DrawTextEx(font, "2 / 4", { textPosX[1],textPosY[7] }, fonstSizeBig, fontSpacing, textColor);
					break;
				case 3:
					DrawTextEx(font, TextFormat("QI: %i", price[2]), { textPosX[0],textPosY[2] }, fonstSizeBig, fontSpacing, qiColor);

					DrawTextEx(font, "3 / 4", { textPosX[1],textPosY[7] }, fonstSizeBig, fontSpacing, textColor);
					break;
				case 4:
					DrawTextEx(font, "A hand Worthy of the treasure", { textPosX[0],textPosY[2] }, fonstSize, fontSpacing, qiFinalStageColor);

					DrawTextEx(font, "4 / 4", { textPosX[1],textPosY[7] }, fonstSizeBig, fontSpacing, qiFinalStageColor);
					break;
				default:
					break;
				}

				break;
			case 2:
#if _DEBUG

				DrawRectangleLines(static_cast<int>(itemPos.x), static_cast<int>(itemPos.y), static_cast<int>(itemSize.x),
					static_cast<int>(itemSize.y), MAGENTA);
#endif
				DrawTextEx(font, "Pres buy to train your mind ", { textPosX[0],textPosY[0] }, fonstSize, fontSpacing, textColor);
				DrawTextEx(font, "reach to reach deeper waters", { textPosX[0],textPosY[1] }, fonstSize, fontSpacing, textColor);
				switch (reach) {
				case 1:
					DrawTextEx(font, TextFormat("QI: %i", price[3]), { textPosX[0],textPosY[2] }, fonstSizeBig, fontSpacing, qiColor);

					DrawTextEx(font, "1 / 4", { textPosX[1],textPosY[7] }, fonstSizeBig, fontSpacing, textColor);
					break;
				case 2:
					DrawTextEx(font, TextFormat("QI: %i", price[4]), { textPosX[0],textPosY[2] }, fonstSizeBig, fontSpacing, qiColor);

					DrawTextEx(font, "2 / 4", { textPosX[1],textPosY[7] }, fonstSizeBig, fontSpacing, textColor);
					break;
				case 3:
					DrawTextEx(font, TextFormat("QI: %i", price[5]), { textPosX[0],textPosY[2] }, fonstSizeBig, fontSpacing, qiColor);

					DrawTextEx(font, "3 / 4", { textPosX[1],textPosY[7] }, fonstSizeBig, fontSpacing, textColor);
					break;
				case 4:
					DrawTextEx(font, "A mind that will survive the ", { textPosX[0],textPosY[2] }, fonstSize, fontSpacing, qiFinalStageColor);
					DrawTextEx(font, "world", { textPosX[0],textPosY[3] }, fonstSize, fontSpacing, qiFinalStageColor);

					DrawTextEx(font, "4 / 4", { textPosX[1],textPosY[7] }, fonstSizeBig, fontSpacing, qiFinalStageColor);
					break;
				default:
					break;
				}
				break;
			case 3:
#if _DEBUG

				DrawRectangleLines(static_cast<int>(itemPos.x), static_cast<int>(itemPos.y), static_cast<int>(itemSize.x),
					static_cast<int>(itemSize.y), COLORALPHA);
#endif		
				switch (evolution) {
				case 1:
					DrawTextEx(font, "Focus a great amount of Qi", { textPosX[0],textPosY[0] }, fonstSize, fontSpacing, textColor);
					DrawTextEx(font, "into a golden core to reach", { textPosX[0],textPosY[1] }, fonstSize, fontSpacing, textColor);
					DrawTextEx(font, "your next stage of evolution", { textPosX[0],textPosY[2] }, fonstSize, fontSpacing, textColor);
					DrawTextEx(font, TextFormat("QI: %i", price[6]), { textPosX[0],textPosY[3] }, fonstSizeBig, fontSpacing, qiColor);

					DrawTextEx(font, "1 / 4", { textPosX[1],textPosY[7] }, fonstSizeBig, fontSpacing, textColor);
					break;
				case 2:
					DrawTextEx(font, "Focus a great amount of Qi", { textPosX[0],textPosY[0] }, fonstSize, fontSpacing, textColor);
					DrawTextEx(font, "your scales and claws to reach", { textPosX[0],textPosY[1] }, fonstSize, fontSpacing, textColor);
					DrawTextEx(font, "your next stage of evolution", { textPosX[0],textPosY[2] }, fonstSize, fontSpacing, textColor);
					DrawTextEx(font, TextFormat("QI: %i", price[7]), { textPosX[0],textPosY[3] }, fonstSizeBig, fontSpacing, qiColor);

					DrawTextEx(font, "2 / 4", { textPosX[1],textPosY[7] }, fonstSizeBig, fontSpacing, textColor);
					break;
				case 3: 		
					DrawTextEx(font, "No longer a sad fish but a", { textPosX[0],textPosY[0] }, fonstSize, fontSpacing, textColor);
					DrawTextEx(font, "perfect dragon,your body  ", { textPosX[0],textPosY[1] }, fonstSize, fontSpacing, textColor);
					DrawTextEx(font, "will survive the heavenly ", { textPosX[0],textPosY[2] }, fonstSize, fontSpacing, textColor);
					DrawTextEx(font, "tribulation, your are almost", { textPosX[0],textPosY[4] }, fonstSize, fontSpacing, textColor);
					DrawTextEx(font, "ready", { textPosX[0],textPosY[5] }, fonstSize, fontSpacing, textColor);
					DrawTextEx(font, TextFormat("QI: %i", price[8]), { textPosX[0],textPosY[6] }, fonstSizeBig, fontSpacing, qiColor);

					DrawTextEx(font, "3 / 4", { textPosX[1],textPosY[7] }, fonstSizeBig, fontSpacing, textColor);
					break;
				case 4:
					DrawTextEx(font, "Finish your training", { textPosX[0],textPosY[0] }, fonstSize, fontSpacing, textColor);
					DrawTextEx(font, "Reach forthe lost treasure", { textPosX[0],textPosY[1] }, fonstSize, fontSpacing, textColor);
					DrawTextEx(font, "Free yourself from this ocean", { textPosX[0],textPosY[2] }, fonstSize, fontSpacing, qiFinalStageColor);

					DrawTextEx(font, "4 / 4", { textPosX[1],textPosY[7] }, fonstSizeBig, fontSpacing, qiFinalStageColor);
					break;
				default:
					break;
				}

				break;
			default:
				break;
			}
		}

		void increaseItem(int& item) {
			if (item < 3) {
				item++;
				std::cout << item << std::endl;
			}
		}

		void decreaseItem(int& item) {
			if (item > 1) {
				item--;
				std::cout << item << std::endl;
			}
		}

		void drawBuy(Vector2& butSize, Vector2& buyPos, Texture2D& buyTex1, Texture2D& buyTex2, bool& buytState) {
#if _DEBUG

			DrawRectangleLines(static_cast<int>(buyPos.x), static_cast<int>(buyPos.y), static_cast<int>(butSize.x),
				static_cast<int>(butSize.y), RED);
#endif
			if (buytState) {
				DrawTexture(buyTex1, static_cast<int>(buyPos.x), static_cast<int>(buyPos.y) - drawTextureOffset, WHITE);
			}
			else {
				DrawTexture(buyTex2, static_cast<int>(buyPos.x), static_cast<int>(buyPos.y) - drawTextureOffset, WHITE);
			}
		}

		void upgradeItem(int& item, int& capasity, int& reach, int& points, int& evolution) {
			switch (item) {
			case 1:
				switch (capasity) {
				case 1:
					if (points > price[0]) {
						std::cout << " it works" << std::endl;

						capasity = 2;
						points = points - price[0];
					}
					break;
				case 2:
					if (points > price[1]) {
						std::cout << " it works" << std::endl;

						capasity = 3;
						points = points - price[1];
					}
					break;
				case 3:
					if (points > price[2]) {
						std::cout << " it works" << std::endl;

						capasity = 4;
						points = points - price[2];
					}
				case 4:
					capasity = 4;

					break;
				default:
					break;
				}
				break;
			case 2:
				switch (reach) {
				case 1:
					if (points > price[3]) {
						std::cout << " it works2" << std::endl;

						reach = 2;
						points = points - price[3];
					}
					break;
				case 2:
					if (points > price[4]) {
						std::cout << " it works2" << std::endl;

						reach = 3;
						points = points - price[4];
					}
					break;
				case 3:
					if (points > price[5]) {
						std::cout << " it works2" << std::endl;

						reach = 4;
						points = points - price[5];
					}
					break;
				case 4:
					std::cout << " it works4" << std::endl;

					reach = 4;

					break;
				default:
					break;
				}
				break;
			case 3:
				switch (evolution) {
				case 1:
					if (points > price[6]) {
						std::cout << " it works2" << std::endl;

						evolution = 2;
						points = points - price[6];
					}
					break;
				case 2:
					if (points > price[7]) {
						std::cout << " it works2" << std::endl;

						evolution = 3;
						points = points - price[7];
					}
					break;
				case 3:
					if (points > price[8]) {
						std::cout << " it works2" << std::endl;

						evolution = 4;
						points = points - price[8];
					}
					break;
				case 4:
					std::cout << " it works4" << std::endl;

					evolution = 4;

					break;
				default:
					break;
				}

				break;
			default:
				break;
			}
		}
	}
}