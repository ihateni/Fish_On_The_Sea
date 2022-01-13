#include "player.h"

namespace fish {
	namespace player {
		void fall(float& fall) {
			fall += 1000 * GetFrameTime();
		}
	}
}