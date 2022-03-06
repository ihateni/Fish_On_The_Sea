#include "gameplay.h"

#include "raylib.h"

#include <iostream>

#include "Game Manager/manager.h"

#include "Player/player.h"
#include "Fish/fish.h"
#include "Shop/shop.h"

namespace fish {
	namespace gameplay {

		GameStage Stage = GameStage::Main;
		GameplayModes Modes = GameplayModes::Shop;

		static void initFishGameplay();
		static void gameplayInput();
		static void gameplayDraw();

		const int fishAmount = 20;
		player::Player player;
		fishs::Fish fish[fishAmount];
		shop::Shop shop;
		Camera2D camera = { 0 };
		float posYSave;
		float posXSave;
		bool activeShop;
		int points;
		int fishCounter;

		Sound poing;
		Music music;

		static Rectangle rec1M;
		static Rectangle stop1;
		static Rectangle stop2;
		static Rectangle stop3;

		void gameplayInit() {
			poing = LoadSound("res/Player_colition.wav");
			music = LoadMusicStream("res/melodic-techno-03-extended-version-moogify-9867.mp3");

			player::initPlayer(player.size, player.position, player.capasity, player.reach, player.playerTex);
			posYSave = player.position.y;
			posXSave = player.position.x;
			fishCounter = 0;
			points = 0;

			shop::initShop(shop.mainSize, shop.mainPos, shop.openSize, shop.openPos, shop.closeSize, shop.closePos, shop.leftArrowSize, shop.leftArrowPos,
				shop.rightArrowSize, shop.rightArrowPos, shop.itemSize, shop.itemPos, shop.item, shop.buySize, shop.buyPos, shop.closeTex1, shop.closeTex2,
				shop.mainTex, shop.leftTex1, shop.leftTex2, shop.rightTex1, shop.rightTex2, shop.openState, shop.closeState, shop.leftState, 
				shop.rightState);

			activeShop = false;
			camera.target = { player.position.x + player.size.x / 2, player.position.y };
			camera.offset = { static_cast<float>(GetScreenWidth()) / 2, static_cast<float>(GetScreenHeight()) / 2 };
			camera.rotation = 0.0f;
			camera.zoom = 1.0f;

			rec1M.height = static_cast<float>(GetScreenHeight()) / 10;
			rec1M.width = static_cast<float>(GetScreenWidth()) / 5;
			rec1M.x = static_cast<float>(GetScreenWidth()) / 2 - rec1M.width;
			rec1M.y = static_cast<float>(GetScreenHeight()) - rec1M.height * 2;

			stop1.height = static_cast<float>(GetScreenHeight()) / 20;
			stop1.width = static_cast<float>(GetScreenWidth());
			stop1.x = 0;
			stop1.y = static_cast<float>(GetScreenHeight()) * 2;

			stop2.height = static_cast<float>(GetScreenHeight()) / 20;
			stop2.width = static_cast<float>(GetScreenWidth());
			stop2.x = 0;
			stop2.y = static_cast<float>(GetScreenHeight()) * 3;

			stop3.height = static_cast<float>(GetScreenHeight()) / 20;
			stop3.width = static_cast<float>(GetScreenWidth());
			stop3.x = 0;
			stop3.y = static_cast<float>(GetScreenHeight()) * 4;
			std::cout << stop3.y << std::endl;
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
					if (!activeShop) {
						if (player.position.x != posXSave) {
							player.position.x = posXSave;
							fishCounter = 0;
						}
					}
					break;
				case GameplayModes::Descend:
					player::fall(player.position.y);
					player::movement(player.position.x);
					for (int i = 0; i < fishAmount; i++) {
						if (fish[i].active) {
							fishs::movement(fish[i].position.x, fish[i].size.y, fish[i].dir);
						}
					}
					switch (player.reach)
					{
					case 1:
						if (CheckCollisionRecs({ player.position.x,player.position.y,player.size.x,player.size.y }, stop1)) {
							Modes = GameplayModes::Ascend;
						}
						break;
					case 2:
						if (CheckCollisionRecs({ player.position.x,player.position.y,player.size.x,player.size.y }, stop2)) {
							Modes = GameplayModes::Ascend;
						}
						break;
					case 3:
						if (CheckCollisionRecs({ player.position.x,player.position.y,player.size.x,player.size.y }, stop3)) {
							Modes = GameplayModes::Ascend;
						}
						break;
					default:
						break;
					}


					break;
				case GameplayModes::Ascend:
					player::movement(player.position.x);
					player::ascension(player.position.y);
					for (int i = 0; i < fishAmount; i++) {
						if (fish[i].active) {
							fishs::movement(fish[i].position.x, fish[i].size.y, fish[i].dir);
						}
					}
					if (player.position.y <= posYSave) {
						Modes = GameplayModes::Shop;
						player.position.y = posYSave;
					}

					for (int i = 0; i < fishAmount; i++) {
						if (CheckCollisionRecs({ player.position.x, player.position.y,player.size.x,player.size.y }, { fish[i].position.x,
							fish[i].position.y,fish[i].size.x,fish[i].size.y })) {
							switch (player.capasity) {
							case 1:
								if (fishCounter < 3) {
									if (fish[i].active == true) {
										fishs::deactivate(fish[i].active, points, fish[i].type);
										fishCounter++;
									}
								}
								break;
							case 2:
								if (fishCounter < 6) {
									if (fish[i].active == true) {
										fishs::deactivate(fish[i].active, points, fish[i].type);
										fishCounter++;
									}
								}
								break;
							case 3:
								if (fishCounter < 10) {
									if (fish[i].active == true) {
										fishs::deactivate(fish[i].active, points, fish[i].type);
										fishCounter++;
									}
								}
								break;
							default:
								break;
							}

						}
					}
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
					if (!activeShop) {
						if (CheckCollisionPointRec(GetMousePosition(), rec1M)) {
							if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
								Modes = GameplayModes::Descend;
								initFishGameplay();
							}
						}

						//open button
						if (CheckCollisionPointRec(GetMousePosition(), { shop.openPos.x,shop.openPos.y,shop.openSize.x,shop.openSize.y })) {
							if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
								shop.openState = false;
							}
							else {
								shop.openState = true;
							}
							if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
								activeShop = !activeShop;
							}
						}
						else {
							shop.openState = true;
						}
					}
					else {
						//close button
						if (CheckCollisionPointRec(GetMousePosition(), { shop.closePos.x,shop.closePos.y,shop.closeSize.x,shop.closeSize.y })) {
							if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
								shop.closeState = false;
							}
							else {
								shop.closeState = true;
							}
							if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
								activeShop = !activeShop;
							}
						}
						else {
							shop.closeState = true;
						}

						//if (CheckCollisionPointRec(GetMousePosition(), { shop.leftArrowPos.x,shop.leftArrowPos.y,shop.leftArrowSize.x,
						//	shop.leftArrowSize.y })) {
						//	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
						//		shop::decreaseItem(shop.item);
						//	}
						//}

						if (CheckCollisionPointRec(GetMousePosition(), { shop.leftArrowPos.x,shop.leftArrowPos.y,shop.leftArrowSize.x,
							shop.leftArrowSize.y })) {
							if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
								shop.leftState = false;
							}
							else {
								shop.leftState = true;
							}
							if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
								shop::decreaseItem(shop.item);
							}
						}
						else {
							shop.leftState = true;
						}

						if (CheckCollisionPointRec(GetMousePosition(), { shop.rightArrowPos.x,shop.rightArrowPos.y,shop.rightArrowSize.x,
							shop.rightArrowSize.y })) {
							if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
								shop::increaseItem(shop.item);
							}
						}

						if (CheckCollisionPointRec(GetMousePosition(), { shop.buyPos.x,shop.buyPos.y,shop.buySize.x,
							shop.buySize.y })) {
							if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
								shop::upgradeItem(shop.item, player.capasity, player.reach, points);
							}
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
				player::drawPlayer(player.position.x, player.position.y, player.size.x, player.size.y, player.playerTex);
				switch (Modes) {
				case GameplayModes::Shop:
					if (!activeShop) {
						DrawText(TextFormat("Points: %i", points), 280, 50, 30, MAROON);
						DrawRectangle(static_cast<int>(rec1M.x), static_cast<int>(rec1M.y), static_cast<int>(rec1M.width),
							static_cast<int>(rec1M.height), RED);
						shop::drawOpen(shop.openSize, shop.openPos, shop.closeTex1, shop.closeTex2, shop.openState);
					}
					else {
						shop::drawShop(shop.mainSize, shop.mainPos, shop.mainTex);
						shop::drawLeftArrow(shop.leftArrowSize, shop.leftArrowPos,shop.leftTex1,shop.leftTex2, shop.leftState);
						shop::drawRightArrow(shop.rightArrowSize, shop.rightArrowPos, shop.rightTex1, shop.rightTex2, shop.rightState);
						shop::drawItem(shop.itemSize, shop.itemPos, shop.item);
						shop::drawClose(shop.closeSize, shop.closePos, shop.closeTex1, shop.closeTex2, shop.closeState);
						shop::drawBuy(shop.buySize, shop.buyPos);
					}
					break;
				case GameplayModes::Descend:
					DrawRectangle(static_cast<int>(stop1.x), static_cast<int>(stop1.y), static_cast<int>(stop1.width),
						static_cast<int>(stop1.height), YELLOW);
					DrawRectangle(static_cast<int>(stop2.x), static_cast<int>(stop2.y), static_cast<int>(stop2.width),
						static_cast<int>(stop2.height), YELLOW);
					DrawRectangle(static_cast<int>(stop3.x), static_cast<int>(stop3.y), static_cast<int>(stop3.width),
						static_cast<int>(stop3.height), YELLOW);

					for (int i = 0; i < fishAmount; i++) {
						fishs::drawFish(fish[i].position.x, fish[i].position.y, fish[i].size.x, fish[i].size.y, fish[i].type);
					}
					break;
				case GameplayModes::Ascend:
					for (int i = 0; i < fishAmount; i++) {
						if (fish[i].active) {
							fishs::drawFish(fish[i].position.x, fish[i].position.y, fish[i].size.x, fish[i].size.y, fish[i].type);
						}
					}
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

		void initFishGameplay() {
			for (int i = 0; i < fishAmount; i++) {
				fishs::initFish(fish[i].size, fish[i].position, fish[i].active, fish[i].type, fish[i].dir);
			}

		}
	}
}