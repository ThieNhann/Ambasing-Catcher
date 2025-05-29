#ifndef DROPOBJECT_H
#define DROPOBJECT_H

#include <raylib.h>

class DropObject {
private:
    float x;
    float y;
    float r;
    float xVelocity;
    float yVelocity;
public:
    float GetX();
    float GetY();
    float GetRadius();
    float GetXVelocity();
    float GetYVelocity();
    void SetRadius(const float& radius);
    void SetX(const float& _x);
    void SetY(const float& _y);
    void SetXVelocity(const float& xVel);
    void SetYVelocity(const float& yVel);
    void Draw();
public:
    DropObject() : x(0), y(0), r(0), xVelocity(0), yVelocity(0) {}
    DropObject(const float& xCord, const float& yCord, const float& radius, const float& xVel, const float& yVel) 
        : x(xCord), y(yCord), r(radius), xVelocity(xVel), yVelocity(yVel) {}
};

#endif