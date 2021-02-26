#pragma once
#include "Commons.h"
#include "Character.h"
class Collisions
{
private:
	Collisions();
	static Collisions* m_instance;
public:
	~Collisions();

	static Collisions* Instance();

	bool CheckCollision(Collider* coll1, Collider* coll2);
};

