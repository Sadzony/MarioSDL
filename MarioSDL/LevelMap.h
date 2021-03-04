#pragma once
#ifndef  _LEVELMAP_H
#define _LEVELMAP_H

#include "constants.h"

class LevelMap
{
public:
	LevelMap(int map[MAP_HEIGHT][MAP_WIDTH]);
	~LevelMap();
	int GetTileAt(unsigned int y, unsigned int x);
	void ChangeTileAt(unsigned int y, unsigned int x, unsigned int newVal);
private:
	int** m_map;
};
#endif
