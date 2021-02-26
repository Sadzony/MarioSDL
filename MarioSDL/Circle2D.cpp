#include "Circle2D.h"
bool Circle2D::CheckCollision(Collider* collider)
{
	if (typeid(collider).name() == "Circle2D*") {
		Circle2D* circle = (Circle2D*)collider;
		Vector2D vec = Vector2D(x - circle->x, y - circle->y);
		double distance = sqrt((vec.x * vec.x) + (vec.y * vec.y));
		double radii = radius + circle->radius;
		if (distance <= radii) {
			circle = nullptr;
			return true;
		}
		circle = nullptr;
	}
	else if (typeid(collider).name() == "Rect2D*") {
		Rect2D* rect = (Rect2D*)collider;
		float closestX, closestY;
		if (x < rect->x) closestX = x;
		else if (x > rect->x + rect->_width) closestX = rect->x + rect->_width;

		if (y < rect->y) closestY = y;
		else if (y > rect->y + rect->_height) closestY = rect->y + rect->_height;

		float distX = x - closestX;
		float distY = y - closestY;
		float distance = sqrt((distX * distX) + (distY * distY));

		if (distance <= radius) {
			rect = nullptr;
			return true;
		}
		rect = nullptr;
	}
	return false;
}