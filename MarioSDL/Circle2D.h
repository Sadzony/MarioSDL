#pragma once
#include "Collider.h"
#include "Rect2D.h"
class Circle2D : public Collider {
public:
	float radius;
	Circle2D(float pradius, float px, float py) : Collider(px, py) {
		radius = pradius;
	}
	bool CheckCollision(Collider* collider) override;
};