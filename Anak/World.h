#pragma once
#include "Tile.h"
//#include "CellsHash.h"
#include "CellsTypesVectors.h"
#include <vector>
#include <string>
#include "CellsHash.h"

class World
{
public:
	std::vector<std::vector<Tile*>> tilesMap;
	CellsHash* cellsHash;
	CellsTypesVectors* cellsTypesVectors;


	World(const std::vector<std::vector<std::string>>& sizesTilesMatrixrix);
	Tile* GetTile(int& x, int& y);
	Manufacture1* SelectedHighObject(const Coordinate& coord);

private:

	int tileHeight;
	int tileWidth;



};

