#include "GameScreenLevel1.h"

GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	m_level_map = nullptr;
	SetLevelMap();
	SetUpLevel();
}

GameScreenLevel1::~GameScreenLevel1()
{
	delete mario;
	mario = nullptr;
	delete luigi;
	luigi = nullptr;
	delete m_background_texture;
	m_background_texture = nullptr;
	delete m_pow_block;
	m_pow_block = nullptr;
}
void GameScreenLevel1::DoScreenShake()
{
	m_screenshake = true;
	m_shake_time = SHAKE_DURATION;
	m_wobble = 0.0f;
}
bool GameScreenLevel1::SetUpLevel()
{
	m_screenshake = false;
	m_background_yPos = 0.0f;
	mario = new CharacterMario(m_renderer, "Images/Mario.png", Vector2D(64, 330), m_level_map);
	luigi = new CharacterLuigi(m_renderer, "Images/Luigi.png", Vector2D(90, 330), m_level_map);
	m_pow_block = new PowBlock(m_renderer, m_level_map, (SCREEN_WIDTH * 0.5f) - 16, 260);
	m_background_texture = new Texture2D(m_renderer);
	if (!m_background_texture->LoadFromFile("Images/BackgroundMB.png")) {
		std::cout << "Failed to load background texture!" << std::endl;
		return false;
	}
	return true;
}

void GameScreenLevel1::SetLevelMap()
{
	int map[MAP_HEIGHT][MAP_WIDTH] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									   {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
									   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									   {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
									   {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
									   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									   {0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0},
									   {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
									   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									   {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };
	if (m_level_map != nullptr) {
		delete m_level_map;
	}
	m_level_map = new LevelMap(map);
}





void GameScreenLevel1::Render()
{
	m_background_texture->Render(Vector2D(0,m_background_yPos), SDL_FLIP_NONE);
	mario->Render();
	luigi->Render();
	m_pow_block->Render();
}

void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{
	if (m_screenshake) {
		m_shake_time -= deltaTime;
		m_wobble++;
		m_background_yPos = sin(m_wobble);
		m_background_yPos *= 3.0f;
		if (m_shake_time <= 0.0f) {
			m_shake_time = SHAKE_DURATION;
			m_screenshake = false;
			m_background_yPos = 0.0f;
		}
	}
	UpdatePowBlock();
	mario->Update(deltaTime, e);
	luigi->Update(deltaTime, e);

	
}

void GameScreenLevel1::UpdatePowBlock()
{
	bool mario_collided = m_pow_block->GetCollisionBox()->CheckCollision(mario->GetCollider());
	bool luigi_collided = m_pow_block->GetCollisionBox()->CheckCollision(luigi->GetCollider());
	if (mario_collided) {
		if (m_pow_block->isAvailable() && mario->isJumping()) {
			m_pow_block->TakeHit();
			DoScreenShake();
			mario->CancelJump();
		}
	}
	if (luigi_collided) {
		if (m_pow_block->isAvailable() && luigi->isJumping()) {
			m_pow_block->TakeHit();
			luigi->CancelJump();
			DoScreenShake();
		}
	}


}
