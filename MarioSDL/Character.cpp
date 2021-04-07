#include "Character.h"
void Character::MoveLeft(float deltaTime, float speed)
{
	m_faceDirection = FACING_LEFT;
	m_position.x -= deltaTime * speed;
}
void Character::MoveRight(float deltaTime, float speed)
{
	m_faceDirection = FACING_RIGHT;
	m_position.x += deltaTime * speed;
}
void Character::AddGravity(float deltaTime)
{
	if (!m_jumping) {
		m_can_jump = false;
		m_position.y += GRAVITY * deltaTime;
	}
}
Character::Character(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map)
{
	m_current_level_map = map;
	isAlive = true;
	m_faceDirection = FACING_RIGHT;
	m_renderer = renderer;
	m_position = start_position;
	m_texture = new Texture2D(m_renderer);
	if (m_texture->LoadFromFile(imagePath) == false) {
		std::cerr << "Image could not be loaded from " << imagePath << std::endl;
	}
	collider = new Rect2D(32, m_texture->GetHeight(), start_position.x, start_position.y);
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
	int rightXposition = (int)(m_position.x + 32) / TILE_WIDTH;
	int foot_position = (int)(m_position.y + m_texture->GetHeight()) / TILE_HEIGHT;
	int centralXposition = ((int)(m_position.x) + (32 * 0.5f)) / TILE_WIDTH;
	if (m_current_level_map->GetTileAt(foot_position, centralXposition) == 2) {
		if (m_position.x > (SCREEN_WIDTH * 0.5f) + 8 || m_position.x + 32 < (SCREEN_WIDTH * 0.5f) - 8) {
			AddGravity(deltaTime);
		}
		else{ //if im colliding with pow
			int remainder = ((int)m_position.y + m_texture->GetHeight()) % 32;
			if (remainder != 0) {
				//find out how far into pow we are
				float leftC, leftP, rightC, rightP, diff;
				leftC = m_position.x;
				leftP = 240.0f;
				rightC = m_position.x + 32;
				rightP = 272.0f;
				if (rightC > leftP && leftC < leftP) {
					diff = rightC - leftP;
					m_position.x = m_position.x - diff;
				}
				else if (leftC < rightP && rightC > rightP) {
					diff = rightP - leftC;
					m_position.x = m_position.x + diff;
				}
				AddGravity(deltaTime);
			}
			else {
				m_can_jump = true;
			}
		}
	}
	else if (m_current_level_map->GetTileAt(foot_position, leftXposition) == 0 && m_current_level_map->GetTileAt(foot_position, rightXposition) == 0) {
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
				m_position.x = (int)m_position.x - 32 - Xremainder + 32;
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

void Character::CancelJump()
{
	m_jumping = false;
	m_jump_force = JUMP_FORCE;
}

void Character::SetPosition(Vector2D new_position)
{
	m_position = new_position;
	collider->SetPosition(new_position.x, new_position.y);
}

Vector2D Character::GetPosition()
{
	return m_position;
}
