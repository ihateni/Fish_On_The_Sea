#ifndef Player_H
#define Player_H

#include "raylib.h"

namespace fish {
	namespace player {
		struct Player {
			Vector2 position;
			Vector2 size;
			int capasity;
			int reach;
			int evolution;
			Texture2D playerTex;

		};

		void initPlayer(Vector2& size, Vector2& position, int& capacity, int& reach, Texture2D& playerTex);
		void movement(float& playerPosX);
		void fall(float& playerPosY);
		void ascension(float& playerPosY);
		void drawPlayer(float& playerPosX, float& playerPosY, float& playerSizeX, float& playerSizey, Texture2D& playerTex);

	}
}
#endif