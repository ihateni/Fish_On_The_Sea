#include "fish.h"

#include <iostream>

namespace fish {
	namespace fishs {

		void initFish(Vector2& fishSize, Vector2& fishPosition,bool& active, bool& type, bool& dir){
			int temp = GetRandomValue(1, 2);
			fishSize = { static_cast<float>(GetScreenWidth()) / 15,static_cast<float>(GetScreenHeight()) / 15 };
			active = true;
			if (temp == 1){
				dir = true;
			}
			else {
				dir = false;
			}
			type = true;
			temp = GetRandomValue(0,GetScreenWidth() - fishSize.x);

			fishPosition = { static_cast<float>(temp), static_cast<float>(GetScreenHeight() + temp) };

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

		void drawFish(float& fishPosX, float& fishPosY, float& fishSizeX, float& fishSizeY) {
			DrawRectangle(static_cast<int>(fishPosX), static_cast<int>(fishPosY), static_cast<int>(fishSizeX), static_cast<int>(fishSizeY), YELLOW);

		}

		void deactivate(bool& active) {
			active = !active;
		}
	}
}