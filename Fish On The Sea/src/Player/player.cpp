#include "player.h"

namespace fish {
	namespace player {
		void fall(float& fall) {
			fall += 10 * GetFrameTime();
		}
	}
}