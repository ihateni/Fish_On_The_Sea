#include "fish.h"

#include <iostream>

namespace fish {
	namespace fishs {

		void initFish(Vector2& fishSize, Vector2& fishPosition,bool& active, int& type, bool& dir) {
			int temp = GetRandomValue(1, 2);
			int temp2;
			type = GetRandomValue(1, 3);
			active = true;
			if (temp == 1) {
				dir = true;
			}
			else {
				dir = false;
			}

			switch (type) {
			case 1:
				fishSize = { static_cast<float>(GetScreenWidth()) / 10,static_cast<float>(GetScreenHeight()) / 10 };
				break;
			case 2:
				fishSize = { static_cast<float>(GetScreenWidth()) / 20,static_cast<float>(GetScreenHeight()) / 20 };
				break;
			case 3:		
				fishSize = { static_cast<float>(GetScreenWidth()) / 15,static_cast<float>(GetScreenHeight()) / 30 };
				break;
			default:
				break;
			}
		
			temp = GetRandomValue(0,GetScreenWidth() - fishSize.x);
			temp2 = GetRandomValue(GetScreenHeight(), GetScreenHeight() * 2 - fishSize.y);
			fishPosition = { static_cast<float>(temp), static_cast<float>(temp2) };

		}

		void movement(float& fishPosX,float& fishWidth, bool& dir) {
			if (dir == true) {
				fishPosX -= 50 * GetFrameTime();
			}
			else {
				fishPosX += 50 * GetFrameTime();

			}

			if (fishPosX <= 0 || fishPosX >= static_cast<float>(GetScreenWidth()) - (fishWidth + fishWidth/3)) {
				dir = !dir;
			}
		}

		void drawFish(float& fishPosX, float& fishPosY, float& fishSizeX, float& fishSizeY, int& type) {

			switch (type) {
			case 1:
				DrawRectangle(static_cast<int>(fishPosX), static_cast<int>(fishPosY), static_cast<int>(fishSizeX), static_cast<int>(fishSizeY), YELLOW);
				break;
			case 2:
				DrawRectangle(static_cast<int>(fishPosX), static_cast<int>(fishPosY), static_cast<int>(fishSizeX), static_cast<int>(fishSizeY), RED);
				break;
			case 3:
				DrawRectangle(static_cast<int>(fishPosX), static_cast<int>(fishPosY), static_cast<int>(fishSizeX), static_cast<int>(fishSizeY), BLUE);
				break;
			default:
				break;
			}

		}

		void deactivate(bool& active) {
			active = !active;
		}
	}
}