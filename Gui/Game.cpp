#include "Game.h"
#include <opencv2/opencv.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace cv;
using namespace std;


Game::Game(){
    
    freeze = false;

    peopleImages = {
        "0.png", "1.png", "2.png", "3.png", "4.png", "5.png", "6.png", "7.png", "8.png", "9.png"
    };

    // Initialize people
    for (const auto& imgPath : peopleImages) {
        std::vector<Mat> frames;
        for (int i = 1; i <= 10; ++i) {
            std::string image_path = samples::findFile("images/" +imgPath);
            Mat img = imread(image_path, IMREAD_COLOR);
            resize(img, img, Size(128, 128));
            frames.push_back(img);
        }
        //imshow("t",frames[0]);
        MoovingElement moovingElement(frames);
        moovingElement.setPosition(getRandomPosition());
        moovingElement.setTarget(getRandomPosition());
        people.push_back(moovingElement);
    }

}

void Game::run() {
    namedWindow("Game", WINDOW_AUTOSIZE);
    setMouseCallback("Game", onMouse1, this);

    while (true) {
        if (waitKey(10) == 27) {
            break; // Exit the loop on mouse click
        }
        if (!freeze) {
            update();
        }
        draw();
    }
    destroyAllWindows();
}

void Game::update() {
    for (auto& MoovingElement : people) {
        if (!MoovingElement.isMoving()) {
            MoovingElement.setTarget(getRandomPosition());
        }
        MoovingElement.move();
    }
}

//void Game::draw() {
//    Mat display = (*DrawTiles::tableImage).clone();
//
//    for (const auto& MoovingElement : people) {
//        Mat currentFrame = MoovingElement.getCurrentFrame();
//        Point pos = MoovingElement.getPosition();
//        Rect roi(pos.x, pos.y, currentFrame.cols, currentFrame.rows);
//        currentFrame.copyTo(display(roi));
//    }
//
//    imshow("Game", display);
//}

void Game::draw() {
    Mat display = (*DrawTiles::tableImage).clone();

    for (const auto& MoovingElement : people) {
        Mat currentFrame = MoovingElement.getCurrentFrame();
        Point pos = MoovingElement.getPosition();

        // Check if the position and frame size are within bounds of display
        if (pos.x >= 0 && pos.y >= 0 &&
            pos.x + currentFrame.cols <= display.cols &&
            pos.y + currentFrame.rows <= display.rows) {

            Rect roi(pos.x, pos.y, currentFrame.cols, currentFrame.rows);
            //Rect roi(0, 0, currentFrame.cols, currentFrame.rows);
            currentFrame.copyTo(display(roi));
        }
        else {
            cout << "Warning: Skipping out-of-bounds frame at position (" << pos.x << ", " << pos.y << ")" << endl;
        }
    }

    if (drawingRect) {
        rectangle(display, rectStart, rectEnd, Scalar(255, 0, 0), 2);
    }
    imshow("Game", display);
}


Point Game::getRandomPosition() {
    int maxRows = (*DrawTiles::tableImage).rows - 128; 
    int maxCols = (*DrawTiles::tableImage).cols - 128; 

    int row = rand() % maxRows;
    int col = rand() % maxCols;

    return Point(col, row);
}

//void onMouse1(int event, int x, int y, int flags, void* userdata) {
//    if (event == EVENT_LBUTTONDOWN) {
//        freeze = !freeze; // Toggle the freeze flag
//    }
//    else if (event == EVENT_RBUTTONDOWN) {
//        if (DrawTiles::tableImage != nullptr && !DrawTiles::tableImage->empty()) {
//            int rows = DrawTiles::rows;
//            int cols = DrawTiles::cols;
//            int cellWidth = DrawTiles::tableImage->cols / (cols * 5);
//            int cellHeight = DrawTiles::tableImage->rows / (rows * 5);
//            DrawTiles::drawGrid(*DrawTiles::tableImage, rows, cols, cellWidth, cellHeight);
//            destroyWindow("Game");
//            imshow("Image Table with Grid", *DrawTiles::tableImage);
//            waitKey(0);
//            destroyAllWindows();
//        }
//        else {
//            cout << "Error: The table image is empty or not initialized." << endl;
//        }
//    }
//}
//void onMouse1(int event, int x, int y, int flags, void* userdata) {
//    Game* game = static_cast<Game*>(userdata);
//
//    if (event == EVENT_LBUTTONDOWN) {
//        // Start drawing the rectangle
//        game->rectStart = Point(x, y);
//        game->rectEnd = Point(x, y);
//        game->drawingRect = true;
//    }
//    else if (event == EVENT_MOUSEMOVE) {
//        if (game->drawingRect) {
//            // Update the rectangle endpoint
//            game->rectEnd = Point(x, y);
//        }
//    }
//    else if (event == EVENT_LBUTTONUP) {
//        // Finish drawing the rectangle
//        game->drawingRect = false;
//        game->freeze = true; // Stop moving elements
//        // Check which elements are inside the rectangle
//        Rect selection(game->rectStart, game->rectEnd);
//        for (auto& moovingElement : game->people) {
//            Point pos = moovingElement.getPosition();
//            if (selection.contains(pos)) {
//                //moovingElement.stop(); 
//                // Custom method to stop the element
//            }
//        }
//    }
//    else if (event == EVENT_RBUTTONDOWN) {
//        if (DrawTiles::tableImage != nullptr && !DrawTiles::tableImage->empty()) {
//            int rows = DrawTiles::rows;
//            int cols = DrawTiles::cols;
//            int cellWidth = DrawTiles::tableImage->cols / (cols * 5);
//            int cellHeight = DrawTiles::tableImage->rows / (rows * 5);
//            DrawTiles::drawGrid(*DrawTiles::tableImage, rows, cols, cellWidth, cellHeight);
//            destroyWindow("Game");
//            imshow("Image Table with Grid", *DrawTiles::tableImage);
//            waitKey(0);
//            destroyAllWindows();
//        }
//        else {
//            cout << "Error: The table image is empty or not initialized." << endl;
//        }
//    }
//}

void Game::moveSelectedElements(const Point& target) {
    Rect selection(rectStart, rectEnd);
    for (auto& moovingElement : people) {
        Point pos = moovingElement.getPosition();
        if (selection.contains(pos)) {
            moovingElement.setTarget(target); 
            moovingElement.start(); 
        }
    }
    freeze = false; // Resume moving elements
}

void Game::stopElementsInRect(const Rect& selection) {
    for (auto& moovingElement : people) {
        Point pos = moovingElement.getPosition();
        if (selection.contains(pos)) {
            moovingElement.stop(); 
        }
    }
}

void onMouse1(int event, int x, int y, int flags, void* userdata) {
    Game* game = static_cast<Game*>(userdata);

    if (event == EVENT_LBUTTONDOWN) {
        // Start drawing the rectangle
        game->rectStart = Point(x, y);
        game->rectEnd = Point(x, y);
        game->drawingRect = true;
    }
    else if (event == EVENT_MOUSEMOVE) {
        if (game->drawingRect) {
            // Update the rectangle endpoint
            game->rectEnd = Point(x, y);
        }
    }
    else if (event == EVENT_LBUTTONUP) {
        // Finish drawing the rectangle
        game->drawingRect = false;
        game->freeze = true; // Stop moving elements
        Rect selection(game->rectStart, game->rectEnd);
        game->stopElementsInRect(selection);
    }
    else if (event == EVENT_RBUTTONDOWN) {
        // Move selected elements to the right-clicked position
        if (!game->drawingRect && game->freeze) {
            Point target(x, y);
            game->moveSelectedElements(target);
        }
    }
}

