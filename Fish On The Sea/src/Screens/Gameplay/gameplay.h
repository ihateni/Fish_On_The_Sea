#ifndef Gameplay_H
#define Gameplay_H


namespace fish {
	namespace gameplay {

		enum class GameStage {
			Main = 0,
			Pause,
			Victory
		};

		extern GameStage Stage;
		
		void gameplayInit();
		void gameplayUpdate();

	}
}
#endif // Gameplay_H