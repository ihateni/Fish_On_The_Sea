#include "gameplay.h"

#include "raylib.h"

#include <iostream>

#include "Game Manager/manager.h"

#include "Player/player.h"
#include "Fish/fish.h"
#include "Shop/shop.h"

namespace fish {
	namespace gameplay {

		enum class GameStage {
			Main = 0,
			Pause,
			Victory
		};


		enum class GameplayModes {
			Shop = 0,
			Descend,
			Ascend
		};

		static void initFishGameplay();
		static void gameplayInput();
		static void gameplayDraw();

		const int fishAmount = 20;

		player::Player player;
		fishs::Fish fish[fishAmount];
		fishs::Fish fish2[fishAmount];
		fishs::Fish fish3[fishAmount];

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
		float fontPosY1;
		float fontPosY2;
		float fontPosY3;
		float fontPosY4;
		float fontPosY5;

		static int textureOffset = 45;
		static float textPausePosY[] = { 511, 531 };
		static float textPausePosX[] = { 23 };
		static float fontSize = 24;
		static float fontSpacing = 3;
		static float fishCapacity[] = { 3, 6, 10, 12 };

		static float qiFontSize = 35;
		static float qiFontSpacing = 2;

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

		GameStage Stage;
		GameplayModes Modes;

		static void gameplayReset() {
			player::initPlayer(player.size, player.position, player.capasity, player.reach, player.evolution, player.playerTex, player.evoTex1, player.evoTex2
				, player.evoTex3);
			posYSave = player.position.y;
			posXSave = player.position.x;
			fishCounter = 0;
			playState = true;
			menuState = true;

			points = 0;
#if _DEBUG
			points = 100000;
#endif

			boxPosX = 0;
			boxPosY = 0;
			fontPosY1 = 70;
			fontPosY2 = 95;
			fontPosY3 = 140;
			fontPosY4 = 165;
			fontPosY5 = 190;

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
			sphereRec.y = rec1M.y + static_cast<float>(GetScreenHeight()) * 4 - static_cast<float>(GetScreenHeight()) / 2;

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
		}

		void gameplayInit() {
			click = LoadSound("res/Sound/mixkit-unlock-game-notification-253.wav");
			sphere = LoadTexture("res/Player/sphere.png");


			GameStage::Main;
			GameplayModes::Shop;

			player::initPlayer(player.size, player.position, player.capasity, player.reach, player.evolution, player.playerTex, player.evoTex1, player.evoTex2
				, player.evoTex3);
			posYSave = player.position.y;
			posXSave = player.position.x;
			fishCounter = 0;
			background = LoadTexture("res/Background/Background.png");
			playTex1 = LoadTexture("res/Gameplay_buttons/play1.png");
			playTex2 = LoadTexture("res/Gameplay_buttons/play2.png");
			playState = true;
			bigBox = LoadTexture("res/Gameplay_buttons/box_large.png");
			font = LoadFont("res/Font/aAsianNinja.otf");
			menuTex1 = LoadTexture("res/Gameplay_buttons/menu1.png");
			menuTex2 = LoadTexture("res/Gameplay_buttons/menu2.png");
			menuState = true;

			points = 0;
#if _DEBUG
			points = 100000;
#endif

			boxPosX = 0;
			boxPosY = 0;
			fontPosY1 = 70;
			fontPosY2 = 95;
			fontPosY3 = 140;
			fontPosY4 = 165;
			fontPosY5 = 190;

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
			sphereRec.y = rec1M.y + static_cast<float>(GetScreenHeight()) * 4 - static_cast<float>(GetScreenHeight()) / 2;

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
		}

