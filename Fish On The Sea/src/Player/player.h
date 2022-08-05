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
			Texture2D evoTex1;
			Texture2D evoTex2;
			Texture2D evoTex3;

		};

		void initPlayer(Vector2& size, Vector2& position, int& capacity, int& reach, int& evolution, Texture2D& playerTex, Texture2D& evoTex1
			, Texture2D& evoTex2, Texture2D& evoTex3);
		void movement(float& playerPosX);
		void fall(float& playerPosY);
		void ascension(float& playerPosY);
		void drawPlayer(float& playerPosX, float& playerPosY, float& playerSizeX, float& playerSizey, Texture2D& playerTex, Texture2D& evoTex1
			, Texture2D& evoTex2, Texture2D& evoTex3, int& evolution);
		void playerDeInit(Texture2D& playerTex, Texture2D& evoTex1, Texture2D& evoTex2, Texture2D& evoTex3);
	}
}
#endif