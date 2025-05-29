#include "Player.h"

float Player::GetX() {
    return rect.x;
}

float Player::GetY() {
    return rect.y;
}

float Player::GetWidth() {
    return rect.width;
}

float Player::GetHeight() {
    return rect.height;
}

Rectangle Player::GetRect() {
    return rect;
}

void Player::SetX(const float& xCord) {
    rect.x = xCord;
}

void Player::SetY(const float& yCord) {
    rect.y = yCord;
}

void Player::Update() {
    float t =  GetFrameTime();
    if (IsKeyDown(KEY_D)) rect.x += speed * t;
    if (IsKeyDown(KEY_A)) rect.x -= speed * t;
}

void Player::Draw() {
    DrawRectangleRec(rect, GREEN);
}