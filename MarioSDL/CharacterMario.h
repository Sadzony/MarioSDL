#pragma once
#include "Character.h"
class CharacterMario :
    public Character
{
public:
    CharacterMario(SDL_Renderer* renderer, std::string imagePath, Vector2D startPos, LevelMap* map);
    void Update(float deltaTime, SDL_Event e) override;
};

