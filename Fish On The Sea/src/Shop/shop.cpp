#include "shop.h"

#include <iostream>
namespace fish {
	namespace shop {

		int fonstSize = 25;
		int fonstSizeBig = 40;
		int fonstSeparation = 3;

		void initShop(Vector2& mainSize, Vector2& mainPos, Vector2& openSize, Vector2& openPos, Vector2& closeSize, Vector2& closePos,
			Vector2& leftArrowSize, Vector2& leftArrowPos, Vector2& rightArrowSize, Vector2& rightArrowPos, Vector2& itemSize, Vector2& itemPos,
			int& item, Vector2& buySize, Vector2& buyPos, Texture2D& CloseTex1, Texture2D& CloseTex2, Texture2D& mainTex, Texture2D& leftTex1,
			Texture2D& leftTex2,Texture2D& rightTex1, Texture2D& rightTex2, Texture2D& buyTex1, Texture2D& buyTex2, 
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
			DrawRectangleLines(static_cast<int>(mainPos.x), static_cast<int>(mainPos.y), static_cast<int>(mainSize.x), static_cast<int>(mainSize.y), ORANGE);
#endif
			DrawTexture(mainTex, static_cast<int>(mainPos.x), static_cast<int>(mainPos.y), WHITE);

		}

		void drawOpen(Vector2& openSize, Vector2& openPos, Texture2D& closeTex1, Texture2D& closeTex2, bool& openState) {
#if _DEBUG
			DrawRectangleLines(static_cast<int>(openPos.x), static_cast<int>(openPos.y), static_cast<int>(openSize.x), static_cast<int>(openSize.y), ORANGE);
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
			DrawRectangleLines(static_cast<int>(closePos.x), static_cast<int>(closePos.y), static_cast<int>(closeSize.x), static_cast<int>(closeSize.y), RED);
#endif
			if (closeState) {
				DrawTexture(closeTex1, static_cast<int>(closePos.x), static_cast<int>(closePos.y), WHITE);
			}
			else {
				DrawTexture(closeTex2, static_cast<int>(closePos.x), static_cast<int>(closePos.y), WHITE);
			}

		}

		void drawLeftArrow(Vector2& leftArrowSize, Vector2& leftArrowPos, Texture2D& leftTex1, Texture2D& leftTex2, bool& leftState){
#if _DEBUG

			DrawRectangleLines(static_cast<int>(leftArrowPos.x), static_cast<int>(leftArrowPos.y), static_cast<int>(leftArrowSize.x),
				static_cast<int>(leftArrowSize.y), RED);
#endif
			if (leftState) {
				DrawTexture(leftTex1, static_cast<int>(leftArrowPos.x), static_cast<int>(leftArrowPos.y) - 43, WHITE);
			}
			else {
				DrawTexture(leftTex2, static_cast<int>(leftArrowPos.x), static_cast<int>(leftArrowPos.y) - 43, WHITE);
			}
		}

		void drawRightArrow(Vector2& rightArrowSize, Vector2& rightArrowPos, Texture2D& rightTex1, Texture2D& rightTex2, bool& rightState) {
#if _DEBUG

			DrawRectangleLines(static_cast<int>(rightArrowPos.x), static_cast<int>(rightArrowPos.y), static_cast<int>(rightArrowSize.x),
				static_cast<int>(rightArrowSize.y), RED);
#endif
			if (rightState) {
				DrawTexture(rightTex1, static_cast<int>(rightArrowPos.x), static_cast<int>(rightArrowPos.y) - 43, WHITE);
			}
			else {
				DrawTexture(rightTex2, static_cast<int>(rightArrowPos.x), static_cast<int>(rightArrowPos.y) - 43, WHITE);
			}
		}

