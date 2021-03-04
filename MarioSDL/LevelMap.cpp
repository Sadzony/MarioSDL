#include "LevelMap.h"

LevelMap::LevelMap(int map[MAP_HEIGHT][MAP_WIDTH])
{
    m_map = new int* [MAP_HEIGHT];
    for (unsigned int i = 0; i < MAP_HEIGHT; i++) {
        m_map[i] = new int[MAP_WIDTH];
    }
    for (unsigned int i = 0; i < MAP_HEIGHT; i++) {
        for (unsigned int j = 0; j < MAP_WIDTH; j++) {
            m_map[i][j] = map[i][j];
        }
    }
}

LevelMap::~LevelMap()
{
    for (unsigned int i = 0; i < MAP_HEIGHT; i++) {
        delete[] m_map[i];
    }
    delete[] m_map;

}

int LevelMap::GetTileAt(unsigned int y, unsigned int x)
{
    if (x < MAP_WIDTH && y < MAP_HEIGHT) {
        return m_map[y][x];
    }
    return 0;
}

void LevelMap::ChangeTileAt(unsigned int y, unsigned int x, unsigned int newVal)
{
    m_map[y][x] = newVal;
}
