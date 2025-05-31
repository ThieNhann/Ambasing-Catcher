#include "Player.h"

//--------------------
// Getters
//--------------------
float Player::GetX() { return rect.x; }
float Player::GetY() { return rect.y; }
float Player::GetWidth() { return rect.width; }
float Player::GetHeight() { return rect.height; }
Rectangle Player::GetRect() { return rect; }

//--------------------
// Setters
//--------------------
void Player::SetX(const float& xCord) { rect.x = xCord; }
void Player::SetY(const float& yCord) { rect.y = yCord; }

//--------------------
// Update player position based on keyboard input
//--------------------
void Player::Update() {
    float t = GetFrameTime();
    if (IsKeyDown(KEY_D)) rect.x += speed * t;
    if (IsKeyDown(KEY_A)) rect.x -= speed * t;
}

//--------------------
// Draw player bar
//--------------------
void Player::Draw() {
    DrawRectangleRec(rect, WHITE);
}