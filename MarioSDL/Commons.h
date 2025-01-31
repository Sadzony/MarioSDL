#pragma once
#include <typeinfo>
struct Vector2D {
	float x;
	float y;
	Vector2D() {
		x = 0.0f;
		y = 0.0f;
	}
	Vector2D(float p_x, float p_y) {
		x = p_x;
		y = p_y;
	}
};
enum SCREENS {
	SCREEN_INTRO,
	SCREEN_MENU,
	SCREEN_LEVEL1,
	SCREEN_LEVEL2,
	SCREEN_GAMEOVER,
	SCREEN_HIGHSCORES
};
enum FACING {
	FACING_LEFT,
	FACING_RIGHT
};


