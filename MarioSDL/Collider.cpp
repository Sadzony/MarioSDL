#include "Collider.h"

Collider::Collider(float px, float py)
{
	x = px;
	y = py;

}

bool Collider::CheckCollision(Collider* collider)
{
	return false;
}

void Collider::SetPosition(float newX, float newY)
{
	x = newX;
	y = newY;
}
