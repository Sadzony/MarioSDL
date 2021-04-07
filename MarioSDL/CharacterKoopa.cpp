#include "CharacterKoopa.h"

void CharacterKoopa::FlipRightwayUp()
{
	if (m_faceDirection == FACING_LEFT) {
		m_faceDirection = FACING_RIGHT;
	}
	else {
		m_faceDirection = FACING_LEFT;
	}
	m_injured = false;
	Jump();
}

CharacterKoopa::CharacterKoopa(SDL_Renderer* renderer, std::string imagePath, LevelMap* map, Vector2D start_position, FACING startFacing, float movement_speed) : Character(renderer, imagePath, start_position, map)
{
	m_faceDirection = startFacing;
	m_movement_speed = movement_speed;
	m_position = start_position;
	m_injured = false;
	singleSpriteH = m_texture->GetHeight();
	singleSpriteW = m_texture->GetWidth()/2;
}

void CharacterKoopa::TakeDamage()
{
	m_injured = true;
	m_injured_time = INJURED_TIME;
	Jump();
}

void CharacterKoopa::Jump()
{
	if (!m_jumping) {
		m_jump_force = JUMP_FORCE;
		m_jumping = true;
		m_can_jump = false;
	}
}

void CharacterKoopa::Render()
{
	int left = 0;
	if (m_injured) {
		left = singleSpriteW;
	}
	SDL_Rect portionOfSprite = { left, 0, singleSpriteW, singleSpriteH };
	SDL_Rect destRect = { (int)m_position.x, (int)m_position.y, singleSpriteW, singleSpriteH };
	if (m_faceDirection == FACING_RIGHT) {
		m_texture->Render(destRect, portionOfSprite, SDL_FLIP_NONE);
	}
	else {
		m_texture->Render(destRect, portionOfSprite, SDL_FLIP_HORIZONTAL);
	}
}

void CharacterKoopa::Update(float deltaTime, SDL_Event e)
{
	if (m_position.x + singleSpriteW > SCREEN_WIDTH && m_faceDirection == FACING_RIGHT && m_position.y < 300.0f) {
		m_faceDirection = FACING_LEFT;
	}
	else if (m_position.x < 0 && m_faceDirection == FACING_LEFT && m_position.y < 300.0f) {
		m_faceDirection = FACING_RIGHT;
	}
	if (!m_injured) {
		if (m_faceDirection == FACING_LEFT) {
			MoveLeft(deltaTime, KOOPA_SPEED);
		}
		else if (m_faceDirection == FACING_RIGHT) {
			MoveRight(deltaTime, KOOPA_SPEED);
		}
	}
	else {
		m_injured_time -= deltaTime;
		if (m_injured_time <= 0.0f) {
			FlipRightwayUp();
		}
	}
	JumpCalculations(deltaTime);
	
	collider->SetPosition(m_position.x, m_position.y);
}
