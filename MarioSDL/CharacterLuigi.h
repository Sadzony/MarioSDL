#pragma once
#include "Character.h"
class CharacterLuigi :
    public Character
{
public:
    CharacterLuigi(SDL_Renderer* renderer, std::string imagePath, Vector2D startPos, LevelMap* map);
    void Update(float deltaTime, SDL_Event e) override;
};

