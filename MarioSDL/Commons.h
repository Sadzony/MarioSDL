#pragma once
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