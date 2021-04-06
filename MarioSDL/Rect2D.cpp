#include "Rect2D.h"
#include <iostream>
bool Rect2D::CheckCollision(Collider* collider)
{
	{
		if (typeid(*collider).name() != typeid(*this).name()) {
			Circle2D* circle = (Circle2D*)collider;
			//implement circle to rect collision here
			circle = nullptr;
		}
		else if (typeid(*collider).name() == typeid(*this).name()) {
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
