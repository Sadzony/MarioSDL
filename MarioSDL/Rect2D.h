#pragma once
#include "Collider.h"
#include "Circle2D.h"
#include <string>
class Rect2D : public Collider {
public:
	float _width, _height;
	Rect2D(float width, float height, float px, float py) : Collider(px, py) {
		_width = width;
		_height = height;
	}
	bool CheckCollision(Collider* collider) override;
};
