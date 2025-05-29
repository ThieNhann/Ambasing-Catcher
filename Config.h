#ifndef CONFIG_H
#define CONFIG_H

//--------------------
// Screen configuration
//--------------------
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

//--------------------
// Playing window configuration
//--------------------
const int PLAY_WINDOW_WIDTH = 500;
const int PLAY_WINDOW_HEIGHT = 500;
const int PLAY_WINDOW_OUTLINE_THICKNESS = 3;

//--------------------
// Egg drop configuration
//--------------------
const float EGG_GRAVITY_PULL = 0.3f;
const int EGG_MIN_RADIUS = 15;
const int EGG_MAX_RADIUS = 20;
const int EGG_INIT_X = PLAY_WINDOW_WIDTH / 2;
const int EGG_INIT_Y = 55 + EGG_MIN_RADIUS;

//--------------------
// Rock drop configuration
//--------------------
const float ROCK_DROP_RATE = 0.2f;
const float ROCK_GRAVITY_PULL = 0.5f;
const int ROCK_MIN_RADIUS = 10;
const int ROCK_MAX_RADIUS = 18;
const int ROCK_INIT_X = GetRandomValue(60, PLAY_WINDOW_WIDTH + 50);
const int ROCK_INIT_Y = 55 + EGG_MIN_RADIUS;

//--------------------
// Bar configuration
//--------------------
const int BAR_INIT_X = 50 + PLAY_WINDOW_WIDTH / 2;
const int BAR_INIT_Y = 30 + PLAY_WINDOW_HEIGHT;
const int BAR_WIDTH = 70;
const int BAR_HEIGHT = 10;
const int BAR_SPEED = 350;

#endif