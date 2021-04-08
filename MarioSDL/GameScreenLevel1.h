#pragma once
#include "GameScreen.h"
#include "Commons.h"
#include "CharacterMario.h"
#include "CharacterLuigi.h"
#include "CharacterKoopa.h"
#include <vector>
#include "LevelMap.h"
#include "PowBlock.h"
#ifndef _GAMESCREENLEVEL1_H
#define _GAMESCREENLEVEL1_H
class Character;
class GameScreenLevel1 :
    public GameScreen
{
private:
    float timeToRevertBlock;
    float spawnRate;
    float timeTillNextSpawn;
    void DoScreenShake();
    bool m_screenshake;
    float m_shake_time;
    float m_wobble;
    float m_background_yPos;
    CharacterMario* mario;
    CharacterLuigi* luigi;
    Texture2D* m_background_texture;
    PowBlock* m_pow_block;
    bool SetUpLevel();
    void SetLevelMap();
    LevelMap* m_level_map;
    void UpdateEnemies(float deltaTime, SDL_Event e);
    void CreateKoopa(Vector2D position, FACING direction, float speed);
    std::vector<CharacterKoopa*> m_enemies;
public:
    GameScreenLevel1(SDL_Renderer* renderer);
    ~GameScreenLevel1();
    void Render() override;
    void Update(float deltaTime, SDL_Event e) override;
    void UpdatePowBlock();
};
#endif
