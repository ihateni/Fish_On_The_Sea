#include "fish.h"

namespace fish {
	namespace fishs {

		void initFish(Vector2& size, Vector2& position) {
			size = { static_cast<float>(GetScreenWidth()) / 15,static_cast<float>(GetScreenHeight()) / 15 };
			position = { static_cast<float>(GetScreenWidth()) / 2 - size.x / 2, static_cast<float>(GetScreenHeight()) / 2 - size.y / 2 };
		}

		void movement(float& fishPosX) {

		}
	}
}