		void gameplayUpdate() {
			gameplayDraw();
			gameplayInput();
			PlayMusicStream(music);
			UpdateMusicStream(music);

			switch (Stage) {
			case GameStage::Main:
				camera.target.y =  player.position.y + player.size.y / 2;
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
					player::fall(fontPosY1);
					player::fall(fontPosY2);
					player::fall(fontPosY3);
					player::fall(fontPosY4);
					player::fall(fontPosY5);

					player::movement(player.position.x);
					if (player.capasity == 4 && player.evolution == 4 && player.reach == 4) {

					}
					else {
						player::movement(player.position.x);
					}
					for (int i = 0; i < fishAmount; i++) {
						if (fish[i].active) {
							fishs::movement(fish[i].position.x, fish[i].size.y, fish[i].dir);
						}
					}

					for (int i = 0; i < fishAmount; i++) {
						if (fish2[i].active) {
							fishs::movement(fish2[i].position.x, fish2[i].size.y, fish2[i].dir);
						}
					}

					for (int i = 0; i < fishAmount; i++) {
						if (fish3[i].active) {
							fishs::movement(fish3[i].position.x, fish3[i].size.y, fish3[i].dir);
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
					case 4:
						if (player.capasity == 4 && player.evolution == 4 && player.reach == 4) {

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
						gameplayReset();
						Modes = GameplayModes::Shop;
						player.position.y = posYSave;
						gameManager::Screens = gameManager::GameScreen::Victory;
					}
					if (player.position.y > sphereRec.y) {
						gameplayReset();

						Modes = GameplayModes::Shop;
						player.position.y = posYSave;
						gameManager::Screens = gameManager::GameScreen::Victory;
					}

					break;
				case GameplayModes::Ascend:
					player::movement(player.position.x);
					player::ascension(player.position.y);
					player::ascension(boxPosY);
					player::ascension(fontPosY1);
					player::ascension(fontPosY2);
					player::ascension(fontPosY3);
					player::ascension(fontPosY4);
					player::ascension(fontPosY5);


					for (int i = 0; i < fishAmount; i++) {
						if (fish[i].active) {
							fishs::movement(fish[i].position.x, fish[i].size.y, fish[i].dir);
						}
					}
					for (int i = 0; i < fishAmount; i++) {
						if (fish2[i].active) {
							fishs::movement(fish2[i].position.x, fish2[i].size.y, fish2[i].dir);
						}
					}

					for (int i = 0; i < fishAmount; i++) {
						if (fish3[i].active) {
							fishs::movement(fish3[i].position.x, fish3[i].size.y, fish3[i].dir);
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
								if (fishCounter < fishCapacity[0]) {
									if (fish[i].active == true) {
										fishs::deactivate(fish[i].active, points, fish[i].type);
										fishCounter++;
									}
								}
								break;
							case 2:
								if (fishCounter < fishCapacity[1]) {
									if (fish[i].active == true) {
										fishs::deactivate(fish[i].active, points, fish[i].type);
										fishCounter++;
									}
								}
								break;
							case 3:
								if (fishCounter < fishCapacity[2]) {
									if (fish[i].active == true) {
										fishs::deactivate(fish[i].active, points, fish[i].type);
										fishCounter++;
									}
								}
							case 4:
								if (fishCounter < fishCapacity[3]) {
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

					for (int i = 0; i < fishAmount; i++) {
						if (CheckCollisionRecs({ player.position.x, player.position.y,player.size.x,player.size.y }, { fish2[i].position.x,
							fish2[i].position.y,fish2[i].size.x,fish2[i].size.y })) {
							switch (player.capasity) {
							case 1:
								if (fishCounter < fishCapacity[0]) {
									if (fish2[i].active == true) {
										fishs::deactivate(fish2[i].active, points, fish2[i].type);
										fishCounter++;
									}
								}
								break;
							case 2:
								if (fishCounter < fishCapacity[1]) {
									if (fish2[i].active == true) {
										fishs::deactivate(fish2[i].active, points, fish2[i].type);
										fishCounter++;
									}
								}
								break;
							case 3:
								if (fishCounter < fishCapacity[2]) {
									if (fish2[i].active == true) {
										fishs::deactivate(fish2[i].active, points, fish2[i].type);
										fishCounter++;
									}
								}
								break;
							case 4:
								if (fishCounter < fishCapacity[3]) {
									if (fish2[i].active == true) {
										fishs::deactivate(fish2[i].active, points, fish2[i].type);
										fishCounter++;
									}
								}
								break;
							default:
								break;
							}
						}
					}

					for (int i = 0; i < fishAmount; i++) {
						if (CheckCollisionRecs({ player.position.x, player.position.y,player.size.x,player.size.y }, { fish3[i].position.x,
							fish3[i].position.y,fish3[i].size.x,fish3[i].size.y })) {
							switch (player.capasity) {
							case 1:
								if (fishCounter < fishCapacity[0]) {
									if (fish3[i].active == true) {
										fishs::deactivate(fish3[i].active, points, fish3[i].type);
										fishCounter++;
									}
								}
								break;
							case 2:
								if (fishCounter < fishCapacity[1]) {
									if (fish3[i].active == true) {
										fishs::deactivate(fish3[i].active, points, fish3[i].type);
										fishCounter++;
									}
								}
								break;
							case 3:
								if (fishCounter < fishCapacity[2]) {
									if (fish3[i].active == true) {
										fishs::deactivate(fish3[i].active, points, fish3[i].type);
										fishCounter++;
									}
								}
								break;
							case 4:
								if (fishCounter < fishCapacity[3]) {
									if (fish3[i].active == true) {
										fishs::deactivate(fish3[i].active, points, fish3[i].type);
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
								shop::upgradeItem(shop.item, player.capasity, player.reach, points, player.evolution);
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
						gameplayReset();

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
				player::drawPlayer(player.position.x, player.position.y, player.size.x, player.size.y, player.playerTex, player.evoTex1, player.evoTex2,
					player.evoTex3, player.evolution);
#if _DEBUG

				DrawRectangleLines(static_cast<int>(sphereRec.x), static_cast<int>(sphereRec.y), static_cast<int>(sphereRec.width),
					static_cast<int>(sphereRec.height), BLACK);
#endif
				DrawTexture(sphere, static_cast<int>(sphereRec.x), static_cast<int>(sphereRec.y), WHITE);

				switch (Modes) {
				case GameplayModes::Shop:
					if (!activeShop) {
						DrawTextEx(font, TextFormat("QI: %i", points), { static_cast<float>(GetScreenWidth() - 200), 30 }, qiFontSize, qiFontSpacing, BLACK);

#if _DEBUG

						DrawRectangleLines(static_cast<int>(rec1M.x), static_cast<int>(rec1M.y), static_cast<int>(rec1M.width),
							static_cast<int>(rec1M.height), RED);
#endif
						if (playState) {
							DrawTexture(playTex1, static_cast<int>(rec1M.x), static_cast<int>(rec1M.y) - textureOffset, WHITE);
						}
						else {
							DrawTexture(playTex2, static_cast<int>(rec1M.x), static_cast<int>(rec1M.y) - textureOffset, WHITE);
						}

						shop::drawOpen(shop.openSize, shop.openPos, shop.closeTex1, shop.closeTex2, shop.openState);
					}
					else {
						DrawTextEx(font, TextFormat("QI: %i", points), { static_cast<float>(GetScreenWidth() - 200), 30 }, qiFontSize, qiFontSpacing, BLACK);
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

					for (int i = 0; i < fishAmount; i++) {
						fishs::drawFish(fish2[i].position.x, fish2[i].position.y, fish2[i].size.x, fish2[i].size.y, fish2[i].type,
							fish2[i].dir, fish2[i].small1, fish2[i].small2, fish2[i].medium1, fish2[i].medium2, fish2[i].big1, fish2[i].big2);
					}

					for (int i = 0; i < fishAmount; i++) {
						fishs::drawFish(fish3[i].position.x, fish3[i].position.y, fish3[i].size.x, fish3[i].size.y, fish3[i].type,
							fish3[i].dir, fish3[i].small1, fish3[i].small2, fish3[i].medium1, fish3[i].medium2, fish3[i].big1, fish3[i].big2);
					}
					
					break;
				case GameplayModes::Ascend:
				
					switch (player.capasity) {
					case 1:
						if (fishCounter <= fishCapacity[0]) {
							DrawTextEx(font, TextFormat("Fish left to capture: %i", static_cast<int>(fishCapacity[0]) - fishCounter), { textPausePosX[0],fontPosY1 }, fontSize, fontSpacing, BLACK);

						}
						break;
					case 2:
						if (fishCounter <= fishCapacity[1]) {
							DrawTextEx(font, TextFormat("Fish left to capture: %i", static_cast<int>(fishCapacity[1]) - fishCounter), { textPausePosX[0],fontPosY1 }, fontSize, fontSpacing, BLACK);

						}
						break;
					case 3:
						if (fishCounter <= fishCapacity[2]) {
							DrawTextEx(font, TextFormat("Fish left to capture: %i", static_cast<int>(fishCapacity[2]) - fishCounter), { textPausePosX[0],fontPosY1 }, fontSize, fontSpacing, BLACK);

						}
						break;
					case 4:
						if (fishCounter <= fishCapacity[3]) {
							DrawTextEx(font, TextFormat("Fish left to capture: %i", static_cast<int>(fishCapacity[3]) - fishCounter), { textPausePosX[0],fontPosY1 }, fontSize, fontSpacing, BLACK);
						}
						break;
					default:
						break;
					}

					for (int i = 0; i < fishAmount; i++) {
						if (fish[i].active) {
							fishs::drawFish(fish[i].position.x, fish[i].position.y, fish[i].size.x, fish[i].size.y, fish[i].type,
								fish[i].dir, fish[i].small1, fish[i].small2, fish[i].medium1, fish[i].medium2, fish[i].big1, fish[i].big2);
						}
					}

					for (int i = 0; i < fishAmount; i++) {
						if (fish2[i].active) {
							fishs::drawFish(fish2[i].position.x, fish2[i].position.y, fish2[i].size.x, fish2[i].size.y, fish2[i].type,
								fish2[i].dir, fish2[i].small1, fish2[i].small2, fish2[i].medium1, fish2[i].medium2, fish2[i].big1, fish2[i].big2);
						}
					}

					for (int i = 0; i < fishAmount; i++) {
						if (fish3[i].active) {
							fishs::drawFish(fish3[i].position.x, fish3[i].position.y, fish3[i].size.x, fish3[i].size.y, fish3[i].type,
								fish3[i].dir, fish3[i].small1, fish3[i].small2, fish3[i].medium1, fish3[i].medium2, fish3[i].big1, fish3[i].big2);
						}
					}
					break;
				default:
					break;
				}
				break;
				break;
			case GameStage::Pause:
				DrawTexture(bigBox, static_cast<int>(boxPosX), static_cast<int>(boxPosY), WHITE);
				DrawTexture(bigBox, static_cast<int>(boxPosX), static_cast<int>(boxPosY), WHITE);
				DrawTextEx(font, "Press P to go back to the game", { textPausePosX[0],fontPosY1 }, fontSize, fontSpacing, BLACK);
				DrawTextEx(font, "Press Menu to go back and lose progress", { textPausePosX[0],fontPosY2 }, fontSize, fontSpacing, BLACK);
				DrawTextEx(font, "Press M to mute or unmute", { textPausePosX[0],fontPosY3 }, fontSize, fontSpacing, BLACK);
				DrawTextEx(font, "You can only use the menu options", { textPausePosX[0],fontPosY4 }, fontSize, fontSpacing, BLACK);
				DrawTextEx(font, "once the hand is at the top", { textPausePosX[0],fontPosY5 }, fontSize, fontSpacing, BLACK);
			
				if (Modes == GameplayModes::Shop)
				{
					if (menuState) {
						DrawTexture(menuTex1, static_cast<int>(rec2M.x), static_cast<int>(rec2M.y) - textureOffset, WHITE);
					}
					else {
						DrawTexture(menuTex2, static_cast<int>(rec2M.x), static_cast<int>(rec2M.y) - textureOffset, WHITE);
					}
				}
				break;
			case  GameStage::Victory:
				break;
			}
			EndMode2D();

			EndDrawing();
		}

		void initFishGameplay() {
			for (int i = 0; i < fishAmount; i++) {
				fishs::initFish(fish[i].size, fish[i].position, fish[i].active, fish[i].type, fish[i].dir, fish[i].small1, fish[i].small2,
					fish[i].medium1, fish[i].medium2, fish[i].big1, fish[i].big2);
			}

			for (int i = 0; i < fishAmount; i++) {
				fishs::initFish2(fish2[i].size, fish2[i].position, fish2[i].active, fish2[i].type, fish2[i].dir, fish2[i].small1, fish2[i].small2,
					fish2[i].medium1, fish2[i].medium2, fish2[i].big1, fish2[i].big2);
			}

			for (int i = 0; i < fishAmount; i++) {
				fishs::initFish3(fish3[i].size, fish3[i].position, fish3[i].active, fish3[i].type, fish3[i].dir, fish3[i].small1, fish3[i].small2,
					fish3[i].medium1, fish3[i].medium2, fish3[i].big1, fish3[i].big2);
			}
		}
	}
}