#pragma once
#include "GameScreen.h"
#include "Commons.h"
#include "CharacterMario.h"
#include "CharacterLuigi.h"
#include "LevelMap.h"
#ifndef _GAMESCREENLEVEL1_H
#define _GAMESCREENLEVEL1_H
class Character;
class GameScreenLevel1 :
    public GameScreen
{
private:
    CharacterMario* mario;
    CharacterLuigi* luigi;
    Texture2D* m_background_texture;
    bool SetUpLevel();
    void SetLevelMap();
    LevelMap* m_level_map;
public:
    GameScreenLevel1(SDL_Renderer* renderer);
    ~GameScreenLevel1();
    void Render() override;
    void Update(float deltaTime, SDL_Event e) override;
};
#endif
