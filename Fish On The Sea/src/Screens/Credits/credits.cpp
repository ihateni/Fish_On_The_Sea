#include "credits.h"

#include "raylib.h"

#include "Game Manager/manager.h"

namespace fish {
	namespace credits {
		static void creditsDraw();

		static Vector2 mousePoint;
		static Rectangle rec1CR;

		void creditsInit() {
			rec1CR.width = static_cast<float>(GetScreenWidth()) / 10;
			rec1CR.height = static_cast<float>(GetScreenHeight()) / 10;
			rec1CR.x = static_cast<float>(GetScreenWidth()) / 9 - rec1CR.width;
			rec1CR.y = static_cast<float>(GetScreenHeight()) / 9 - rec1CR.height;
		}

		void creditsUpdate() {
			creditsDraw();
			mousePoint = GetMousePosition();

			if (CheckCollisionPointRec(mousePoint, rec1CR)) {
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					gameManager::Screens = gameManager::GameScreen::Game;
				}
			}
		}

		void creditsDraw() {
			ClearBackground(RAYWHITE);

			DrawRectangle(static_cast<int>(rec1CR.x), static_cast<int>(rec1CR.y), static_cast<int>(rec1CR.width), static_cast<int>(rec1CR.height), BLACK);
			DrawText("atras", static_cast<int>(rec1CR.x) + 18, static_cast<int>(rec1CR.y) + 10, 20, WHITE);

			DrawText("Made by: Martin Concetti", static_cast<int>(GetScreenWidth() / 4), 0, 30, SKYBLUE);
			DrawText("Player ball collision from raylib example, bricks from Matias Karplus", static_cast<int>(GetScreenWidth() / 4), static_cast<int>(GetScreenHeight()) / 19, 20, SKYBLUE);
			DrawText("Using raylib", static_cast<int>(GetScreenWidth() / 4), static_cast<int>(GetScreenHeight()) / 10, 30, SKYBLUE);
			DrawText("V1.0", static_cast<int>(GetScreenWidth() / 2), static_cast<int>(GetScreenHeight()) / 7, 30, SKYBLUE);
			DrawText("Collision  sound effect by Martin Concetti in bfxr", 5, static_cast<int>(GetScreenHeight()) / 4, 30, BLACK);
			DrawText("melodic-techno-03-extended-version-moogify-9867.mp3", 5, static_cast<int>(GetScreenHeight()) / 3, 30, BLACK);
			DrawText("created by Zen Man, more info in the resource folder!", 5, static_cast<int>(GetScreenHeight()) / 2, 30, BLACK);

			EndDrawing();
		}
	}
}