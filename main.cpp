#include <iostream>
#include <raylib.h>
#include <cmath>
#include <string>
#include "DropObject.h"
#include "Player.h"
#include "Config.h"
#include "Utils.h"
using namespace std;

//---------------------------------------------
// Main entry point
//---------------------------------------------
int main() {
    //--- Window and Game Setup ---
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Gravity Simulation");
    SetTargetFPS(60);

    string scoreText = "Score: ";

    //--- Game Objects ---
    Egg ball;
    ball.SetX(BALL_INIT_X);
    ball.SetY(BALL_INIT_Y);
    ball.SetRadius(BALL_RADIUS);

    Player bar(BAR_INIT_X, BAR_INIT_Y, BAR_WIDTH, BAR_HEIGHT, BAR_SPEED);

    Rectangle playWindow = {50, 50, PLAY_WINDOW_WIDTH, PLAY_WINDOW_HEIGHT};

    int score = 0;
    
    //--- Main Game Loop ---
    while (!WindowShouldClose()) {
        //--- Update Logic ---
        bar.Update();
        ball.SetYVelocity(ball.GetYVelocity() + GRAVITY);
        ball.SetY(ball.GetY() + ball.GetYVelocity());

        // Ball falls out of play window
        if (ball.GetY() > PLAY_WINDOW_HEIGHT + 50 - ball.GetRadius()) {
            ball.SetX(GetRandomValue(53 + ball.GetRadius(), PLAY_WINDOW_WIDTH - ball.GetRadius()));
            ball.SetY(BALL_INIT_Y);
            ball.SetYVelocity(0.0f);
            if (score > 0) score--;
        }
        // Ball collides with bar
        else if (CheckCollisionCircleRec(Vector2{ball.GetX(), ball.GetY()}, ball.GetRadius(), bar.GetRect())) {
            ball.SetX(GetRandomValue(53 + ball.GetRadius(), PLAY_WINDOW_WIDTH - ball.GetRadius()));
            ball.SetY(BALL_INIT_Y);
            ball.SetYVelocity(0.0f);
            score++;
        }

        // Bar collision with play window boundaries
        if (bar.GetX() >= 50 + PLAY_WINDOW_WIDTH - bar.GetWidth() - 3) {
            bar.SetX(50 + PLAY_WINDOW_WIDTH - bar.GetWidth() - 3);  
        }
        if (bar.GetX() <= 55) {
            bar.SetX(55);  
        }

        //--- Draw Everything ---
        BeginDrawing();
            ClearBackground(BLACK);
            ball.Draw();
            bar.Draw();
            DrawRectangleLinesEx(playWindow, PLAY_WINDOW_OUTLINE_THICKNESS, WHITE);
            DrawText((scoreText + to_string(score)).c_str(), 600, 50, 30, WHITE);
        EndDrawing();
    }
    
    //--- Cleanup ---
    CloseWindow();
}
