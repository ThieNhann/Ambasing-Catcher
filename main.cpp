#include <iostream>
#include <raylib.h>
#include <cmath>
#include <string>
#include "DropObject.h"
#include "Player.h"
#include "Config.h"
#include "Utils.h"
using namespace std;

int main() {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Gravity Simulation");
    SetTargetFPS(60);

    string scoreText = "Score: ";
    Font font = LoadFont("resource/fonts/KnightWarrior.otf");

    DropObject ball;
    ball.SetX(BALL_INIT_X);
    ball.SetY(BALL_INIT_Y);
    ball.SetRadius(BALL_RADIUS);

    Player bar(BAR_INIT_X, BAR_INIT_Y, BAR_WIDTH, BAR_HEIGHT, BAR_SPEED);

    Rectangle playWindow = {50, 50, PLAY_WINDOW_WIDTH, PLAY_WINDOW_HEIGHT};

    int score = 0;

    while (!WindowShouldClose()) {
        bar.Update();
        ball.SetYVelocity(ball.GetYVelocity() + GRAVITY);
        ball.SetY(ball.GetY() + ball.GetYVelocity());

        if (ball.GetY() > PLAY_WINDOW_HEIGHT + 50 - ball.GetRadius() || CheckCollisionCircleRec(Vector2{ball.GetX(), ball.GetY()}, ball.GetRadius(), bar.GetRect())) {                   //Check ball y-axys screen collision
            ball.SetX(GetRandomValue(53 + ball.GetRadius(), PLAY_WINDOW_WIDTH - ball.GetRadius()));
            ball.SetY(BALL_INIT_Y);
            ball.SetYVelocity(0.0f);
            score++;
        }

        if (bar.GetX() >= 50 + PLAY_WINDOW_WIDTH - bar.GetWidth() - 3) {   //Check bar x-axys screen collision
            bar.SetX(50 + PLAY_WINDOW_WIDTH - bar.GetWidth() - 3);  
        }
        if (bar.GetX() <= 55) {
            bar.SetX(55);  
        }

        BeginDrawing();
            ClearBackground(BLACK);
            ball.Draw();
            bar.Draw();
            DrawRectangleLinesEx(playWindow, PLAY_WINDOW_OUTLINE_THICKNESS, WHITE);
            DrawText((scoreText + to_string(score)).c_str(), 600, 50, 30, WHITE);
        EndDrawing();
    }
    DrawRectangleLines(50, 50, 500, 500, WHITE);
    CloseWindow();
}
