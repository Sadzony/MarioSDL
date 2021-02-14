#include "GameScreenLevel1.h"

GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
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
}
bool GameScreenLevel1::SetUpLevel()
{
	mario = new CharacterMario(m_renderer, "Images/Mario.png", Vector2D(64, 330));
	luigi = new CharacterLuigi(m_renderer, "Images/Luigi.png", Vector2D(90, 330));
	m_background_texture = new Texture2D(m_renderer);
	if (!m_background_texture->LoadFromFile("Images/test.bmp")) {
		std::cout << "Failed to load background texture!" << std::endl;
		return false;
	}
	return true;
}





void GameScreenLevel1::Render()
{
	m_background_texture->Render(Vector2D(0,0), SDL_FLIP_NONE);
	mario->Render();
	luigi->Render();
}

void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{
	mario->Update(deltaTime, e);
	luigi->Update(deltaTime, e);
}
