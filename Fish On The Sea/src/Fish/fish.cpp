#include "fish.h"

#include <iostream>
namespace fish {
	namespace fishs {

		static int speed = 100;

		void initFish(Vector2& fishSize, Vector2& fishPosition, bool& active, int& type, bool& dir, Texture2D& small1, Texture2D& small2,
			Texture2D& medium1, Texture2D& medium2, Texture2D& big1, Texture2D& big2) {
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
			small1 = LoadTexture("res/Fish_textures/fish_S2.png");
			small2 = LoadTexture("res/Fish_textures/fish_S2_invert.png");

			medium1 = LoadTexture("res/Fish_textures/fish_M2.png");
			medium2 = LoadTexture("res/Fish_textures/fish_M2_invert.png");

			big1 = LoadTexture("res/Fish_textures/fish_L3.png");
			big2 = LoadTexture("res/Fish_textures/fish_L3_invert.png");

			switch (type) {
			case 1:
				fishSize = { static_cast<float>(GetScreenWidth()) / 6,static_cast<float>(GetScreenWidth()) / 10 };
				break;
			case 2:
				fishSize = { static_cast<float>(GetScreenWidth()) / 7 /*20*/,static_cast<float>(GetScreenWidth()) / 20 };

				break;
			case 3:
				fishSize = { static_cast<float>(GetScreenWidth()) / 30,static_cast<float>(GetScreenWidth()) / 30 };
				break;
			default:
				break;
			}

			temp = GetRandomValue(0, GetScreenWidth() - static_cast<int>(fishSize.x));
			temp2 = GetRandomValue(GetScreenHeight(), GetScreenHeight() * 2 - static_cast<int>(fishSize.y));
			fishPosition = { static_cast<float>(temp), static_cast<float>(temp2) };

		}

		void initFish2(Vector2& fishSize, Vector2& fishPosition, bool& active, int& type, bool& dir, Texture2D& small1, Texture2D& small2,
			Texture2D& medium1, Texture2D& medium2, Texture2D& big1, Texture2D& big2) {
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
			small1 = LoadTexture("res/Fish_textures/fish_S1.png");
			small2 = LoadTexture("res/Fish_textures/fish_S1_invert.png");

			medium1 = LoadTexture("res/Fish_textures/fish_M1.png");
			medium2 = LoadTexture("res/Fish_textures/fish_M1_invert.png");

			big1 = LoadTexture("res/Fish_textures/fish_L1.png");
			big2 = LoadTexture("res/Fish_textures/fish_L1_invert.png");

			switch (type) {
			case 1:
				fishSize = { static_cast<float>(GetScreenWidth()) / 6,static_cast<float>(GetScreenWidth()) / 10 };
				break;
			case 2:
				fishSize = { static_cast<float>(GetScreenWidth()) / 7 /*20*/,static_cast<float>(GetScreenWidth()) / 20 };

				break;
			case 3:
				fishSize = { static_cast<float>(GetScreenWidth()) / 30,static_cast<float>(GetScreenWidth()) / 30 };
				break;
			default:
				break;
			}

			temp = GetRandomValue(0, GetScreenWidth() - static_cast<int>(fishSize.x));
			temp2 = GetRandomValue(GetScreenHeight() * 2 - static_cast<int>(fishSize.y), GetScreenHeight() * 3 - static_cast<int>(fishSize.y));
			fishPosition = { static_cast<float>(temp), static_cast<float>(temp2) };

		}

