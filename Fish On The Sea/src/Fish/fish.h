#ifndef Fish_H
#define Fish_H

#include "raylib.h"

namespace fish {
	namespace fishs {
		Vector2 position;
		Vector2 size;
		bool active;
		int type;
	}

	void initFish(Vector2& size, Vector2& position);
	void movement(float& fishPosX);
}
#endif