		void drawItem(Vector2& itemSize, Vector2& itemPos, int& item, Font& font, int& capasity, int& reach, int& evolution) {
			switch (item) {
			case 1:
				DrawRectangleLines(static_cast<int>(itemPos.x), static_cast<int>(itemPos.y), static_cast<int>(itemSize.x),
					static_cast<int>(itemSize.y), BLUE);
				DrawTextEx(font, "Pres buy to train your mind ", { 70,135 }, fonstSize, fonstSeparation, BLACK);
				DrawTextEx(font, "hand to catch more fish", { 70,160 }, fonstSize, fonstSeparation, BLACK);
				switch (capasity){
					case 1:
						DrawTextEx(font, "1 / 4", { 220,400 }, fonstSizeBig, fonstSeparation, BLACK);
						break;
					case 2:
						DrawTextEx(font, "2 / 4", { 220,400 }, fonstSizeBig, fonstSeparation, BLACK);
						break;
					case 3:
						DrawTextEx(font, "3 / 4", { 220,400 }, fonstSizeBig, fonstSeparation, BLACK);
						break;
					case 4:
						DrawTextEx(font, "A hand Worthy of the treasure", { 70,185 }, fonstSize, fonstSeparation, GOLD);

						DrawTextEx(font, "4 / 4", { 220,400 }, fonstSizeBig, fonstSeparation, GOLD);
						break;
				default:
					break;
				}

				break;
			case 2:
				DrawRectangleLines(static_cast<int>(itemPos.x), static_cast<int>(itemPos.y), static_cast<int>(itemSize.x),
					static_cast<int>(itemSize.y), MAGENTA);
				DrawTextEx(font, "Pres buy to train your mind ", { 70,135 }, fonstSize, fonstSeparation, BLACK);
				DrawTextEx(font, "reach to reach deeper waters", { 70,160 }, fonstSize, fonstSeparation, BLACK);
				switch (reach) {
				case 1:
					DrawTextEx(font, "1 / 4", { 220,400 }, fonstSizeBig, fonstSeparation, BLACK);
					break;
				case 2:
					DrawTextEx(font, "2 / 4", { 220,400 }, fonstSizeBig, fonstSeparation, BLACK);
					break;
				case 3:
					DrawTextEx(font, "3 / 4", { 220,400 }, fonstSizeBig, fonstSeparation, BLACK);
					break;
				case 4:
					DrawTextEx(font, "A mind that will survive the ", { 70,185 }, fonstSize, fonstSeparation, GOLD);
					DrawTextEx(font, "world", { 70,210 }, fonstSize, fonstSeparation, GOLD);

					DrawTextEx(font, "4 / 4", { 220,400 }, fonstSizeBig, fonstSeparation, GOLD);
					break;
				default:
					break;
				}
				break;
			case 3:
				DrawRectangleLines(static_cast<int>(itemPos.x), static_cast<int>(itemPos.y), static_cast<int>(itemSize.x),
					static_cast<int>(itemSize.y), COLORALPHA);
			
				switch (evolution) {
				case 1:
					DrawTextEx(font, "Focus a great amount of Qi", { 70,135 }, fonstSize, fonstSeparation, BLACK);
					DrawTextEx(font, "into a golden core to reach", { 70,160 }, fonstSize, fonstSeparation, BLACK);
					DrawTextEx(font, "your next stage of evolution", { 70,185 }, fonstSize, fonstSeparation, BLACK);
					
					DrawTextEx(font, "1 / 4", { 220,400 }, fonstSizeBig, fonstSeparation, BLACK);
					break;
				case 2:
					DrawTextEx(font, "Focus a great amount of Qi", { 70,135 }, fonstSize, fonstSeparation, BLACK);
					DrawTextEx(font, "your scales and claws to reach", { 70,160 }, fonstSize, fonstSeparation, BLACK);
					DrawTextEx(font, "your next stage of evolution", { 70,185 }, fonstSize, fonstSeparation, BLACK);

					DrawTextEx(font, "2 / 4", { 220,400 }, fonstSizeBig, fonstSeparation, BLACK);
					break;
				case 3:
					DrawTextEx(font, "No longer a sad fish but a", { 70,135 }, fonstSize, fonstSeparation, BLACK);
					DrawTextEx(font, "perfect dragon,your body  ", { 70,160 }, fonstSize, fonstSeparation, BLACK);
					DrawTextEx(font, "will survive the heavenly ", { 70,185 }, fonstSize, fonstSeparation, BLACK);
					DrawTextEx(font, "tribulation, your are almost", { 70,215 }, fonstSize, fonstSeparation, BLACK);
					DrawTextEx(font, "ready", { 70,240 }, fonstSize, fonstSeparation, BLACK);

					DrawTextEx(font, "3 / 4", { 220,400 }, fonstSizeBig, fonstSeparation, BLACK);
					break;
				case 4:
					DrawTextEx(font, "Finish your training", { 70,135 }, fonstSize, fonstSeparation, BLACK);
					DrawTextEx(font, "Reach forthe lost treasure", { 70,160 }, fonstSize, fonstSeparation, BLACK);
					DrawTextEx(font, "Free yourself from this ocean", { 70,185 }, fonstSize, fonstSeparation, GOLD);

					DrawTextEx(font, "4 / 4", { 220,400 }, fonstSizeBig, fonstSeparation, GOLD);
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
				DrawTexture(buyTex1, static_cast<int>(buyPos.x), static_cast<int>(buyPos.y) - 43, WHITE);
			}
			else {
				DrawTexture(buyTex2, static_cast<int>(buyPos.x), static_cast<int>(buyPos.y) - 43, WHITE);
			}
		}

		void upgradeItem(int& item, int& capasity, int& reach, int& points, int& evolution) {
			switch (item) {
			case 1:
				switch (capasity) {
				case 1:
					if (points > 100) {
						std::cout << " it works" << std::endl;

						capasity = 2;
						points = points - 50;
					}
					break;
				case 2:
					if (points > 500) {
						std::cout << " it works" << std::endl;

						capasity = 3;
						points = points - 50;
					}
					break;
				case 3:
					if (points > 1500) {
						std::cout << " it works" << std::endl;

						capasity = 4;
						points = points - 50;
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
					if (points > 600) {
						std::cout << " it works2" << std::endl;

						reach = 2;
						points = points - 50;
					}
					break;
				case 2:
					if (points > 1500) {
						std::cout << " it works2" << std::endl;

						reach = 3;
						points = points - 50;
					}
					break;
				case 3:
					if (points > 2000) {
						std::cout << " it works2" << std::endl;

						reach = 4;
						points = points - 50;
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
					if (points > 100) {
						std::cout << " it works2" << std::endl;

						evolution = 2;
						points = points - 50;
					}
					break;
				case 2:
					if (points > 2000) {
						std::cout << " it works2" << std::endl;

						evolution = 3;
						points = points - 50;
					}
					break;
				case 3:
					if (points > 3000) {
						std::cout << " it works2" << std::endl;

						evolution = 4;
						points = points - 50;
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