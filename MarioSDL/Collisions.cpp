#include "Collisions.h"
Collisions* Collisions::m_instance = nullptr;
Collisions::Collisions()
{
}

Collisions::~Collisions()
{
	m_instance = nullptr;
}

Collisions* Collisions::Instance()
{
	if (!m_instance) {
		m_instance = new Collisions();
	}
	return m_instance;
}
bool Collisions::CheckCollision(Collider* coll1, Collider* coll2)
{
	//find out the object types
	std::string coll1Type = typeid(coll1).name();
	std::string coll2Type = typeid(coll2).name();
	if (coll1Type == "Circle2D*" && coll2Type == "Rect2D*") {
		float closestX, closestY;
		if (coll1->x < coll2->x) closestX = coll2->x;
	}
	if (coll1Type == "Rect2D*" && coll2Type == "Circle2D*") {

	}
	if (coll1Type == "Circle2D*" && coll2Type == "Circle2D*") {

	}
	if (coll1Type == "Rect2D*" && coll2Type == "Rect2D*") {

	}
	return false;
}
