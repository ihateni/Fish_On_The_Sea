#include "player.h"

namespace fish {
	namespace player {
		int direction;

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