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
	collider->SetPosition(m_position.x, m_position.y);
}
void Character::AddGravity(float deltaTime)
{
	if (!m_jumping) {
		m_can_jump = false;
		m_position.y += GRAVITY * deltaTime;
		collider->SetPosition(m_position.x, m_position.y);
	}
}
Character::Character(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map)
{
	m_current_level_map = map;
	collider = new Circle2D(CHARACTER_RADIUS, start_position.x, start_position.y);
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
