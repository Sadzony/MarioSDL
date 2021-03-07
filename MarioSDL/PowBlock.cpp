#include "PowBlock.h"

PowBlock::PowBlock(SDL_Renderer* renderer, LevelMap* map, float posX, float posY)
{
	m_renderer = renderer;
	m_map = map;
	std::string imagePath = "Images/PowBlock.png";
	collider = new Rect2D(singleWidth, singleHeight, posX, posY);
}

PowBlock::~PowBlock()
{
}

void PowBlock::Render()
{
}

void PowBlock::TakeHit()
{
}
