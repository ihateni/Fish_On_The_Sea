#include "victory.h"

#include "raylib.h"

#include "Game Manager/manager.h"

namespace fish {
	namespace victory {
		static void victoryDraw();

		static Rectangle rec1CR;

		static bool backState;
		static Texture2D background;
		static Texture2D backButton1;
		static Texture2D backButton2;

		static Font font;
		static	Sound click;

		static int textureOffset = 45;
		static float textPosX[] = {23};
		static float textPosY[] = { 511, 531 };
		static float fontSize = 26;
		static float fontSpacing = 3;

		void victoryInit() {
			click = LoadSound("res/Sound/mixkit-unlock-game-notification-253.wav");

			rec1CR.width = (static_cast<float> (GetScreenWidth()) - ((static_cast<float>(GetScreenWidth()) / 10) * 2)) / 3;
			rec1CR.height = (static_cast<float> (GetScreenHeight()) - ((static_cast<float>(GetScreenHeight()) / 10) * 2)) / 15;
			rec1CR.x = 10;
			rec1CR.y = 10;

			backState = true;

			background = LoadTexture("res/Background/sprite_northWindShrineBG - copia.png");
			backButton1 = LoadTexture("res/Control_buttons/menu1.png");
			backButton2 = LoadTexture("res/Control_buttons/menu2.png");


			font = LoadFont("res/Font/aAsianNinja.otf");

		}

		void victoryUpdate() {
			victoryDraw();

			if (CheckCollisionPointRec(GetMousePosition(), rec1CR)) {
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
					backState = false;
				}
				else {
					backState = true;
				}

				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
					gameManager::Screens = gameManager::GameScreen::Menu;
					PlaySound(click);

				}
			}
			else {
				backState = true;

			}
		}

		void victoryDraw() {
			BeginDrawing();
			ClearBackground(RAYWHITE);

			DrawTexture(background, 0, 0, WHITE);


			if (backState) {
				DrawTexture(backButton1, static_cast<int>(rec1CR.x), static_cast<int>(rec1CR.y) - textureOffset, WHITE);
			}
			else {
				DrawTexture(backButton2, static_cast<int>(rec1CR.x), static_cast<int>(rec1CR.y) - textureOffset, WHITE);
			}
			DrawTextEx(font, "You are free from the ocean!", { textPosX[0],textPosY[0] }, fontSize, fontSpacing, RED);
			DrawTextEx(font, "Thanks for playing", { textPosX[0],textPosY[1] }, fontSize, fontSpacing, RED);

			EndDrawing();
		}

		void victoryDeInit() {
			UnloadTexture(background);
			UnloadTexture(backButton1);
			UnloadTexture(backButton2);

			UnloadFont(font);
			UnloadSound(click);

		}
	}
}