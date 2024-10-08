#include "Header.h"
#include <iostream>
#include "DrawTiles.h"
#include "Game.h"

int main() {
    DrawTiles tiles;
    std::string filename = "InputWorld.txt";
    tiles.readWorldMatrix(filename);
    vector<vector<Mat>> matrixImgs = tiles.MakeMatrixOfImgs();
    tiles.displayImageTable(matrixImgs);

    
    return 0;
}