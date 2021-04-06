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
class Enemy
{
protected:
	LevelMap* m_current_level_map;
	Rect2D* collider;
	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;
	FACING m_faceDirection;
	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);
	virtual void AddGravity(float deltaTime);
public:
	Enemy(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map);
	~Enemy();
	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	void SetPosition(Vector2D new_position);
	Rect2D* GetCollider() { return collider; }
	Vector2D GetPosition();
};

