#include "fish.h"

namespace fish {
	namespace fishs {

		int temp = GetRandomValue(1, 2);
		void initFish(Vector2& fishSize, Vector2& fishPosition,bool& active, bool& type, bool& dir){
			fishSize = { static_cast<float>(GetScreenWidth()) / 15,static_cast<float>(GetScreenHeight()) / 15 };
			fishPosition = { static_cast<float>(GetScreenWidth()) / 2 - fishSize.x / 2, static_cast<float>(GetScreenHeight()) + fishSize.y * 2 };
			active = true;
			if (temp == 1){
				dir = true;
			}
			else {
				dir = false;
			}
			type = true;
		}

		void movement(float& fishPosX,float& fishWidth, bool& dir) {
			if (dir == true) {
				fishPosX -= 50 * GetFrameTime();
			}
			else {
				fishPosX += 50 * GetFrameTime();

			}

			if (fishPosX <= 0 || fishPosX >= static_cast<float>(GetScreenWidth()) - fishWidth) {
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