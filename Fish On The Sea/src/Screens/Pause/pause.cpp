#include "pause.h"

#include "raylib.h"

#include "Game Manager/manager.h"

namespace fish {
	namespace pause {
		static void pauseDraw();

		static Rectangle rec1CR;

		static bool backState;
		static Texture2D background;
		static Texture2D backButton1;
		static Texture2D backButton2;
		static Texture2D box;

		static Font font;

		void pauseInit() {
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

		void pauseUpdate() {
			pauseDraw();

			if (CheckCollisionPointRec(GetMousePosition(), rec1CR)) {
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
					backState = false;
				}
				else {
					backState = true;
				}

				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
					gameManager::Screens = gameManager::GameScreen::Menu;
				}
			}
			else {
				backState = true;

			}
		}

		void pauseDraw() {
			BeginDrawing();
			ClearBackground(RAYWHITE);

			DrawTexture(background, 0, 0, WHITE);

			DrawRectangleLines(static_cast<int>(rec1CR.x), static_cast<int>(rec1CR.y), static_cast<int>(rec1CR.width), static_cast<int>(rec1CR.height),
				BLACK);
			DrawTexture(box, 0, 0, WHITE);

			if (backState) {
				DrawTexture(backButton1, static_cast<int>(rec1CR.x), static_cast<int>(rec1CR.y) - 45, WHITE);
			}
			else {
				DrawTexture(backButton2, static_cast<int>(rec1CR.x), static_cast<int>(rec1CR.y) - 45, WHITE);
			}

			DrawTextEx(font, "Use your mind hand to colect fish", { 23,70 }, 26, 3, BLACK);
			DrawTextEx(font, "this will turn the fish into QI points", { 23,95 }, 26, 3, BLACK);
			DrawTextEx(font, "Diferent fish give diferent QI amounts", { 23,140 }, 26, 3, BLACK);
			DrawTextEx(font, "Use your mause to guide the hand", { 23,232 }, 26, 3, BLACK);
			DrawTextEx(font, "Open and close the upgrade store by", { 23,324 }, 25, 3, BLACK);
			DrawTextEx(font, "pressing the X", { 23,344 }, 26, 3, BLACK);
			DrawTextEx(font, "Press P for pause.", { 23,419 }, 26, 3, BLACK);
			DrawTextEx(font, "Reach the bottomb of the map and", { 23,511 }, 26, 3, BLACK);
			DrawTextEx(font, "face the heavens!", { 23,531 }, 26, 3, BLACK);


			EndDrawing();
		}

		void pauseDeInit() {
			UnloadTexture(background);
			UnloadTexture(backButton1);
			UnloadTexture(backButton2);
			UnloadTexture(box);

			UnloadFont(font);

		}
	}
}