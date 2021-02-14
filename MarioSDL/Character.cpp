#include "Character.h"
void Character::MoveLeft(float deltaTime)
{
	m_faceDirection = FACING_LEFT;
	m_position.x -= deltaTime * MARIO_SPEED;
}
void Character::MoveRight(float deltaTime)
{
	m_faceDirection = FACING_RIGHT;
	m_position.x += deltaTime * MARIO_SPEED;
}
void Character::AddGravity(float deltaTime)
{
	if (m_position.y + m_texture->GetHeight() < SCREEN_HEIGHT && !m_jumping) {
		m_can_jump = false;
		m_position.y += GRAVITY * deltaTime;
	}
	else if(!(m_position.y + m_texture->GetHeight() < SCREEN_HEIGHT) && !m_jumping){
		m_jump_force = JUMP_FORCE;
		m_can_jump = true;
	}
}
Character::Character(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position)
{
	m_faceDirection = FACING_RIGHT;
	m_renderer = renderer;
	m_position = start_position;
	m_texture = new Texture2D(m_renderer);
	if (m_texture->LoadFromFile(imagePath) == false) {
		std::cerr << "Image could not be loaded from " << imagePath << std::endl;
	}
}

Character::~Character()
{
	m_renderer = nullptr;
}

void Character::Render()
{
	if (m_faceDirection == FACING_LEFT) {
		m_texture->Render(m_position, SDL_FLIP_HORIZONTAL);
	}
	else if (m_faceDirection == FACING_RIGHT) {
		m_texture->Render(m_position, SDL_FLIP_NONE);
	}
}

void Character::Update(float deltaTime, SDL_Event e)
{

}

void Character::SetPosition(Vector2D new_position)
{
	m_position = new_position;
}

Vector2D Character::GetPosition()
{
	return m_position;
}
