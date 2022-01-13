#include "gameplay.h"

#include "raylib.h"

#include <iostream>

#include "Game Manager/manager.h"

#include "Player/player.h"

namespace fish {
	namespace gameplay {

		static void gameplayInput();
		static void gameplayDraw();

		const int files = 10;
		const int rows = 3;

		static bool pause = false;
		static bool win = false;
		static int points;
		static int random;
	
		player::Player player;

		Sound poing;
		Music music;

		void gameplayInit() {
			points = 0;
			poing = LoadSound("res/Player_colition.wav");
			music = LoadMusicStream("res/melodic-techno-03-extended-version-moogify-9867.mp3");

			player.size = { static_cast<float>(GetScreenWidth()) / 6,static_cast<float>(GetScreenHeight()) / 15 };
			player.position = { static_cast<float>(GetScreenWidth()) / 2 - player.size.x / 2,static_cast<float>(GetScreenHeight()) - player.size.y - 10 };
			std::cout<< player.size.x <<std::endl;
		}

		void gameplayUpdate() {
			gameplayDraw();
			gameplayInput();
			PlayMusicStream(music);
			UpdateMusicStream(music);
			if (!win) {
				if (!pause) {
					player::fall(player.position.y);
					std::cout << player.position.y << std::endl;
				}
			}
		}

		void gameplayInput() {
			if (IsKeyPressed(KEY_P)) pause = !pause;

			if (!pause) {
			
			}
		}

		void gameplayDraw() {
			BeginDrawing();
			ClearBackground(RAYWHITE);

			if (!win) {
				if (!pause) {
					DrawRectangle(90,90 ,100 ,800 , RED);
					DrawRectangle(static_cast<int>(player.position.x), static_cast<int>(player.position.y), static_cast<int>(player.size.x), static_cast<int>(player.size.y), BLACK);

				}
				else {
					DrawText("Press P to play again", static_cast<int>(GetScreenWidth()) / 9, static_cast<int>(GetScreenHeight()) / 9, 40, RED);
					DrawText("Press enter to go to menu", static_cast<int>(GetScreenWidth()) / 9, static_cast<int>(GetScreenHeight()) / 6, 40, RED);


				}
			}
			else {
				if (points < 30) {
					DrawText("Game over", static_cast<int>(GetScreenWidth()) / 9, static_cast<int>(GetScreenHeight()) / 16, 40, RED);
					DrawText("Press P to play again", static_cast<int>(GetScreenWidth()) / 9, static_cast<int>(GetScreenHeight()) / 8, 40, SKYBLUE);
					DrawText("Press enter to go to menu", static_cast<int>(GetScreenWidth()) / 9, static_cast<int>(GetScreenHeight()) / 5, 40, SKYBLUE);
				}
				else {
					DrawText("You win!", static_cast<int>(GetScreenWidth()) / 9, static_cast<int>(GetScreenHeight()) / 16, 40, RED);
					DrawText("Press P to play again", static_cast<int>(GetScreenWidth()) / 9, static_cast<int>(GetScreenHeight()) / 8, 40, SKYBLUE);
					DrawText("Press enter to go to menu", static_cast<int>(GetScreenWidth()) / 9, static_cast<int>(GetScreenHeight()) / 5, 40, SKYBLUE);
				}
			}
			EndDrawing();
		}
	}
}