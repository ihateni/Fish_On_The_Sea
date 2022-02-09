#ifndef Fish_H
#define Fish_H

#include "raylib.h"

namespace fish {
	namespace fishs {
		struct Fish {
			Vector2 position;
			Vector2 size;
			bool active;
			bool type;
			bool dir;
		};

		void initFish(Vector2& fishSize, Vector2& fishPosition,bool& active, bool& type, bool& dir);
		void movement(float& fishPosX, bool& type);
		void drawFish(float& fishPosX, float& fishPosY, float& fishSizeX, float& fishSizeY);
	}
}
#endif