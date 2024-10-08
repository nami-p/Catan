#pragma once
#include <vector>
#include <unordered_map>
#include <utility>  // for std::pair
#include <functional>  // for std::hash
#include "Cell.h"
// Coordinate class to be used as the key in the hash map
class Coordinate {
public:
    int x, y;
    Coordinate(int x, int y) : x(x), y(y) {}

    bool operator==(const Coordinate& other) const {
        return x == other.x && y == other.y;
    }
};

// Custom hash function for Coordinate
namespace std {
    template <>
    struct hash<Coordinate> {
        size_t operator()(const Coordinate& coord) const {
            return std::hash<int>()(coord.x) ^ std::hash<int>()(coord.y);
        }
    };
}

// CellsHash class containing the hash table and its operations
class CellsHash {
public:
    std::unordered_map<Coordinate, Cell> coordinatesMap;

    CellsHash() {}

    void addCell(const Coordinate& coord, const Cell* cell) {
       coordinatesMap.insert({ coord, *cell });
    }

    Cell* findCell(const Coordinate& coord) {
        auto it = coordinatesMap.find(coord);
        if (it != coordinatesMap.end()) {
            return &(it->second);
        }
        return nullptr;
    }

   /* Manufacture* SelectedHighObject(const Coordinate& coord) {
        auto it = coordinatesMap.find(coord);
        if (it == coordinatesMap.end()) {
            return nullptr;
        }

        const Cell* cell = &it->second;
        if ((*cell->typeIndexes)[CITY] != -1) {
            return Game::world->cellsTypesVectors->cities[(*cell->typeIndexes)[CITY]];
        }
        else if ((*cell->typeIndexes)[VILLAGE] != -1) {
            return Game::world->cellsTypesVectors->villages[(*cell->typeIndexes)[VILLAGE]];
        }
        else if ((*cell->typeIndexes)[GROUNDT] != -1) {
            return Game::world->cellsTypesVectors->transports[(*cell->typeIndexes)[GROUNDT]];
        }
        else if ((*cell->typeIndexes)[AIRT] != -1) {
            return Game::world->cellsTypesVectors->transports[(*cell->typeIndexes)[AIRT]];
        }
        else if ((*cell->typeIndexes)[ROAD] != -1) {
            return Game::world->cellsTypesVectors->roads[(*cell->typeIndexes)[ROAD]];
        }
        return nullptr;
    }*/
};
