#include "menu.h"

#include "raylib.h"

#include "Game Manager/manager.h"

#include <iostream>
namespace fish {
	namespace menu {
		static void menuDraw();
		static Vector2 mousePoint;

		static Rectangle rec1M;
		static Rectangle rec2M;
		static Rectangle rec3M;
		static Rectangle rec4M;

		Texture2D play1;
		Texture2D play2;
		bool playState;

		Texture2D control1;
		Texture2D control2;
		bool controlsState;

		Texture2D credits1;
		Texture2D credits2;
		bool creditsState;

		Texture2D exit1;
		Texture2D exit2;
		bool exitState;

		void menuInit() {
			play1 = LoadTexture("res/Menu buttons/play1.png");
			play2 = LoadTexture("res/Menu buttons/play2.png");
			playState = true;

			credits1 = LoadTexture("res/Menu buttons/credits1.png");
			credits2 = LoadTexture("res/Menu buttons/credits2.png");
			creditsState = true;

			control1 = LoadTexture("res/Menu buttons/instructions1.png");
			control2 = LoadTexture("res/Menu buttons/instructions2.png");
			controlsState = true;

			exit1 = LoadTexture("res/Menu buttons/exit1.png");
			exit2 = LoadTexture("res/Menu buttons/exit2.png");
			exitState = true;

			rec1M.height = (static_cast<float> (GetScreenHeight()) - ((static_cast<float>(GetScreenHeight()) / 10) * 2)) / 15;
			rec1M.width = (static_cast<float> (GetScreenWidth()) - ((static_cast<float>(GetScreenWidth()) / 10) * 2)) / 3;
			rec1M.x = static_cast<float>(GetScreenWidth()) / 2 - rec1M.width / 2;
			rec1M.y = static_cast<float>(GetScreenHeight()) / 2 - rec1M.height;

			rec2M.height = (static_cast<float> (GetScreenHeight()) - ((static_cast<float>(GetScreenHeight()) / 10) * 2)) / 15;
			rec2M.width = (static_cast<float> (GetScreenWidth()) - ((static_cast<float>(GetScreenWidth()) / 10) * 2)) / 3;
			rec2M.x = static_cast<float>(GetScreenWidth()) / 2 - rec1M.width / 2;
			rec2M.y = static_cast<float>(GetScreenHeight()) / 2 + rec1M.height;

			rec3M.height = (static_cast<float> (GetScreenHeight()) - ((static_cast<float>(GetScreenHeight()) / 10) * 2)) / 15;
			rec3M.width = (static_cast<float> (GetScreenWidth()) - ((static_cast<float>(GetScreenWidth()) / 10) * 2)) / 3;
			rec3M.x = static_cast<float>(GetScreenWidth()) / 2 - rec1M.width / 2;
			rec3M.y = static_cast<float>(GetScreenHeight()) / 2 + rec1M.height * 3;

			rec4M.height = (static_cast<float> (GetScreenHeight()) - ((static_cast<float>(GetScreenHeight()) / 10) * 2)) / 15;
			rec4M.width = (static_cast<float> (GetScreenWidth()) - ((static_cast<float>(GetScreenWidth()) / 10) * 2)) / 3;
			rec4M.x = static_cast<float>(GetScreenWidth()) / 2 - rec1M.width / 2;
			rec4M.y = static_cast<float>(GetScreenHeight()) / 2 + rec1M.height * 5;
		}

		void menuUpdate() {
			menuDraw();

			mousePoint = GetMousePosition();

			//play button
			if (CheckCollisionPointRec(mousePoint, rec1M)) {
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
					playState = false;
				}
				else {
					playState = true;
				}

				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
					gameManager::Screens = gameManager::GameScreen::Game;
				}
			}
			else {
				playState = true;

			}

			//credits button
			if (CheckCollisionPointRec(mousePoint, rec2M)) {
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
					creditsState = false;
				}
				else {
					creditsState = true;
				}
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
					//gameManager::Screens = gameManager::GameScreen::Credits;
				}
			}
			else {
				creditsState = true;

			}

			//control button
			if (CheckCollisionPointRec(mousePoint, rec3M)) {
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
					controlsState = false;
				}
				else {
					controlsState = true;
				}
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
					//gameManager::Screens = gameManager::GameScreen::Controls;
				}
			}
			else {
				controlsState = true;

			}

			//exit button
			if (CheckCollisionPointRec(mousePoint, rec4M)) {
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
					exitState = false;
				}
				else {
					exitState = true;
				}
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
					gameManager::Screens = gameManager::GameScreen::End;
				}
			}
			else {
				exitState = true;

			}
		}

		void menuDraw() {
			BeginDrawing();
			ClearBackground(RAYWHITE);

#if _DEBUG
			DrawRectangle(static_cast<int>(rec1M.x), static_cast<int>(rec1M.y), static_cast<int>(rec1M.width), static_cast<int>(rec1M.height), BLACK);
			DrawRectangle(static_cast<int>(rec2M.x), static_cast<int>(rec2M.y), static_cast<int>(rec2M.width), static_cast<int>(rec2M.height), BLACK);
			DrawRectangle(static_cast<int>(rec3M.x), static_cast<int>(rec3M.y), static_cast<int>(rec3M.width), static_cast<int>(rec3M.height), BLACK);
			DrawRectangle(static_cast<int>(rec4M.x), static_cast<int>(rec4M.y), static_cast<int>(rec4M.width), static_cast<int>(rec4M.height), BLACK);
#endif

			if (playState) {
				DrawTexture(play1, static_cast<int>(rec1M.x), static_cast<int>(rec1M.y) - 45, WHITE);
			}
			else {
				DrawTexture(play2, static_cast<int>(rec1M.x), static_cast<int>(rec1M.y) - 45, WHITE);
			}

			if (creditsState) {
				DrawTexture(credits1, static_cast<int>(rec2M.x), static_cast<int>(rec2M.y) - 45, WHITE);
			}
			else {				
				DrawTexture(credits2, static_cast<int>(rec2M.x), static_cast<int>(rec2M.y) - 45, WHITE);
			}

			if (controlsState) {
				DrawTexture(control1, static_cast<int>(rec3M.x), static_cast<int>(rec3M.y) - 45, WHITE);
			}
			else {
				DrawTexture(control2, static_cast<int>(rec3M.x), static_cast<int>(rec3M.y) - 45, WHITE);
			}

			if (exitState) {
				DrawTexture(exit1, static_cast<int>(rec4M.x), static_cast<int>(rec4M.y) - 45, WHITE);
			}
			else {
				DrawTexture(exit2, static_cast<int>(rec4M.x), static_cast<int>(rec4M.y) - 45, WHITE);
			}

			
			DrawText("Fish On The Sea", static_cast<int>(GetScreenWidth() - 450), 100, 50, RED);

			DrawText("V0.5.2", static_cast<int>(GetScreenWidth() - 100), static_cast<int>(GetScreenHeight()) - 40, 20, SKYBLUE);

			EndDrawing();
		}
	}
}