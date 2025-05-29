#include <iostream>
#include <raylib.h>
#include <cmath>
#include "DropObject.h"
#include "Player.h"
#include "Config.h"
#include "Utils.h"
using namespace std;

int main() {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Gravity Simulation");
    SetTargetFPS(60);

    DropObject ball;
    ball.SetX((float)BALL_INIT_X);
    ball.SetY((float)BALL_INIT_Y);
    ball.SetRadius(BALL_RADIUS);

    Player bar(BAR_INIT_X, BAR_INIT_Y, BAR_WIDTH, BAR_HEIGHT, BAR_SPEED);

    while (!WindowShouldClose()) {
        bar.Update();
        ball.SetYVelocity(ball.GetYVelocity() + GRAVITY);
        ball.SetY(ball.GetY() + ball.GetYVelocity());

        if (ball.GetY() > SCREEN_HEIGHT || CheckCollisionCircleRec(Vector2{ball.GetX(), ball.GetY()}, ball.GetRadius(), bar.GetRect())) {                   //Check ball y-axys screen collision
            ball.SetX(GetRandomValue(50, 750));
            ball.SetY(0.0f);
            ball.SetYVelocity(0.0f);
        }

        if (bar.GetX() >= SCREEN_WIDTH - bar.GetWidth() - 5) {   //Check bar x-axys screen collision
            bar.SetX(SCREEN_WIDTH - bar.GetWidth() - 5);  
        }
        if (bar.GetX() <= 5) {
            bar.SetX(5);  
        }

        BeginDrawing();
            ClearBackground(BLACK);
            ball.Draw();
            bar.Draw();
        EndDrawing();
    }

    CloseWindow();
}
