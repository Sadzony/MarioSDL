#include "Rect2D.h"

bool Rect2D::CheckCollision(Collider* collider)
{
	{
		if (typeid(collider).name() == "Circle2D*") {
			Circle2D* circle = (Circle2D*)collider;
			float closestX, closestY;
			if (circle->x < x) closestX = x;
			else if (circle->x > x + _width) closestX = x + _width;

			if (circle->y < y) closestY = y;
			else if (circle->y > y + _height) closestY = y + _height;
			float distX = circle->x - closestX;
			float distY = circle->y - closestY;
			float distance = sqrt((distX * distX) + (distY * distY));
			if (distance <= circle->radius) {
				circle = nullptr;
				return true;
			}
			circle = nullptr;
		}
		else if (typeid(collider).name() == "Rect2D*") {
			Rect2D* rect = (Rect2D*)collider;
			if (x + (_width / 2) > rect->x &&
				x + (_width / 2) < rect->x + rect->_width &&
				y + (_height / 2) > rect->y &&
				y + (_height / 2) < rect->y + rect->_height)
			{
				return true;
			}
		}
		return false;
	}
}
