#include "DropObject.h"

float Egg::GetRadius() const { return radius;}
float Egg::GetX() const { return position.x; }
float Egg::GetY() const { return position.y; }
float Egg::GetXVelocity() const { return xVelocity; }
float Egg::GetYVelocity() const { return yVelocity; }

void Egg::SetRadius(const float& r) { radius = r; }
void Egg::SetX(const float& _x) { position.x = _x; }
void Egg::SetY(const float& _y) { position.y = _y; }
void Egg::SetXVelocity(const float& xVel) { xVelocity = xVel; }
void Egg::SetYVelocity(const float& yVel) { yVelocity = yVel; }

void Egg::LoadTexture(const char* path) {
    if (!textureLoaded) {
        texture = ::LoadTexture(path);
        textureLoaded = true;
    }
}

void Egg::UnloadTexture() {
    if (textureLoaded) {
        ::UnloadTexture(texture);
        textureLoaded = false;
    }
}

Egg::~Egg() {
    UnloadTexture();
}

void Egg::Draw() const {
    if (textureLoaded) {
        float scale = (radius * 2) / (float)texture.width;
        DrawTextureEx(texture, 
            {(float)(position.x - radius), (float)(position.y - radius)}, 
            0.0f, 
            scale, 
            WHITE);
    } else {
        DrawCircle(position.x, position.y, radius, GREEN);
    }
}

float Rock::GetRadius() const { return radius;}
float Rock::GetX() const { return position.x; }
float Rock::GetY() const { return position.y; }
float Rock::GetXVelocity() const { return xVelocity; }
float Rock::GetYVelocity() const { return yVelocity; }

void Rock::SetRadius(const float& r) { radius = r; }
void Rock::SetX(const float& _x) { position.x = _x; }
void Rock::SetY(const float& _y) { position.y = _y; }
void Rock::SetXVelocity(const float& xVel) { xVelocity = xVel; }
void Rock::SetYVelocity(const float& yVel) { yVelocity = yVel; }

void Rock::LoadTexture(const char* path) {
    if (!textureLoaded) {
        texture = ::LoadTexture(path);
        textureLoaded = true;
    }
}

void Rock::UnloadTexture() {
    if (textureLoaded) {
        ::UnloadTexture(texture);
        textureLoaded = false;
    }
}

Rock::~Rock() {
    UnloadTexture();
}

void Rock::UpdateRotation(float dt) {
    // Xoay với tốc độ 120 độ/giây
    rotation += 120.0f * dt;
    if (rotation > 360.0f) rotation -= 360.0f;
}

void Rock::Draw() const {
    if (textureLoaded) {
        float scale = (radius * 2) / (float)texture.width;
        // Vẽ texture xoay quanh tâm
        DrawTexturePro(
            texture,
            Rectangle{0, 0, (float)texture.width, (float)texture.height},
            Rectangle{position.x - radius, position.y - radius, radius * 2, radius * 2},
            Vector2{radius, radius},
            rotation,
            WHITE
        );
    } else {
        DrawCircle(position.x, position.y, radius, GRAY);
    }
}

