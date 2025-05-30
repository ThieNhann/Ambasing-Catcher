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
    InitAudioDevice();

    SetTargetFPS(60);

    string scoreText = "Score: ";

    Egg* egg = (Egg*)ObjectFactory::Create(EGG);

    Rock* rock = nullptr;

    Player bar(BAR_INIT_X, BAR_INIT_Y, BAR_WIDTH, BAR_HEIGHT, BAR_SPEED);

    Rectangle playWindow = {50, 50, PLAY_WINDOW_WIDTH, PLAY_WINDOW_HEIGHT};

    Vector2 bottomLineLeftPoint = {50, 50 + PLAY_WINDOW_HEIGHT};

    Vector2 bottomLineRightPoint = {50 + PLAY_WINDOW_WIDTH, 50 + PLAY_WINDOW_HEIGHT};

    Sound eggCol = LoadSound("resource/sounds/coin.wav");
    Sound rockCol = LoadSound("resource/sounds/hurt.wav");
    Music bgMusic = LoadMusicStream("resource/sounds/time_for_adventure.mp3");
    PlayMusicStream(bgMusic);

    int score = 0;

    //--- Main Game Loop ---
    while (!WindowShouldClose()) {
        
        UpdateMusicStream(bgMusic);
        //--- Update Logic ---

        bar.Update();

        egg->SetYVelocity(egg->GetYVelocity() + EGG_GRAVITY_PULL);
        egg->SetY(egg->GetY() + egg->GetYVelocity());

        if (rock) {
            rock->SetYVelocity(rock->GetYVelocity() + ROCK_GRAVITY_PULL);
            rock->SetY(rock->GetY() + rock->GetYVelocity());

            // Check collision with bar first
            if (CheckCollisionCircleRec(Vector2{rock->GetX(), rock->GetY()}, rock->GetRadius(), bar.GetRect())) {
                PlaySound(rockCol);
                delete rock;
                rock = nullptr;
                if (score > 0) score--;
            }
            // Then check if rock hits the bottom line or falls out of play window
            else if (
                CheckCollisionCircleLine(Vector2{rock->GetX(), rock->GetY()}, rock->GetRadius(), bottomLineLeftPoint, bottomLineRightPoint)
                || rock->GetY() + rock->GetRadius() > 50 + PLAY_WINDOW_HEIGHT
            ) {
                delete rock;
                rock = nullptr;
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
            PlaySound(eggCol);
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
            DrawRectangleLinesEx(playWindow, PLAY_WINDOW_OUTLINE_THICKNESS, WHITE);
            DrawText((scoreText + to_string(score)).c_str(), 600, 50, 30, WHITE);
            if (egg) egg->Draw();
            if (rock) rock->Draw();
            bar.Draw();
        EndDrawing();
    }

    //--- Cleanup ---
    UnloadMusicStream(bgMusic);
    UnloadSound(eggCol);
    UnloadSound(rockCol);
    delete egg; // Prevent memory leak
    delete rock;
    CloseWindow();
}
