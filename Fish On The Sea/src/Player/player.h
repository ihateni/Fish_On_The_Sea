#ifndef Player_H
#define Player_H

#include "raylib.h"

namespace fish {
	namespace player {
		struct Player {
			Vector2 position;
			Vector2 size;
		};

		void fall(float& fall);
	}
}
#endif