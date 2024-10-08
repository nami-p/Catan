#ifndef PERSON_H
#define PERSON_H

#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

class MoovingElement {
public:
    MoovingElement(const std::vector<Mat>& frames);
    void move();
    void start();
    void stop();
    void setPosition(const Point& pos);
    Point getPosition() const;
    Mat getCurrentFrame() const;
    void setTarget(const Point& target);
    bool isMoving() const;

private:
    std::vector<Mat> animationFrames;
    Point currentPos;
    Point targetPos;
    bool moving;
    int currentFrame;
};

#endif // PERSON_H
