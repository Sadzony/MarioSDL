#include "CharacterMario.h"
CharacterMario::CharacterMario(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position, LevelMap* map) : Character(renderer, imagePath, start_position, map) {
	m_faceDirection = FACING_RIGHT;
	m_renderer = renderer;
	m_position = start_position;
	m_texture = new Texture2D(m_renderer);
	if (m_texture->LoadFromFile(imagePath) == false) {
		std::cerr << "Image could not be loaded from " << imagePath << std::endl;
	}
}

void CharacterMario::Update(float deltaTime, SDL_Event e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_a:
			movingLeft = true;
			movingRight = false;
			break;
		case SDLK_d:
			movingRight = true;
			movingLeft = false;
			break;
		case SDLK_w:
			if (m_can_jump) {
				m_jumping = true;
			}
			break;
		}
		break;
	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_a:
			movingLeft = false;
			break;
		case SDLK_d:
			movingRight = false;
			break;
		}
	}
	if (movingLeft) {
		MoveLeft(deltaTime);
	}
	else if (movingRight) {
		MoveRight(deltaTime);
	}
	int centralXposition = (int)(m_position.x + (m_texture->GetWidth() * 0.5f)) / TILE_WIDTH;
	int foot_position = (int)(m_position.y + m_texture->GetHeight()) / TILE_HEIGHT;
	if (m_current_level_map->GetTileAt(foot_position, centralXposition) == 0) {
		AddGravity(deltaTime);
	}
	else {
		m_can_jump = true;
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
