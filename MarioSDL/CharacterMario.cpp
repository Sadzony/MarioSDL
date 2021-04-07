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
		MoveLeft(deltaTime, MARIO_SPEED);
	}
	else if (movingRight) {
		MoveRight(deltaTime, MARIO_SPEED);
	}
	JumpCalculations(deltaTime);
	collider->SetPosition(m_position.x, m_position.y);
}
