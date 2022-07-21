#include "controls.h"

#include "raylib.h"

#include "Game Manager/manager.h"

namespace fish {
	namespace controls {
		static void controlsDraw();

		static Rectangle rec1CR;

		static bool backState;
		static Texture2D background;
		static Texture2D backButton1;
		static Texture2D backButton2;
		static Texture2D box;

		static Font font;
		static	Sound click;

		static int textureOffset = 45;
		static float textPosX[] = { 23 };
		static float textPosY[] = { 70, 95, 140, 160, 232, 324, 344, 419, 440, 511, 531 };
		static int fontSize = 26;
		static int fontSpacing = 3;

		void controlsInit() {
			click = LoadSound("res/Sound/mixkit-unlock-game-notification-253.wav");

			rec1CR.width = (static_cast<float> (GetScreenWidth()) - ((static_cast<float>(GetScreenWidth()) / 10) * 2)) / 3;
			rec1CR.height = (static_cast<float> (GetScreenHeight()) - ((static_cast<float>(GetScreenHeight()) / 10) * 2)) / 15;
			rec1CR.x = 10;
			rec1CR.y = 10;

			backState = true;

			background = LoadTexture("res/Background/Background.png");
			backButton1 = LoadTexture("res/Control_buttons/menu1.png");
			backButton2 = LoadTexture("res/Control_buttons/menu2.png");

			box = LoadTexture("res/Control_buttons/box_large.png");

			font = LoadFont("res/Font/aAsianNinja.otf");

		}

		void controlsUpdate() {
			controlsDraw();

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

		void controlsDraw() {
			BeginDrawing();
			ClearBackground(RAYWHITE);

			DrawTexture(background, 0, 0, WHITE);

			DrawRectangleLines(static_cast<int>(rec1CR.x), static_cast<int>(rec1CR.y), static_cast<int>(rec1CR.width), static_cast<int>(rec1CR.height),
				BLACK);
			DrawTexture(box, 0, 0, WHITE);

			if (backState) {
				DrawTexture(backButton1, static_cast<int>(rec1CR.x), static_cast<int>(rec1CR.y) - textureOffset, WHITE);
			}
			else {
				DrawTexture(backButton2, static_cast<int>(rec1CR.x), static_cast<int>(rec1CR.y) - textureOffset, WHITE);
			}

			DrawTextEx(font, "Use your mind hand to collect fish", { textPosX[0],textPosY[0] }, fontSize, fontSpacing, BLACK);
			DrawTextEx(font, "this will turn the fish into QI points", { textPosX[0],textPosY[1] }, fontSize, fontSpacing, BLACK);
			DrawTextEx(font, "Different fish give different QI", { textPosX[0],textPosY[2] }, fontSize, fontSpacing, BLACK);
			DrawTextEx(font, "amounts", { textPosX[0],textPosY[3] }, fontSize, fontSpacing, BLACK);
			DrawTextEx(font, "Use your mouse to guide the hand", { textPosX[0],textPosY[4] }, fontSize, fontSpacing, BLACK);
			DrawTextEx(font, "Open and close the upgrade store by", { textPosX[0],textPosY[5] }, fontSize, fontSpacing, BLACK);
			DrawTextEx(font, "pressing the X", { textPosX[0],textPosY[6] }, fontSize, fontSpacing, BLACK);
			DrawTextEx(font, "Press P for pause.", { textPosX[0],textPosY[7] }, fontSize, fontSpacing, BLACK);
			DrawTextEx(font, "Press M to stop or play music.", { textPosX[0],textPosY[8] }, fontSize, fontSpacing, BLACK);

			DrawTextEx(font, "Reach the bottom of the map and", { textPosX[0],textPosY[9] }, fontSize, fontSpacing, BLACK);
			DrawTextEx(font, "face the heavens!", { textPosX[0],textPosY[10] }, fontSize, fontSpacing, BLACK);


			EndDrawing();
		}

		void controlsDeInit() {
			UnloadTexture(background);
			UnloadTexture(backButton1);
			UnloadTexture(backButton2);
			UnloadTexture(box);

			UnloadFont(font);
			UnloadSound(click);

		}
	}
}