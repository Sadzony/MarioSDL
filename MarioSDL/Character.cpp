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

void Character::JumpCalculations(float deltaTime)
{
	int leftXposition = (int)(m_position.x) / TILE_WIDTH;
	int rightXposition = (int)(m_position.x + m_texture->GetWidth()) / TILE_WIDTH;
	int foot_position = (int)(m_position.y + m_texture->GetHeight()) / TILE_HEIGHT;
	if (m_current_level_map->GetTileAt(foot_position, leftXposition) == 0 && m_current_level_map->GetTileAt(foot_position, rightXposition) == 0) {
		AddGravity(deltaTime);
	}
	else { //if im colliding with the map

		int remainder = ((int)m_position.y + m_texture->GetHeight()) % 32; //check if foot pos is a multiple of 32

		if (remainder != 0 && !m_jumping) { //if its not, that means we're inside tile.
			int Xremainder = ((int)m_position.x) % 32; //calculate remainder of X position
			if (m_current_level_map->GetTileAt(foot_position, leftXposition) == 1) {	//push left or right depending on direction
				m_position.x = (int)m_position.x + 32 - Xremainder;

			}
			else if (m_current_level_map->GetTileAt(foot_position, rightXposition) == 1) {
				m_position.x = (int)m_position.x - 32 - Xremainder + m_texture->GetWidth();
			}
			AddGravity(deltaTime); //since we're not on tile, add gravity again.
		}
		else {

			m_can_jump = true;
		}
	}

	if (m_jumping) {
		m_position.y -= m_jump_force * deltaTime;
		m_jump_force -= JUMP_FORCE_DECREMENT * deltaTime;
		if (m_jump_force <= 0.0f) {
			m_jumping = false;
			m_jump_force = JUMP_FORCE;
		}
	}
}

void Character::SetPosition(Vector2D new_position)
{
	m_position = new_position;
}

Vector2D Character::GetPosition()
{
	return m_position;
}
