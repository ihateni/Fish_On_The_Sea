#include "player.h"

#include <iostream>
namespace fish {
	namespace player {
		float  direction;
		int evoY = 100;

		void initPlayer(Vector2& size, Vector2& position, int& capacity, int& reach, int& evolution, Texture2D& playerTex, Texture2D& evoTex1
			, Texture2D& evoTex2, Texture2D& evoTex3) {
			size = { 40, 40};

			position = { static_cast<float>(GetScreenWidth()) / 2 - size.x / 2, static_cast<float>(GetScreenHeight()) / 2 - size.y / 2 };
			capacity = 1;
			reach = 1;
			evolution = 1;
			playerTex = LoadTexture("res/Player/hand.png");

			evoTex1 = LoadTexture("res/Player/main1.png");
			evoTex2 = LoadTexture("res/Player/main2.png");
			evoTex3 = LoadTexture("res/Player/main3.png");

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

		void drawPlayer(float& playerPosX, float& playerPosY, float& playerSizeX, float& playerSizey, Texture2D& playerTex, Texture2D& evoTex1
			, Texture2D& evoTex2, Texture2D& evoTex3, int& evolution) {
#if _DEBUG
			DrawRectangleLines(static_cast<int>(playerPosX), static_cast<int>(playerPosY), static_cast<int>(playerSizeX), static_cast<int>(playerSizey), BLACK);
#endif
			switch (evolution)
			{
			case 1:
				DrawTexture(evoTex1, static_cast<int>(playerPosX) - static_cast<int>(playerPosX) / 5, evoY, WHITE);

				break;
			case 2:
				DrawTexture(evoTex2, static_cast<int>(playerPosX) - static_cast<int>(playerPosX) / 5, evoY, WHITE);

				break;
			case 3:
				DrawTexture(evoTex3, static_cast<int>(playerPosX) - static_cast<int>(playerPosX) / 2, evoY, WHITE);

				break;
			case 4:
				DrawTexture(evoTex3, static_cast<int>(playerPosX) - static_cast<int>(playerPosX) / 2, evoY, WHITE);

				break;
			default:
				break;
			}
			
			DrawTexture(playerTex, static_cast<int>(playerPosX), static_cast<int>(playerPosY) , WHITE);

		}
	}
}