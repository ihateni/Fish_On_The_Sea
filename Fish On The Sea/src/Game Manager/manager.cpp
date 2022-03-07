#include "manager.h"

#include "raylib.h"

#include "Screens/Menu/menu.h"
#include "Screens/Gameplay/gameplay.h"
#include "Screens/Credits/credits.h"
#include "Screens/Controls/controls.h"
#include "Screens/Victory/victory.h"

namespace fish {
	namespace gameManager {

		GameScreen Screens = GameScreen::Menu;

		const int screenWidth = 500;//1000;
		const int screenHeight = 800;
		static bool playing = true;

		static void change();
		static void deInit();
		static 	void Init();

		static Music music1;

		void run() {
			InitWindow(screenWidth, screenHeight, "Fish On The Sea V1.0");

			Init();
			music1 = LoadMusicStream("res/Sound/melodyloops-preview-china-dream-10m30s.mp3");
			PlayMusicStream(music1);

			while (!WindowShouldClose() && playing) {
				change();
				UpdateMusicStream(music1);

			}
			deInit();
			CloseWindow();
		}

		static void change() {
			switch (Screens) {
			case GameScreen::Menu:
				menu::menuUpdate();
				break;
			case GameScreen::Game:
				gameplay::gameplayUpdate();
				break;
			case GameScreen::Credits:
				credits::creditsUpdate();
				break;
			case GameScreen::Controls:
				controls::controlsUpdate();
				break;
			case GameScreen::End:
				playing = false;
				break;
				break;
			case GameScreen::Victory:
				victory::victoryUpdate();
				break;
			}
		}

		void Init() {
			menu::menuInit();
			gameplay::gameplayInit();
			credits::creditsInit();
			controls::controlsInit(); 
			victory::victoryInit();
			InitAudioDevice();
		}

		void deInit() {
			menu::menuDeInit();
			credits::creditsDeInit();
			controls::controlsDeInit();
			victory::victoryDeInit();
			UnloadMusicStream(music1);

			CloseAudioDevice();
		}
	}
}