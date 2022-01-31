#include "gameplay.h"

#include "raylib.h"

#include <iostream>

#include "Game Manager/manager.h"

#include "Player/player.h"

namespace fish {
	namespace gameplay {

		GameStage Stage = GameStage::Main;
		GameplayModes Modes = GameplayModes::Shop;

		static void gameplayInput();
		static void gameplayDraw();

		static bool pause = false;
		static bool win = false;

		player::Player player;
		Camera2D camera = { 0 };

		Sound poing;
		Music music;

		static Rectangle rec1M;
		static Rectangle stop1;

		void gameplayInit() {
			poing = LoadSound("res/Player_colition.wav");
			music = LoadMusicStream("res/melodic-techno-03-extended-version-moogify-9867.mp3");

			//player.size = //{ static_cast<float>(GetScreenWidth()) / 15,static_cast<float>(GetScreenHeight()) / 15 };
			//player.position = { static_cast<float>(GetScreenWidth()) / 2 - player.size.x / 2,static_cast<float>(GetScreenHeight()) / 2 - player.size.y / 2 };		
		
			player::initPlayer(player.size, player.position);
			
			camera.target = { player.position.x + player.size.x / 2, player.position.y };
			camera.offset = { static_cast<float>(GetScreenWidth()) / 2, static_cast<float>(GetScreenHeight()) / 2 };
			camera.rotation = 0.0f;
			camera.zoom = 1.0f;

			rec1M.height = static_cast<float>(GetScreenHeight()) / 10;
			rec1M.width = static_cast<float>(GetScreenWidth()) / 5;
			rec1M.x = static_cast<float>(GetScreenWidth()) / 2 - rec1M.width;
			rec1M.y = static_cast<float>(GetScreenHeight())  - rec1M.height * 2;
		
			stop1.height = static_cast<float>(GetScreenHeight()) / 10;
			stop1.width = static_cast<float>(GetScreenWidth()) ;
			stop1.x = 0;
			stop1.y = static_cast<float>(GetScreenHeight()) * 2;
		}

		void gameplayUpdate() {
			gameplayDraw();
			gameplayInput();
			PlayMusicStream(music);
			UpdateMusicStream(music);

			switch (Stage) {
			case GameStage::Main:
				camera.target.y = player.position.y + player.size.y / 2;
					switch (Modes) {
					case GameplayModes::Shop:
						/*player::fall(player.position.y);
						player::movement(player.position.x);*/
						break;
					case GameplayModes::Descend:
						player::fall(player.position.y);
						player::movement(player.position.x);
						if (CheckCollisionRecs({player.position.x,player.position.y,player.size.x,player.size.y}, stop1)) {
								Modes = GameplayModes::Ascend;
						}					
						break;
					case GameplayModes::Ascend:
						player::ascension(player.position.y);
						break;
					default:
						break;
					}
				break;
			case GameStage::Pause:
				break;
			case  GameStage::Victory:
				break;
			}
		}

		void gameplayInput() {
			switch (Stage) {
			case GameStage::Main:
				if (IsKeyReleased(KEY_P)) Stage = GameStage::Pause;
				switch (Modes) {
				case GameplayModes::Shop:
					if (CheckCollisionPointRec(GetMousePosition(), rec1M)) {
						if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
							Modes = GameplayModes::Descend;
						}
					}
					break;
				case GameplayModes::Descend:
					
					break;
				case GameplayModes::Ascend:
					break;
				default:
					break;
				}
				break;
			case GameStage::Pause:
				if (IsKeyReleased(KEY_P)) Stage = GameStage::Main;
				break;
			case  GameStage::Victory:
				break;
			}
		}

		void gameplayDraw() {
			BeginDrawing();
			ClearBackground(RAYWHITE);

			switch (Stage) {
			case GameStage::Main:
				BeginMode2D(camera);
				DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), SKYBLUE);
				DrawRectangle(0, GetScreenHeight(), 100, 800, RED);
				DrawRectangle(static_cast<int>(player.position.x), static_cast<int>(player.position.y), static_cast<int>(player.size.x), static_cast<int>(player.size.y), BLACK);
					switch (Modes) {
					case GameplayModes::Shop:
						DrawRectangle(static_cast<int>(rec1M.x), static_cast<int>(rec1M.y), static_cast<int>(rec1M.width), static_cast<int>(rec1M.height), RED);
						break;
					case GameplayModes::Descend:
						DrawRectangle(static_cast<int>(stop1.x), static_cast<int>(stop1.y), static_cast<int>(stop1.width), static_cast<int>(stop1.height), YELLOW);

						break;
					case GameplayModes::Ascend:
						break;
					default:
						break;
					}
					break;
				EndMode2D();
				break;
			case GameStage::Pause:
				DrawText("Press P to play again", static_cast<int>(GetScreenWidth()) / 9, static_cast<int>(GetScreenHeight()) / 9, 40, RED);
				DrawText("Press enter to go to menu", static_cast<int>(GetScreenWidth()) / 9, static_cast<int>(GetScreenHeight()) / 6, 40, RED);
				break;
			case  GameStage::Victory:
				break;
			}
			EndDrawing();
		}
	}
}