		void initFish3(Vector2& fishSize, Vector2& fishPosition, bool& active, int& type, bool& dir, Texture2D& small1, Texture2D& small2,
			Texture2D& medium1, Texture2D& medium2, Texture2D& big1, Texture2D& big2) {
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
			small1 = LoadTexture("res/Fish_textures/fish_S3.png");
			small2 = LoadTexture("res/Fish_textures/fish_S3_invert.png");

			medium1 = LoadTexture("res/Fish_textures/fish_M3.png");
			medium2 = LoadTexture("res/Fish_textures/fish_M3_invert.png");

			big1 = LoadTexture("res/Fish_textures/fish_L2.png");
			big2 = LoadTexture("res/Fish_textures/fish_L2_invert.png");

			switch (type) {
			case 1:
				fishSize = { static_cast<float>(GetScreenWidth()) / 6,static_cast<float>(GetScreenWidth()) / 10 };
				break;
			case 2:
				fishSize = { static_cast<float>(GetScreenWidth()) / 7 /*20*/,static_cast<float>(GetScreenWidth()) / 20 };

				break;
			case 3:
				fishSize = { static_cast<float>(GetScreenWidth()) / 30,static_cast<float>(GetScreenWidth()) / 30 };
				break;
			default:
				break;
			}


			temp = GetRandomValue(0, GetScreenWidth() - static_cast<int>(fishSize.x));
			temp2 = GetRandomValue(GetScreenHeight() * 3 - static_cast<int>(fishSize.y), GetScreenHeight() * 4 - static_cast<int>(fishSize.y));
			fishPosition = { static_cast<float>(temp), static_cast<float>(temp2) };

		}
		void movement(float& fishPosX, float& fishWidth, bool& dir) {
			if (dir == true) {
				fishPosX -= speed * GetFrameTime();
			}
			else {
				fishPosX += speed * GetFrameTime();

			}

			if (fishPosX <= 0 || fishPosX >= static_cast<float>(GetScreenWidth()) - (fishWidth + fishWidth / 2)) {
				if (dir == true) {
					fishPosX = 0;
				}
				else {
					fishPosX = static_cast<float>(GetScreenWidth()) - (fishWidth + fishWidth / 2) ;

				}
				dir = !dir;
			}
		}

		void drawFish(float& fishPosX, float& fishPosY, float& fishSizeX, float& fishSizeY, int& type, bool& dir, Texture2D& small1, Texture2D& small2,
			Texture2D& medium1, Texture2D& medium2, Texture2D& big1, Texture2D& big2) {

			switch (type) {
			case 1:
				if (dir) {
					DrawTexture(big1, static_cast<int>(fishPosX), static_cast<int>(fishPosY) - 5, WHITE);
				}
				else {
					DrawTexture(big2, static_cast<int>(fishPosX), static_cast<int>(fishPosY) - 5, WHITE);
				}
#if _DEBUG
				DrawRectangleLines(static_cast<int>(fishPosX), static_cast<int>(fishPosY), static_cast<int>(fishSizeX), static_cast<int>(fishSizeY), YELLOW);
#endif
				break;
			case 2:
				if (dir) {
					DrawTexture(medium1, static_cast<int>(fishPosX), static_cast<int>(fishPosY) - 5, WHITE);
				}
				else {
					DrawTexture(medium2, static_cast<int>(fishPosX), static_cast<int>(fishPosY) - 5, WHITE);
				}
#if _DEBUG
				DrawRectangleLines(static_cast<int>(fishPosX), static_cast<int>(fishPosY), static_cast<int>(fishSizeX), static_cast<int>(fishSizeY), RED);
#endif
				break;
			case 3:
				if (dir) {
					DrawTexture(small1, static_cast<int>(fishPosX) - 15, static_cast<int>(fishPosY) - 5, WHITE);
				}
				else {
					DrawTexture(small2, static_cast<int>(fishPosX) - 15, static_cast<int>(fishPosY) - 5, WHITE);
				}
#if _DEBUG
				DrawRectangleLines(static_cast<int>(fishPosX), static_cast<int>(fishPosY), static_cast<int>(fishSizeX), static_cast<int>(fishSizeY), BLUE);
#endif
				break;
			default:
				break;
			}

		}

		void deactivate(bool& active, int& points, int& type) {

			switch (type) {
			case 1:
				points += 10;
				break;
			case 2:
				points += 20;
				break;
			case 3:
				points += 30;
				break;
			default:
				break;
			}
			active = !active;
		}

		void deactivate2(bool& active, int& points, int& type) {

			switch (type) {
			case 1:
				points += 60;
				break;
			case 2:
				points += 80;
				break;
			case 3:
				points += 100;
				break;
			default:
				break;
			}
			active = !active;
		}

		void deactivate3(bool& active, int& points, int& type) {

			switch (type) {
			case 1:
				points += 100;
				break;
			case 2:
				points += 150;
				break;
			case 3:
				points += 200;
				break;
			default:
				break;
			}
			active = !active;
		}
	}
}