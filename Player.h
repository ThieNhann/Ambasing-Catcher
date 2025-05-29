#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

class Player {
private:
    Rectangle rect;
    float speed;
public:
    void SetX(const float& x);
    void SetY(const float& y);
    float GetX();
    float GetY();
    float GetWidth();
    float GetHeight();
    Rectangle GetRect();
    void Update();
    void Draw();
public:
    Player() : rect{0, 0, 50, 50}, speed(5) {}
    Player(const float& x, const float& y, const float& w, const float& h, const float& spd)
        : rect{x, y, w, h}, speed(spd) {}
};

#endif
