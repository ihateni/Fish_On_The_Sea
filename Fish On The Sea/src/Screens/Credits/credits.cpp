#include "credits.h"

#include "raylib.h"

#include "Game Manager/manager.h"

namespace fish {
	namespace credits {
		static void creditsDraw();

		static Rectangle rec1CR;

		static bool backState;
		static Texture2D background;
		static Texture2D backButton1;
		static Texture2D backButton2;
		static Texture2D box;

		static Font font;
		static	Sound click;

		void creditsInit() {
			click = LoadSound("res/Sound/mixkit-unlock-game-notification-253.wav");

			rec1CR.width = (static_cast<float> (GetScreenWidth()) - ((static_cast<float>(GetScreenWidth()) / 10) * 2)) / 3;
			rec1CR.height = (static_cast<float> (GetScreenHeight()) - ((static_cast<float>(GetScreenHeight()) / 10) * 2)) / 15; 
			rec1CR.x = 10;
			rec1CR.y = 10;

			backState = true;

			background = LoadTexture("res/Background/Background.png");
			backButton1 = LoadTexture("res/Control_buttons/menu1.png" );
			backButton2 = LoadTexture("res/Control_buttons/menu2.png");

			box = LoadTexture("res/Control_buttons/box_large.png");

			font = LoadFont("res/Font/aAsianNinja.otf");

		}

		void creditsUpdate() {
			creditsDraw();

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

		void creditsDraw() {
			BeginDrawing();
			ClearBackground(RAYWHITE);

			DrawTexture(background, 0, 0, WHITE);

			DrawRectangleLines(static_cast<int>(rec1CR.x), static_cast<int>(rec1CR.y), static_cast<int>(rec1CR.width), static_cast<int>(rec1CR.height), 
				BLACK);
			DrawTexture(box, 0,0, WHITE);

			if (backState) {
				DrawTexture(backButton1, static_cast<int>(rec1CR.x), static_cast<int>(rec1CR.y) - 45, WHITE);
			}
			else {
				DrawTexture(backButton2, static_cast<int>(rec1CR.x), static_cast<int>(rec1CR.y) - 45, WHITE);
			}

			DrawTextEx(font, "Made by : Martin Concetti", { 23,70 }, 26, 3, BLACK);
			DrawTextEx(font, "With help from Raylib examples", { 23,95 }, 26, 3, BLACK);
			DrawTextEx(font, "Art by: Leonardo Perugini", { 23,120 }, 26, 3, BLACK);
			DrawTextEx(font, "Programs use: PaintTool SAI, VS 2019", { 23,145 }, 26, 3, BLACK);
			DrawTextEx(font, "Git, Git kraken.", { 23,170 }, 25, 3, BLACK);
			DrawTextEx(font, "Web pages use: dafont, zapsplat,", { 23,195 }, 26, 3, BLACK);
			DrawTextEx(font, "melodyloops,github, opengameart.", { 23,220 }, 26, 3, BLACK);
			DrawTextEx(font, "For more extensive information please", { 23,245 }, 26, 3, BLACK);
			DrawTextEx(font, "consult the readme docuemnt", { 23,270 }, 26, 3, BLACK);
			DrawTextEx(font, "Victory art by: Crisisworks", { 23,295 }, 26, 3, BLACK);

		
			EndDrawing();
		}

		void creditsDeInit() {
			UnloadTexture(background);
			UnloadTexture(backButton1);
			UnloadTexture(backButton2);
			UnloadTexture(box);

			UnloadFont(font);
			UnloadSound(click);

		}
	}
}