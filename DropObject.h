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
    virtual float GetX() const = 0;
    virtual float GetY() const = 0;
    virtual float GetXVelocity() const = 0;
    virtual float GetYVelocity() const = 0;

    virtual void SetX(const float& _x) = 0;
    virtual void SetY(const float& _y) = 0;
    virtual void SetXVelocity(const float& xVel) = 0;
    virtual void SetYVelocity(const float& yVel) = 0;

    virtual void Draw() const = 0;
    virtual ~DropObject() {}
};

class CircleObject : public DropObject {
protected:
    float radius;

public:
    virtual float GetRadius() const = 0;
    virtual void SetRadius(const float& r) = 0;
};

class Egg : public CircleObject {
private:
    Texture2D texture;
    bool textureLoaded = false;
public:
    float GetRadius() const override;
    void SetRadius(const float& r) override;

    float GetX() const override;
    float GetY() const override;

    float GetXVelocity() const override;
    float GetYVelocity() const override;

    void SetX(const float& _x) override;
    void SetY(const float& _y) override;
    void SetXVelocity(const float& xVel) override;
    void SetYVelocity(const float& yVel) override;

    void Draw() const override;

    // Texture management
    void LoadTexture(const char* path);
    void UnloadTexture();

    // Destructor
    ~Egg();
};

class Rock : public CircleObject {
private:
    Texture2D texture;
    bool textureLoaded = false;
    float rotation = 0.0f; // góc xoay hiện tại
public:
    float GetRadius() const override;
    void SetRadius(const float& r) override;

    float GetX() const override;
    float GetY() const override;

    float GetXVelocity() const override;
    float GetYVelocity() const override;

    void SetX(const float& _x) override;
    void SetY(const float& _y) override;
    void SetXVelocity(const float& xVel) override;
    void SetYVelocity(const float& yVel) override;

    void Draw() const override;

    // Texture management
    void LoadTexture(const char* path);
    void UnloadTexture();

    // Destructor
    ~Rock();

    // Rotation
    void UpdateRotation(float dt);
    float GetRotation() const { return rotation; }
};

#endif