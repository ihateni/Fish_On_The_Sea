#ifndef Gameplay_H
#define Gameplay_H


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

		extern GameStage Stage;
		extern GameplayModes Modes;

		void gameplayInit();
		void gameplayUpdate();

	}
}
#endif // Gameplay_H