#pragma once
#include <iostream>
#include "Commons.h"
#include "constants.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>
#include "Texture2D.h"
#include "Rect2D.h"
#include "LevelMap.h"
class PowBlock
{
public:
	PowBlock(SDL_Renderer* renderer, LevelMap* map, float posX, float posY);
	~PowBlock();
	void Render();
	Rect2D* GetCollisionBox() { return collider; };
	void TakeHit();
	bool isAvailable() { return num_hits_left > 0; }
private:
	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;
	LevelMap* m_map;
	Rect2D* collider;
	float singleWidth;
	float singleHeight;
	int num_hits_left;
};

