#ifndef Fish_H
#define Fish_H

#include "raylib.h"

namespace fish {
	namespace fishs {

		struct Fish {
			Vector2 position;
			Vector2 size;
			bool active;
			int area;
			int type;
			bool dir;
			Texture2D small1;
			Texture2D small2;
			Texture2D medium1;
			Texture2D medium2;
			Texture2D big1;
			Texture2D big2;

		};

		void initFish(Vector2& fishSize, Vector2& fishPosition, bool& active, int& type, bool& dir, Texture2D& small1, Texture2D& small2,
			Texture2D& medium1, Texture2D& medium2, Texture2D& big1, Texture2D& big2);
		void initFish2(Vector2& fishSize, Vector2& fishPosition, bool& active, int& type, bool& dir, Texture2D& small1, Texture2D& small2,
			Texture2D& medium1, Texture2D& medium2, Texture2D& big1, Texture2D& big2);
		void initFish3(Vector2& fishSize, Vector2& fishPosition, bool& active, int& type, bool& dir, Texture2D& small1, Texture2D& small2,
			Texture2D& medium1, Texture2D& medium2, Texture2D& big1, Texture2D& big2);
		void movement(float& fishPosX, float& fishWidth, bool& type);
		void drawFish(float& fishPosX, float& fishPosY, float& fishSizeX, float& fishSizeY, int& type, bool& dir, Texture2D& small1, Texture2D& small2,
			Texture2D& medium1, Texture2D& medium2, Texture2D& big1, Texture2D& big2);
		void deactivate(bool& active, int& points, int& type);
		void deactivate2(bool& active, int& points, int& type);
		void deactivate3(bool& active, int& points, int& type);

	}
}
#endif