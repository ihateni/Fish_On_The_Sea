#ifndef GameManager_H
#define GameManager_H

namespace fish {
	namespace gameManager {
		enum class GameScreen {
			Menu = 0,
			Game,
			Credits,
			Controls,
			End,
			Pause
		};

		extern GameScreen Screens;

		void run();
	}
}
#endif // GameManger_H
