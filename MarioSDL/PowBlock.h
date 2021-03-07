#pragma once
#include "Commons.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "LevelMap.h"
#include "Rect2D.h"
#include "Texture2D.h"
#include <string>
class PowBlock
{
public:
	PowBlock(SDL_Renderer* renderer, LevelMap* map, float x_pos, float y_pos);
	~PowBlock();
	void Render();
	Rect2D* GetCollisionBox() { return collider; }
	void TakeHit();
	bool isAvailable() { return m_num_hits_left > 0; }
private:
	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;
	LevelMap* m_map;
	Rect2D* collider;

	float m_single_sprite_w;
	float m_single_sprite_h;
	int m_num_hits_left;
};

