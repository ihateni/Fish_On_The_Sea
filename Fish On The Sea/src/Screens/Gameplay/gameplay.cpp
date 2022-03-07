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

		const int fishAmount = 60;

		player::Player player;
		fishs::Fish fish[fishAmount];
		shop::Shop shop;

		Camera2D camera = { 0 };

		float posYSave;
		float posXSave;
		bool activeShop;
		int points;
		int fishCounter;
		bool playState;
		bool menuState;
		int fishArea1 = 1;
		int fishArea2 = 2;
		int fishArea3 = 3;

		float boxPosX;
		float boxPosY;

		Sound poing;
		Music music;

		static Rectangle rec1M;
		static Rectangle rec2M;
		static Rectangle stop1;
		static Rectangle stop2;
		static Rectangle stop3;
		static Rectangle sphereRec;

		static Texture2D background;
		static Texture2D playTex1;
		static Texture2D playTex2;
		static Texture2D bigBox;
		static Texture2D menuTex1;
		static Texture2D menuTex2;
		static Texture2D sphere;
		static Font font;

		static	Sound click;

		void gameplayInit() {
			click = LoadSound("res/Sound/mixkit-unlock-game-notification-253.wav");
			sphere = LoadTexture("res/Player/sphere.png");


			player::initPlayer(player.size, player.position, player.capasity, player.reach, player.evolution,player.playerTex,player.evoTex1,player.evoTex2
			,player.evoTex3);
			posYSave = player.position.y;
			posXSave = player.position.x;
			fishCounter = 0;
			points = 0;
			background = LoadTexture("res/Background/Background.png");
			playTex1 = LoadTexture("res/Gameplay_buttons/play1.png");
			playTex2 = LoadTexture("res/Gameplay_buttons/play2.png");
			playState = true;
			bigBox = LoadTexture("res/Gameplay_buttons/box_large.png");
			font = LoadFont("res/Font/aAsianNinja.otf");
			menuTex1 = LoadTexture("res/Gameplay_buttons/menu1.png");
			menuTex2 = LoadTexture("res/Gameplay_buttons/menu2.png");
			menuState = true;

#if _DEBUG
			points = 100000;
#endif
			boxPosX = 0;
			boxPosY = 0;

			shop::initShop(shop.mainSize, shop.mainPos, shop.openSize, shop.openPos, shop.closeSize, shop.closePos, shop.leftArrowSize, shop.leftArrowPos,
				shop.rightArrowSize, shop.rightArrowPos, shop.itemSize, shop.itemPos, shop.item, shop.buySize, shop.buyPos, shop.closeTex1, shop.closeTex2,
				shop.mainTex, shop.leftTex1, shop.leftTex2, shop.rightTex1, shop.rightTex2, shop.buyTex1, shop.buyTex2, shop.openState, shop.closeState,
				shop.leftState, shop.rightState, shop.buyState, shop.font);

			activeShop = false;
			camera.target = { player.position.x + player.size.x / 2, player.position.y };
			camera.offset = { static_cast<float>(GetScreenWidth()) / 2, static_cast<float>(GetScreenHeight()) / 2 };
			camera.rotation = 0.0f;
			camera.zoom = 1.0f;

			rec1M.height = (static_cast<float> (GetScreenHeight()) - ((static_cast<float>(GetScreenHeight()) / 10) * 2)) / 15;
			rec1M.width = (static_cast<float> (GetScreenWidth()) - ((static_cast<float>(GetScreenWidth()) / 10) * 2)) / 3;
			rec1M.x = static_cast<float>(GetScreenWidth()) / 2 - rec1M.width / 2;
			rec1M.y = static_cast<float>(GetScreenHeight()) - rec1M.height * 2;

			sphereRec.height = (static_cast<float> (GetScreenWidth()) / 5);
			sphereRec.width = (static_cast<float> (GetScreenWidth()) / 5);
			sphereRec.x = rec1M.x;
			sphereRec.y = rec1M.y + static_cast<float>(GetScreenHeight()) * 4 - static_cast<float>(GetScreenHeight())/2;

			rec2M.height = (static_cast<float> (GetScreenHeight()) - ((static_cast<float>(GetScreenHeight()) / 10) * 2)) / 15;
			rec2M.width = (static_cast<float> (GetScreenWidth()) - ((static_cast<float>(GetScreenWidth()) / 10) * 2)) / 3;
			rec2M.x = static_cast<float>(GetScreenWidth()) / 2 - rec1M.width / 2;
			rec2M.y = static_cast<float>(GetScreenHeight()) - rec1M.height * 2;

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
					player::fall(boxPosY);
					player::fall(rec2M.y);

					if (player.capasity == 4 || player.evolution == 4 || player.reach == 4) {
					
					}
					else{
						player::movement(player.position.x);
					}

					for (int i = 0; i < fishAmount; i++) {
						if (fish[i].active) {
							fishs::movement(fish[i].position.x, fish[i].size.y, fish[i].dir);
						}
					}
					switch (player.reach){
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
					case 4:
						if(player.capasity == 4 || player.evolution == 4 || player.reach == 4){
							
						}
						else {
							if (CheckCollisionRecs({ player.position.x,player.position.y,player.size.x,player.size.y }, stop3)) {
								Modes = GameplayModes::Ascend;
							}
						}
						
						break;
					default:
						break;
					}

					if (CheckCollisionRecs({ player.position.x,player.position.y,player.size.x,player.size.y }, sphereRec)) {
						gameManager::Screens = gameManager::GameScreen::Victory;
						gameplayInit();
					}
					if (player.position.y > sphereRec.y) {
						gameManager::Screens = gameManager::GameScreen::Victory;
						gameplayInit();
					}

				case GameplayModes::Ascend:
					player::movement(player.position.x);
					player::ascension(player.position.y);
					player::ascension(boxPosY);
					player::ascension(rec2M.y);
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
										fishs::deactivate(fish[i].active, points, fish[i].type, fish[i].area);
										fishCounter++;
									}
								}
								break;
							case 2:
								if (fishCounter < 6) {
									if (fish[i].active == true) {
										fishs::deactivate(fish[i].active, points, fish[i].type,fish[i].area);
										fishCounter++;
									}
								}
								break;
							case 3:
								if (fishCounter < 10) {
									if (fish[i].active == true) {
										fishs::deactivate(fish[i].active, points, fish[i].type,fish[i].area);
										fishCounter++;
									}
								}
								break;
							case 4:
								if (fishCounter < 10) {
									if (fish[i].active == true) {
										fishs::deactivate(fish[i].active, points, fish[i].type,fish[i].area);
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

						//play button
						if (CheckCollisionPointRec(GetMousePosition(), rec1M)) {
							if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
								playState = false;
							}
							else {
								playState = true;
							}
							if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
								Modes = GameplayModes::Descend;
								PlaySound(click);

								initFishGameplay();
							}
						}
						else {
							playState = true;
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
								PlaySound(click);

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
								PlaySound(click);

							}
						}
						else {
							shop.closeState = true;
						}

						//shop left arrow
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
								PlaySound(click);

							}
						}
						else {
							shop.leftState = true;
						}

						//shop right arrow
						if (CheckCollisionPointRec(GetMousePosition(), { shop.rightArrowPos.x,shop.rightArrowPos.y,shop.rightArrowSize.x,
							shop.rightArrowSize.y })) {
							if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
								shop.rightState = false;
							}
							else {
								shop.rightState = true;
							}
							if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
								shop::increaseItem(shop.item);
								PlaySound(click);

							}
						}
						else {
							shop.rightState = true;
						}

						//shop but button
						if (CheckCollisionPointRec(GetMousePosition(), { shop.buyPos.x,shop.buyPos.y,shop.buySize.x,
							shop.buySize.y })) {
							if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
								shop.buyState = false;
							}
							else {
								shop.buyState = true;
							}
							if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
								shop::upgradeItem(shop.item, player.capasity, player.reach, points,player.evolution);
								PlaySound(click);

							}
						}
						else {
							shop.buyState = true;
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


				if (CheckCollisionPointRec(GetMousePosition(), rec2M)) {
					if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
						menuState = false;
					}
					else {
						menuState = true;
					}
					if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
						gameManager::Screens = gameManager::GameScreen::Menu;
						PlaySound(click);

						gameplayInit();
						Stage = GameStage::Main;
					}

					else {
						menuState = true;
					}
					break;
				}
			case  GameStage::Victory:
				break;
			}
		}

		void gameplayDraw() {
			BeginDrawing();
			ClearBackground(RAYWHITE);
			BeginMode2D(camera);
			DrawTexture(background, 0, 0, WHITE);

			switch (Stage) {
			case GameStage::Main:
#if _DEBUG
				DrawRectangleLines(0, GetScreenHeight(), 100, 800, RED);
#endif
				player::drawPlayer(player.position.x, player.position.y, player.size.x, player.size.y, player.playerTex,player.evoTex1, player.evoTex2
					, player.evoTex3, player.evolution);
#if _DEBUG

				DrawRectangleLines(static_cast<int>(sphereRec.x), static_cast<int>(sphereRec.y), static_cast<int>(sphereRec.width),
					static_cast<int>(sphereRec.height), BLACK);
#endif
				DrawTexture(sphere, static_cast<int>(sphereRec.x), static_cast<int>(sphereRec.y) , WHITE);

				switch (Modes) {
				case GameplayModes::Shop:
					if (!activeShop) {
						DrawTextEx(font, TextFormat("QI: %i", points), { static_cast<float>(GetScreenWidth() - 200), 30 }, 35, 2, BLACK);

#if _DEBUG

						DrawRectangleLines(static_cast<int>(rec1M.x), static_cast<int>(rec1M.y), static_cast<int>(rec1M.width),
							static_cast<int>(rec1M.height), RED);
#endif
						if (playState) {
							DrawTexture(playTex1, static_cast<int>(rec1M.x), static_cast<int>(rec1M.y) - 45, WHITE);
						}
						else {
							DrawTexture(playTex2, static_cast<int>(rec1M.x), static_cast<int>(rec1M.y) - 45, WHITE);
						}

						shop::drawOpen(shop.openSize, shop.openPos, shop.closeTex1, shop.closeTex2, shop.openState);
					}
					else {
						shop::drawShop(shop.mainSize, shop.mainPos, shop.mainTex);
						shop::drawLeftArrow(shop.leftArrowSize, shop.leftArrowPos, shop.leftTex1, shop.leftTex2, shop.leftState);
						shop::drawRightArrow(shop.rightArrowSize, shop.rightArrowPos, shop.rightTex1, shop.rightTex2, shop.rightState);
						shop::drawItem(shop.itemSize, shop.itemPos, shop.item, shop.font, player.capasity, player.reach, player.evolution);
						shop::drawClose(shop.closeSize, shop.closePos, shop.closeTex1, shop.closeTex2, shop.closeState);
						shop::drawBuy(shop.buySize, shop.buyPos, shop.buyTex1, shop.buyTex2, shop.buyState);
					}
					break;
				case GameplayModes::Descend:
#if _DEBUG
					DrawRectangleLines(static_cast<int>(stop1.x), static_cast<int>(stop1.y), static_cast<int>(stop1.width),
						static_cast<int>(stop1.height), YELLOW);
					DrawRectangleLines(static_cast<int>(stop2.x), static_cast<int>(stop2.y), static_cast<int>(stop2.width),
						static_cast<int>(stop2.height), YELLOW);
					DrawRectangleLines(static_cast<int>(stop3.x), static_cast<int>(stop3.y), static_cast<int>(stop3.width),
						static_cast<int>(stop3.height), YELLOW);
#endif

					for (int i = 0; i < fishAmount; i++) {
						fishs::drawFish(fish[i].position.x, fish[i].position.y, fish[i].size.x, fish[i].size.y, fish[i].type,
							fish[i].dir, fish[i].small1, fish[i].small2, fish[i].medium1, fish[i].medium2, fish[i].big1, fish[i].big2);
					}
					break;
				case GameplayModes::Ascend:
					for (int i = 0; i < fishAmount; i++) {
						if (fish[i].active) {
							fishs::drawFish(fish[i].position.x, fish[i].position.y, fish[i].size.x, fish[i].size.y, fish[i].type,
								fish[i].dir, fish[i].small1, fish[i].small2, fish[i].medium1, fish[i].medium2, fish[i].big1, fish[i].big2);
						}
					}
					break;
				default:
					break;
				}
				break;
				//EndMode2D();
				break;
			case GameStage::Pause:
				DrawTexture(bigBox, static_cast<int>(boxPosX), static_cast<int>(boxPosY), WHITE);
				DrawTextEx(font, "Press P ro go back to the game", { 23,70 }, 24, 3, BLACK);
				DrawTextEx(font, "Press Menu to go back and lose progress", { 23,95 }, 24, 3, BLACK);
				DrawTextEx(font, "Press M to mute or un mute", { 23,140 }, 24, 3, BLACK);
				DrawTextEx(font, "you can only use the mute and menu options", { 23,165 }, 24, 3, BLACK);
				DrawTextEx(font, "Once the hand is at the top", { 23,190 }, 24, 3, BLACK);

				if (menuState) {
					DrawTexture(menuTex1, static_cast<int>(rec2M.x), static_cast<int>(rec2M.y) - 45, WHITE);
				}
				else {
					DrawTexture(menuTex2, static_cast<int>(rec2M.x), static_cast<int>(rec2M.y) - 45, WHITE);
				}


				break;
			case  GameStage::Victory:
				break;
			}
			EndMode2D();

			EndDrawing();
		}

		void initFishGameplay() {
			for (int i = 0; i < 20; i++) {
				fishs::initFish(fish[i].size, fish[i].position, fish[i].active, fish[i].type, fish[i].dir, fish[i].small1, fish[i].small2,
					fish[i].medium1, fish[i].medium2, fish[i].big1, fish[i].big2, fishArea1);
			}

			for (int j = 20; j < 40; j++) {
				fishs::initFish(fish[j].size, fish[j].position, fish[j].active, fish[j].type, fish[j].dir, fish[j].small1, fish[j].small2,
					fish[j].medium1, fish[j].medium2, fish[j].big1, fish[j].big2, fishArea2);
			}
			
			for (int k = 40; k < fishAmount; k++) {
				fishs::initFish(fish[k].size, fish[k].position, fish[k].active, fish[k].type, fish[k].dir, fish[k].small1, fish[k].small2,
					fish[k].medium1, fish[k].medium2, fish[k].big1, fish[k].big2, fishArea3);
			}
		}
	}
}