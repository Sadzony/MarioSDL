#include "Texture2D.h"
Texture2D::Texture2D(SDL_Renderer* renderer) {
	m_renderer = renderer;
    m_texture = nullptr;
    m_height = 0;
    m_width = 0;
}
Texture2D::~Texture2D() {
	Free();
	m_renderer = nullptr;
}
bool Texture2D::LoadFromFile(std::string path)
{
    Free();
    //Load the image
    SDL_Surface* p_surface = IMG_Load(path.c_str());
    if (p_surface != nullptr) {
        SDL_SetColorKey(p_surface, SDL_TRUE, SDL_MapRGB(p_surface->format, 0, 0XFF, 0XFF));
        m_texture = SDL_CreateTextureFromSurface(m_renderer, p_surface);
        if (m_texture == nullptr) {
            std::cout << "Unable to get texture from surfacce. Error: " << SDL_GetError();
        }
        else {
            m_width = p_surface->w;
            m_height = p_surface->h;
        }
        SDL_FreeSurface(p_surface);
    }
    else {
        std::cout << "Unable to create texture from surface. Error: " << IMG_GetError();
    }
    return m_texture != nullptr;
}

void Texture2D::Free()
{
	if (m_texture != nullptr) {
		SDL_DestroyTexture(m_texture);
		m_texture = nullptr;
		m_width = 0;
		m_height = 0;

	}
}

void Texture2D::Render(Vector2D position, SDL_RendererFlip flip, double angle)
{
	SDL_Rect renderLocation = { position.x,position.y, m_width, m_height};
	SDL_RenderCopyEx(m_renderer, m_texture, nullptr, &renderLocation, 0, nullptr, flip);
}

void Texture2D::Render(SDL_Rect dest_rect, SDL_Rect src_rect, SDL_RendererFlip flip, double angle)
{
    SDL_RenderCopyEx(m_renderer, m_texture, &src_rect, &dest_rect, 0, nullptr, flip);
}
