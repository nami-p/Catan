// DrawTiles.h
#pragma once
#ifndef DRAWTILES_H
#define DRAWTILES_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class DrawTiles {
private:
    std::vector<std::string> vectorImgs;
    std::vector<std::vector<int>> World;

public:
    static Mat* tableImage;
    static int rows;
    static int cols;

    DrawTiles();
    void readWorldMatrix(const std::string& filename);
    std::vector<std::vector<Mat>> MakeMatrixOfImgs();
    Mat mergeImagesToTable(const vector<vector<Mat>>& imageMatrix);
    void displayImageTable(const vector<vector<Mat>>& imageMatrix);

    static void drawGrid(Mat& image, int rows, int cols, int cellWidth, int cellHeight);
};

// Declare the onMouse function
void onMouse1(int event, int x, int y, int flags, void* userdata);

#endif // DRAWTILES_H
