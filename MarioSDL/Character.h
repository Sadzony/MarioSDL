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
class Texture2D;
class Character
{
protected:
	bool isAlive;
	LevelMap* m_current_level_map;
	Rect2D* collider;
	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;
	FACING m_faceDirection;
	bool movingLeft = false;
	bool movingRight = false;
	bool m_jumping = false;
	bool m_can_jump = false;
	float m_jump_force = JUMP_FORCE;
	virtual void MoveLeft(float deltaTime, float speed);
	virtual void MoveRight(float deltaTime, float speed);
	virtual void AddGravity(float deltaTime);
public:
	Character(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map);
	~Character();
	bool isJumping() { return m_jumping; }
	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	void JumpCalculations(float deltaTime);
	void HeadCollision(float deltaTime);
	void CancelJump();
	void SetPosition(Vector2D new_position);
	Rect2D* GetCollider() { return collider; }
	Vector2D GetPosition();
	bool GetAlive() { return isAlive; };
	void SetAlive(bool newVal) { isAlive = newVal; };
};

