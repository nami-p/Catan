#ifndef GAME_H
#define GAME_H

#include "DrawTiles.h"
#include "MoovingElement.h"
#include <vector>

class Game {
public:
    Game();
    void run();
    void stopElementsInRect(const Rect& selection);
    void moveSelectedElements(const Point& target);

    std::vector<MoovingElement> people;
    Point rectStart, rectEnd;
    bool drawingRect = false ;
    bool freeze;

private:
    void update();
    void draw();
    //void movePerson(MoovingElement& person);
    Point getRandomPosition();

    Mat gameImage;
    DrawTiles drawer;


    std::vector<std::string> peopleImages; 
};

#endif // GAME_H
