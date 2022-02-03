#ifndef Player_H
#define Player_H

#include "raylib.h"

namespace fish {
	namespace player {
		struct Player {
			Vector2 position;
			Vector2 size;
		};

		void initPlayer(Vector2& size, Vector2& position);
		void movement(float& playerPosX);
		void fall(float& playerPosY);
		void ascension(float& playerPosY);
		void drawPlayer(float& playerPosX, float& playerPosY, float& playerSizeX, float& playerSizey);

	}
}
#endif