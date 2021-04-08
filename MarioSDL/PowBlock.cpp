#include "PowBlock.h"

PowBlock::PowBlock(SDL_Renderer* renderer, LevelMap* map, float posX, float posY)
{
	m_renderer = renderer;
	m_map = map;
	m_texture = new Texture2D(m_renderer);
	std::string imagePath = "Images/PowBlock.png";
	if (!m_texture->LoadFromFile(imagePath)) {
		std::cerr << "Failed to load texture at: " << imagePath << std::endl;
		return;
	}
	m_map = map;
	singleWidth = m_texture->GetWidth() / 3;
	singleHeight = m_texture->GetHeight();
	num_hits_left = 3;
	m_position = Vector2D(posX, posY);
	collider = new Rect2D(singleWidth, singleHeight, posX, posY);
}

PowBlock::~PowBlock()
{
	m_renderer = nullptr;
	delete m_texture;
	m_texture = nullptr;
	m_map = nullptr;
	delete collider;
	collider = nullptr;
}

void PowBlock::Render()
{
	if (num_hits_left > 0) {
		int left = singleWidth * (num_hits_left - 1);
		SDL_Rect srcRect = { left, 0, singleWidth, singleHeight };
		SDL_Rect posRect = { (int)m_position.x, (int)m_position.y, singleWidth, singleHeight };
		m_texture->Render(posRect, srcRect, SDL_FLIP_NONE);
	}
}

void PowBlock::TakeHit()
{
	num_hits_left--;
	if (num_hits_left <= 0) {
		num_hits_left = 0;
		m_map->ChangeTileAt(8, 7, 0);
		m_map->ChangeTileAt(8, 8, 0);
	}
}
