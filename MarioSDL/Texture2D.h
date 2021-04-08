#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include <string>
#include "Commons.h"
#ifndef _TEXTURE2D_H
#define _TEXTURE2D_H


class Texture2D
{
public:
	Texture2D(SDL_Renderer* renderer);
	~Texture2D();
	bool LoadFromFile(std::string path);
	void Free();
	void Render(Vector2D new_position, SDL_RendererFlip flip, double angle = 0.0f);
	void Render(SDL_Rect posRect, SDL_Rect srcRecct, SDL_RendererFlip flip, double angle = 0.0f);

	int GetWidth() { return m_width; }
	int GetHeight() { return m_height; }
private:
	int m_width;
	int m_height;

	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
};
#endif
