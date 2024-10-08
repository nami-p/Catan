#include "MoovingElement.h"

MoovingElement::MoovingElement(const std::vector<Mat>& frames)
    : animationFrames(frames), currentPos(0, 0), targetPos(0, 0), moving(false), currentFrame(0) {}

void MoovingElement::move() {
    if (currentPos == targetPos) {
        moving = false;
        return;
    }

    Point direction = targetPos - currentPos;
    if (abs(direction.x) > abs(direction.y)) {
        currentPos.x += (direction.x > 0) ? 1 : -1;
    }
    else {
        currentPos.y += (direction.y > 0) ? 1 : -1;
    }

    currentFrame = (currentFrame + 1) % animationFrames.size();
}

void MoovingElement::setPosition(const Point& pos) {
    currentPos = pos;
}

Point MoovingElement::getPosition() const {
    return currentPos;
}

Mat MoovingElement::getCurrentFrame() const {
    return animationFrames[currentFrame];
}

void MoovingElement::setTarget(const Point& target) {
    targetPos = target;
    moving = true;
}

bool MoovingElement::isMoving() const {
    return moving;
}

void MoovingElement::start() {
    moving = true;
}

void MoovingElement::stop() {
    moving = false;
}


