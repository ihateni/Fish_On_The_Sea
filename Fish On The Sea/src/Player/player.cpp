#include "player.h"

namespace fish {
	namespace player {
		int direction;

		void initPlayer(Vector2& size, Vector2& position) {
			size = { static_cast<float>(GetScreenWidth()) / 15,static_cast<float>(GetScreenHeight()) / 15 };
			position = { static_cast<float>(GetScreenWidth()) / 2 - size.x / 2, static_cast<float>(GetScreenHeight()) / 2 - size.y / 2 };
		}

		void fall(float& playerPosY) {
			playerPosY += 100 * GetFrameTime();
		}

		void movement(float& playerPosX) {
			direction = GetMouseX() - playerPosX;
			playerPosX = playerPosX + direction * GetFrameTime();
		}

		void ascension(float& playerPosY) {
			playerPosY -= 10 * GetFrameTime();

		}
	}
}