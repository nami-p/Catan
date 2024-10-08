#include "World.h"
#include "ReadConfigorations.h" 

World::World(const std::vector<std::vector<std::string>>& sizes_tilesMatrix){

    this->tileWidth = JsonConfig::SIZES["Tile"].first;
    this->tileHeight = JsonConfig::SIZES["Tile"].second;

    
    int row_size = sizes_tilesMatrix.size();
    int coulmn_size = 0;
    if(sizes_tilesMatrix.size()>0){
        coulmn_size = sizes_tilesMatrix[0].size();
    }

    //define num of sizes_tilesMatrixrix rows
    tilesMap.resize(row_size);

    for (size_t positionY = 0; positionY < row_size; positionY++) {

        //define num of sizes_tilesMatrixrix coulmns
        tilesMap[positionY].resize(coulmn_size);

        //for (const auto& coulmn: sizes_tilesMatrixrix[row]) {
        for (size_t positionX = 0; positionX < coulmn_size; positionX++) {
            Tile* tile = new Tile(std::stoi(sizes_tilesMatrix[positionY][positionX]), this->tileWidth, tileHeight);
            tilesMap[positionY][positionX] = tile;
        }
    }

    this->cellsHash = new CellsHash();
    this->cellsTypesVectors = new CellsTypesVectors();
};

Tile* World::GetTile(int& positionX, int& positionY) {

    return tilesMap[positionY / tileHeight][positionX / tileWidth];
};

Manufacture1* World::SelectedHighObject(const Coordinate& coord) {
    auto it = cellsHash->coordinatesMap.find(coord);
    if (it == cellsHash->coordinatesMap.end()) {
        return nullptr;
    }

    const Cell* cell = &it->second;
    if ((*cell->typeIndexes)[CITY] != -1) {
        return cellsTypesVectors->cities[(*cell->typeIndexes)[CITY]];
    }
    else if ((*cell->typeIndexes)[VILLAGE] != -1) {
        return cellsTypesVectors->villages[(*cell->typeIndexes)[VILLAGE]];
    }
    else if ((*cell->typeIndexes)[GROUNDT] != -1) {
        return cellsTypesVectors->transports[(*cell->typeIndexes)[GROUNDT]];
    }
    else if ((*cell->typeIndexes)[ROAD] != -1) {
        return cellsTypesVectors->roads[(*cell->typeIndexes)[ROAD]];
    }
    else if ((*cell->typeIndexes)[PEOPLE] != -1) {
        return cellsTypesVectors->peoples[(*cell->typeIndexes)[PEOPLE]];
    }
    else if ((*cell->typeIndexes)[AIRT] != -1) {
        return cellsTypesVectors->transports[(*cell->typeIndexes)[AIRT]];
    }
    return nullptr;
};
