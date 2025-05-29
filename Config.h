#ifndef CONFIG_H
#define CONFIG

//Screen
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

//Playing window
const int PLAY_WINDOW_WIDTH = 500;
const int PLAY_WINDOW_HEIGHT = 500;
const int PLAY_WINDOW_OUTLINE_THICKNESS = 3;

//Ball drop
const float GRAVITY = 0.3f;
const int BALL_RADIUS = 15;
const int BALL_INIT_X = PLAY_WINDOW_WIDTH / 2;
const int BALL_INIT_Y = 55 + BALL_RADIUS;
//Bar
const int BAR_INIT_X = 50 + PLAY_WINDOW_WIDTH / 2;
const int BAR_INIT_Y = 30 + PLAY_WINDOW_HEIGHT;
const int BAR_WIDTH = 100;
const int BAR_HEIGHT = 10;
const int BAR_SPEED = 350;
#endif