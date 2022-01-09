#include "manager.h"

#include "raylib.h"

#include "Screens/Menu/menu.h"
//#include "Screens/Gameplay/gameplay.h"
//#include "Screens/Credits/credits.h"
//#include "Screens/Controls/controls.h"

namespace breakout {
	namespace gameManager {

		GameScreen Screens = GameScreen::Menu;

		const int screenWidth = 1000;
		const int screenHeight = 550;
		static bool playing = true;

		static void change();
		static void deInit();
		static 	void Init();

		void run() {
			InitWindow(screenWidth, screenHeight, "Fish On The Sea V0.2");

			Init();

			while (!WindowShouldClose() && playing) {
				change();

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
				//gameplay::gameplayUpdate();
				break;
			case GameScreen::Credits:
			//	credits::creditsUpdate();
				break;
			case GameScreen::Controls:
				//controls::controlsUpdate();
				break;
			case GameScreen::End:
				playing = false;
				break;
			}
		}

		void Init() {
			menu::menuInit();
			/*gameplay::gameplayInit();
			credits::creditsInit();
			controls::controlsInit();*/
			InitAudioDevice();
		}

		void deInit() {
			CloseAudioDevice();
		}
	}
}