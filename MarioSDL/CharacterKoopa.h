#pragma once
#include "Character.h"
class CharacterKoopa :
    public Character
{
private:
    float m_movement_speed;
    float singleSpriteH;
    float singleSpriteW;
    bool m_injured;
    float m_injured_time;
    void FlipRightwayUp();
public:
    CharacterKoopa(SDL_Renderer* renderer, std::string imagePath, LevelMap* map, Vector2D start_position, FACING startFacing, float movement_speed);
    ~CharacterKoopa();
    void TakeDamage();
    void Jump();
    void Render() override;
    void Update(float deltaTime, SDL_Event e) override;
    bool GetInjured() { return m_injured; };

};

