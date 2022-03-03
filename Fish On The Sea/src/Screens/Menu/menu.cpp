#include "menu.h"

#include "raylib.h"

#include "Game Manager/manager.h"

namespace fish {
	namespace menu {
		static void menuDraw();
		static Vector2 mousePoint;

		static Rectangle rec1M;
		static Rectangle rec2M;
		static Rectangle rec3M;
		static Rectangle rec4M;

		void menuInit() {
			rec1M.height = static_cast<float>(GetScreenHeight()) / 10;
			rec1M.width = static_cast<float>(GetScreenWidth()) / 10;
			rec1M.x = static_cast<float>(GetScreenWidth()) / 9 - rec1M.width;
			rec1M.y = static_cast<float>(GetScreenHeight()) / 9 - rec1M.height;

			rec2M.height = static_cast<float>(GetScreenHeight()) / 10;
			rec2M.width = static_cast<float>(GetScreenWidth()) / 10;
			rec2M.x = static_cast<float>(GetScreenWidth()) / 9 - rec1M.width;
			rec2M.y = static_cast<float>(GetScreenHeight()) / 9 + rec1M.height;

			rec3M.height = static_cast<float>(GetScreenHeight()) / 10;
			rec3M.width = static_cast<float>(GetScreenWidth()) / 10;
			rec3M.x = static_cast<float>(GetScreenWidth()) / 9 - rec1M.width;
			rec3M.y = static_cast<float>(GetScreenHeight()) / 9 + rec1M.height * 3;

			rec4M.height = static_cast<float>(GetScreenHeight()) / 10;
			rec4M.width = static_cast<float>(GetScreenWidth()) / 10;
			rec4M.x = static_cast<float>(GetScreenWidth()) / 9 - rec1M.width;
			rec4M.y = static_cast<float>(GetScreenHeight()) / 9 + rec1M.height * 5;
		}

		void menuUpdate() {
			menuDraw();

			mousePoint = GetMousePosition();

			if (CheckCollisionPointRec(mousePoint, rec1M)) {
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					gameManager::Screens = gameManager::GameScreen::Game;
				}
			}

			if (CheckCollisionPointRec(mousePoint, rec2M)) {
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					//gameManager::Screens = gameManager::GameScreen::Credits;
				}
			}

			if (CheckCollisionPointRec(mousePoint, rec3M)) {
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					//gameManager::Screens = gameManager::GameScreen::Controls;
				}
			}

			if (CheckCollisionPointRec(mousePoint, rec4M)) {
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					gameManager::Screens = gameManager::GameScreen::End;
				}
			}
		}

		void menuDraw() {
			BeginDrawing();
			ClearBackground(RAYWHITE);

			DrawRectangle(static_cast<int>(rec1M.x), static_cast<int>(rec1M.y), static_cast<int>(rec1M.width), static_cast<int>(rec1M.height), BLACK);
			DrawRectangle(static_cast<int>(rec2M.x), static_cast<int>(rec2M.y), static_cast<int>(rec2M.width), static_cast<int>(rec2M.height), BLACK);
			DrawRectangle(static_cast<int>(rec3M.x), static_cast<int>(rec3M.y), static_cast<int>(rec3M.width), static_cast<int>(rec3M.height), BLACK);
			DrawRectangle(static_cast<int>(rec4M.x), static_cast<int>(rec4M.y), static_cast<int>(rec4M.width), static_cast<int>(rec4M.height), BLACK);

			DrawText("Play", static_cast<int>(rec1M.x) + 18, static_cast<int>(rec1M.y) + 10, 20, WHITE);
			DrawText("Credits", static_cast<int>(rec2M.x) + 18, static_cast<int>(rec2M.y) + 10, 20, WHITE);
			DrawText("Controls", static_cast<int>(rec3M.x) + 5, static_cast<int>(rec3M.y) + 10, 20, WHITE);
			DrawText("Exit", static_cast<int>(rec4M.x) + 18, static_cast<int>(rec4M.y) + 10, 20, WHITE);

			DrawText("Fish On The Sea", static_cast<int>(GetScreenWidth() - 500), 100, 50, RED);
		/*	DrawText("MEGA", static_cast<int>(GetScreenWidth() - 400), 200, 50, LIME);
			DrawText("Fish On The Sea", static_cast<int>(GetScreenWidth() - 400), 300, 50, SKYBLUE);*/

			DrawText("V0.4", static_cast<int>(GetScreenWidth() - 100), static_cast<int>(GetScreenHeight()) - 40, 20, SKYBLUE);
			DrawText("Use the mouse to move and interact!", 5, static_cast<int>(GetScreenHeight()) - 40, 30, RED);

			EndDrawing();
		}
	}
}