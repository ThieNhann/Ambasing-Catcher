#include "DropObject.h"

float DropObject::GetX() { return x; }
float DropObject::GetY() { return y; }
float DropObject::GetRadius() { return r; }
float DropObject::GetXVelocity() { return xVelocity; }
float DropObject::GetYVelocity() { return yVelocity; }
void DropObject::SetRadius(const float& radius) { r = radius; }
void DropObject::SetX(const float& _x) { x = _x; }
void DropObject::SetY(const float& _y) { y = _y; }
void DropObject::SetXVelocity(const float& xVel) { xVelocity = xVel; }
void DropObject::SetYVelocity(const float& yVel) { yVelocity = yVel; }
void DropObject::Draw() { DrawCircle(x, y, r, GREEN); }
