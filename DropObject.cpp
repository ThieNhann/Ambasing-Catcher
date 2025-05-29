#include "DropObject.h"

float Egg::GetRadius() { return radius;}
float Egg::GetX() { return position.x; }
float Egg::GetY() { return position.y; }
float Egg::GetXVelocity() { return xVelocity; }
float Egg::GetYVelocity() { return yVelocity; }

void Egg::SetRadius(const float& r) { radius = r; }
void Egg::SetX(const float& _x) { position.x = _x; }
void Egg::SetY(const float& _y) { position.y = _y; }
void Egg::SetXVelocity(const float& xVel) { xVelocity = xVel; }
void Egg::SetYVelocity(const float& yVel) { yVelocity = yVel; }

void Egg::Draw() {
    DrawCircle(position.x, position.y, radius, GREEN);
}
