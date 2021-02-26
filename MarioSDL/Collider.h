#pragma once
#include "Commons.h"
class Collider {
public:
	float x, y;
	Collider(float px, float py);
	virtual bool CheckCollision(Collider* collider);
	void SetPosition(float newX, float newY);
};

