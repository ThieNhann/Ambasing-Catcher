#include <iostream>
#include <raylib.h>
#include <cmath>
#include <string>
#include "DropObject.h"
#include "ObjectFactory.h"
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

    Egg* egg = (Egg*)ObjectFactory::Create(EGG);

    Rock* rock = nullptr;

    Player bar(BAR_INIT_X, BAR_INIT_Y, BAR_WIDTH, BAR_HEIGHT, BAR_SPEED);

    Rectangle playWindow = {50, 50, PLAY_WINDOW_WIDTH, PLAY_WINDOW_HEIGHT};

    int score = 0;
    
    //--- Main Game Loop ---
    while (!WindowShouldClose()) {

        //--- Update Logic ---

        bar.Update();

        egg->SetYVelocity(egg->GetYVelocity() + EGG_GRAVITY_PULL);
        egg->SetY(egg->GetY() + egg->GetYVelocity());

        if (rock) {
            rock->SetYVelocity(rock->GetYVelocity() + ROCK_GRAVITY_PULL);
            rock->SetY(rock->GetY() + rock->GetYVelocity());

            // Xoay rock liên tục
            rock->UpdateRotation(GetFrameTime());

            if (rock->GetY() > PLAY_WINDOW_HEIGHT + 100 - rock->GetRadius()) {
                delete rock;
                rock = nullptr;
            }
            else if (CheckCollisionCircleRec(Vector2{rock->GetX(), rock->GetY()}, rock->GetRadius(), bar.GetRect())) {
                delete rock;
                rock = nullptr;
                if (score > 0) score--;
            }
        }

        // egg falls out of play window
        if (egg->GetY() > PLAY_WINDOW_HEIGHT + 50 - egg->GetRadius()) {
            delete egg;
            egg = (Egg*)ObjectFactory::Create(EGG);
            if ((float)GetRandomValue(1, 100) / 100.0f <= ROCK_DROP_RATE && rock == nullptr)  {
                rock = (Rock*)ObjectFactory::Create(ROCK);
            }
            if (score > 0) score--;
        }
        // egg collides with bar
        else if (CheckCollisionCircleRec(Vector2{egg->GetX(), egg->GetY()}, egg->GetRadius(), bar.GetRect())) {
            delete egg;
            egg = (Egg*)ObjectFactory::Create(EGG);
            if ((float)GetRandomValue(1, 100) / 100.0f <= ROCK_DROP_RATE && rock == nullptr)  {
                rock = (Rock*)ObjectFactory::Create(ROCK);
            }
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
            if (egg) egg->Draw();
            if (rock) rock->Draw();
            bar.Draw();
            DrawRectangleLinesEx(playWindow, PLAY_WINDOW_OUTLINE_THICKNESS, WHITE);
            DrawText((scoreText + to_string(score)).c_str(), 600, 50, 30, WHITE);
        EndDrawing();
    }
    
    //--- Cleanup ---
    delete egg; // Prevent memory leak
    delete rock;
    CloseWindow();
}
