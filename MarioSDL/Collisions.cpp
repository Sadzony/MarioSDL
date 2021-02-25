#include "Collisions.h"

Collisions::Collisions()
{
}

Collisions::~Collisions()
{
}

Collisions* Collisions::Instance()
{
	return nullptr;
}

bool Collisions::Circle(Character* character1, Character* character2)
{
	return false;
}

bool Collisions::Box(Rect2D rect1, Rect2D rect2)
{
	return false;
}
