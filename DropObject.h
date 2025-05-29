#ifndef DROPOBJECT_H
#define DROPOBJECT_H

#include <raylib.h>

//---------------------------------------------
// DropObject class: represents the falling object
//---------------------------------------------
class DropObject {
protected:
    Vector2 position;
    float xVelocity, yVelocity;
public:
    virtual float GetX();
    virtual float GetY();
    virtual float GetXVelocity();
    virtual float GetYVelocity();

    virtual void SetX(const float& _x);
    virtual void SetY(const float& _y);
    virtual void SetXVelocity(const float& xVel);
    virtual void SetYVelocity(const float& yVel);

    virtual void Draw() = 0;
    virtual ~DropObject() {}
};

class Egg : public DropObject {
private:
    float radius;
public:
    float GetRadius();
    void SetRadius(const float& r);

    float GetX() override;
    float GetY() override;

    float GetXVelocity() override;
    float GetYVelocity() override;

    void SetX(const float& _x) override;
    void SetY(const float& _y) override;
    void SetXVelocity(const float& xVel);
    void SetYVelocity(const float& yVel);

    void Draw() override;
    
};

#endif