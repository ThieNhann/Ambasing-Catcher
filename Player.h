#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

//---------------------------------------------
// Player class: represents the controllable bar
//---------------------------------------------
class Player {
private:
    Rectangle rect; // Player's rectangle (position and size)
    float speed;    // Movement speed
public:
    // Setters
    void SetX(const float& x);
    void SetY(const float& y);

    // Getters
    float GetX();
    float GetY();
    float GetWidth();
    float GetHeight();
    Rectangle GetRect();

    // Update player position based on input
    void Update();

    // Draw player on screen
    void Draw();

    // Constructors
    Player() : rect{0, 0, 50, 50}, speed(5) {}
    Player(const float& x, const float& y, const float& w, const float& h, const float& spd)
        : rect{x, y, w, h}, speed(spd) {}
};

#endif
