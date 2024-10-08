// DrawTiles.cpp
#include "DrawTiles.h"
#include "Game.h"
#include "../Anak/ReadConfigorations.h"

int DrawTiles::rows = 0;
int DrawTiles::cols = 0;
Mat* DrawTiles::tableImage = nullptr;

DrawTiles::DrawTiles() {
    vectorImgs.resize(7);
    vectorImgs[1] = "tile_ground";
    vectorImgs[2] = "tile_water";
    vectorImgs[3] = "tile_forest";
    vectorImgs[4] = "tile_field";
    vectorImgs[5] = "tile_road";
    vectorImgs[6] = "tile_blocks_mine";

    if (tableImage == nullptr) {
        tableImage = new Mat();
    }
}

void DrawTiles::readWorldMatrix(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<int>> matrix;
    std::string line;

    if (file.is_open()) {
        // Skip the "+World" line
        std::getline(file, line);

        while (std::getline(file, line)) {
            std::vector<int> row;
            std::stringstream ss(line);
            int number;
            while (ss >> number) {
                row.emplace_back(number);
            }
            matrix.emplace_back(row);
        }

        file.close();
    }
    else {
        std::cerr << "Unable to open file";
    }
    matrix.pop_back();

    this->World = matrix;
}

std::vector<std::vector<Mat>> DrawTiles::MakeMatrixOfImgs() {
    std::vector<std::vector<Mat>> ImgsMatrix(0);
    cout << this->World.size() << endl;
    for (const auto& row : this->World) {
        std::vector<Mat> newLine;
        for (int num : row) {
            std::string image_path = samples::findFile("images/" + vectorImgs[num] + ".png");
            Mat img = imread(image_path, IMREAD_COLOR);
            newLine.emplace_back(img);
        }
        ImgsMatrix.emplace_back(newLine);
    }
    return ImgsMatrix;
}

Mat DrawTiles::mergeImagesToTable(const vector<vector<Mat>>& imageMatrix) {
    if (imageMatrix.empty() || imageMatrix[0].empty()) {
        return Mat();
    }
    int rows = imageMatrix.size();
    int cols = imageMatrix[0].size();

    int imgHeight = imageMatrix[0][0].rows;
    int imgWidth = imageMatrix[0][0].cols;

    int tileHeghit = 5;
    //int tileHeghit = (JsonConfig::SIZES["Tile"].first);
    //int tileWidth = (JsonConfig::SIZES["Tile"].second);
    int tileWidth = 5;

    int totalHeight = imgHeight * rows * tileHeghit;
    int totalWidth = imgWidth * cols * tileWidth;

    // Create an empty image for merging
    Mat tableImage(totalHeight, totalWidth, imageMatrix[0][0].type());

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            Mat img = imageMatrix[row][col];
            if (!img.empty()) {
                // Resize the image to fit the 5x5 cell grid
                Mat resizedImg;
                resize(img, resizedImg, Size(imgWidth * tileWidth, imgHeight * tileHeghit));

                // Calculate the position of the image within the merged image
                Rect roi(col * imgWidth * tileWidth, row * imgHeight * tileHeghit, imgWidth * tileWidth, imgHeight * tileHeghit);
                resizedImg.copyTo(tableImage(roi));
            }
        }
    }

    return tableImage;
}

void DrawTiles::drawGrid(Mat& image, int rows, int cols, int cellWidth, int cellHeight) {
    // Draw regular black grid for cells within each image
    Scalar blackColor(0, 0, 0);
    int blackLineThickness = 1;

    for (int i = 0; i < rows * 5; ++i) {
        // Draw horizontal black lines
        line(image, Point(0, i * cellHeight), Point(image.cols, i * cellHeight), blackColor, blackLineThickness);
    }

    for (int j = 0; j < cols * 5; ++j) {
        // Draw vertical black lines
        line(image, Point(j * cellWidth, 0), Point(j * cellWidth, image.rows), blackColor, blackLineThickness);
    }

    // Draw wider blue lines between images
    int blueLineThickness = 3;
    Scalar blueColor(255, 0, 0);

    // Draw horizontal blue lines
    for (int i = 0; i <= rows; ++i) {
        line(image, Point(0, i * cellHeight * 5), Point(image.cols, i * cellHeight * 5), blueColor, blueLineThickness);
    }

    // Draw vertical blue lines
    for (int j = 0; j <= cols; ++j) {
        line(image, Point(j * cellWidth * 5, 0), Point(j * cellWidth * 5, image.rows), blueColor, blueLineThickness);
    }
}

void DrawTiles::displayImageTable(const vector<vector<Mat>>& imageMatrix) {
    
    if (tableImage == nullptr) {
        tableImage = new Mat();
    }

    *tableImage = mergeImagesToTable(imageMatrix);
    DrawTiles::rows = imageMatrix.size();
    DrawTiles::cols = imageMatrix[0].size();

    if (!tableImage->empty()) {
        //namedWindow("Image Table", WINDOW_AUTOSIZE);
        //destroyWindow("Image Table");
        //imshow("Image Table", *tableImage);

        //// Set the mouse callback
        //setMouseCallback("Image Table", onMouse1, nullptr);

        Game game;
        game.run();

        waitKey(0);
        destroyAllWindows(); 
    }
    else {
        cout << "Error: The table image is empty." << endl;
    }
}

