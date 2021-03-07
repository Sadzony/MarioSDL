#include "PowBlock.h"



PowBlock::PowBlock(SDL_Renderer* renderer, LevelMap* map, float x_pos, float y_pos)
{
	std::string imagePath = "Images/PowBlock.png";
	m_texture = new Texture2D(renderer);
	if (!m_texture->LoadFromFile(imagePath.c_str())) {
		std::cerr << "Failed to load texture at " << imagePath << std::endl;
		return;
	}
	m_map = map;
	m_single_sprite_w = m_texture->GetWidth() / 3;
	m_single_sprite_h = m_texture->GetHeight();
	m_num_hits_left = 3;
	m_position = Vector2D(x_pos, y_pos);
	collider = new Rect2D(m_single_sprite_w, m_single_sprite_h, x_pos, y_pos);
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
	if (m_num_hits_left > 0) {
		int left = m_single_sprite_w * (m_num_hits_left - 1);
		SDL_Rect portion_of_sprite = { left, 0, m_single_sprite_w, m_single_sprite_h };
		SDL_Rect dest_rect = { static_cast<int>(m_position.x), static_cast<int>(m_position.y), m_single_sprite_w, m_single_sprite_h };
		m_texture->Render(dest_rect, portion_of_sprite, SDL_FLIP_NONE);
	}
}
void PowBlock::TakeHit()
{
	m_num_hits_left--;
	if (m_num_hits_left <= 0) {
		m_num_hits_left = 0;
		m_map->ChangeTileAt(8, 7, 0);
		m_map->ChangeTileAt(8, 8, 0);
	}
}

