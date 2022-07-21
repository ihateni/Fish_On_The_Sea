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

		static int textureOffset = 45;
		static float fontSize = 26;
		static float fontSpacing = 3;
		static float textPosX[] = { 23 };
		static float textPosY[] = { 70, 95, 120, 145, 170, 195, 220, 245, 270, 295 };

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
				DrawTexture(backButton1, static_cast<int>(rec1CR.x), static_cast<int>(rec1CR.y) - textureOffset, WHITE);
			}
			else {
				DrawTexture(backButton2, static_cast<int>(rec1CR.x), static_cast<int>(rec1CR.y) - textureOffset, WHITE);
			}			

			DrawTextEx(font, "Made by : Martin Concetti", { textPosX[0], textPosY[0] }, fontSize, fontSpacing, BLACK);
			DrawTextEx(font, "With help from Raylib examples", { textPosX[0], textPosY[1] }, fontSize, fontSpacing, BLACK);
			DrawTextEx(font, "Art by: Leonardo Perugini", { textPosX[0], textPosY[2] }, fontSize, fontSpacing, BLACK);
			DrawTextEx(font, "Programs use: PaintTool SAI, VS 2019", { textPosX[0], textPosY[3] }, fontSize, fontSpacing, BLACK);
			DrawTextEx(font, "Git, Git kraken.", { textPosX[0], textPosY[4] }, fontSize, fontSpacing, BLACK);
			DrawTextEx(font, "Web pages use: dafont, zapsplat,", { textPosX[0], textPosY[5] }, fontSize, fontSpacing, BLACK);
			DrawTextEx(font, "melodyloops,github, opengameart.", { textPosX[0], textPosY[6] }, fontSize, fontSpacing, BLACK);
			DrawTextEx(font, "For more extensive information please", { textPosX[0], textPosY[7] }, fontSize, fontSpacing, BLACK);
			DrawTextEx(font, "consult the readme document", { textPosX[0], textPosY[8] }, fontSize, fontSpacing, BLACK);
			DrawTextEx(font, "Victory art by: Crisisworks", { textPosX[0], textPosY[9] }, fontSize, fontSpacing, BLACK);

		
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