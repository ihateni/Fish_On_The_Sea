#include "player.h"

#include <iostream>
namespace fish {
	namespace player {
		float  direction;

		void initPlayer(Vector2& size, Vector2& position, int& capacity, int& reach, Texture2D& playerTex) {
			size = { 40, 40};

			position = { static_cast<float>(GetScreenWidth()) / 2 - size.x / 2, static_cast<float>(GetScreenHeight()) / 2 - size.y / 2 };
			capacity = 1;
			reach = 1;
			playerTex= LoadTexture("res/hand.png");
		}

		void movement(float& playerPosX) {
			direction = GetMouseX() - playerPosX;
			playerPosX = playerPosX + direction * GetFrameTime();
		}

		void fall(float& playerPosY) {
			playerPosY += 500 * GetFrameTime();
		}

		void ascension(float& playerPosY) {
			playerPosY -= 200 * GetFrameTime();

		}

		void drawPlayer(float& playerPosX, float& playerPosY, float& playerSizeX, float& playerSizey, Texture2D& playerTex) {
#if _DEBUG
			DrawRectangleLines(static_cast<int>(playerPosX), static_cast<int>(playerPosY), static_cast<int>(playerSizeX), static_cast<int>(playerSizey), BLACK);
#endif
			DrawTexture(playerTex, static_cast<int>(playerPosX), static_cast<int>(playerPosY) , WHITE);

		}
	}
}