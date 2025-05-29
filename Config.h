#ifndef CONFIG_H
#define CONFIG

//Screen, window
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

//Ball drop
const float GRAVITY = 0.3f;
const int BALL_INIT_X = SCREEN_WIDTH / 2;
const int BALL_INIT_Y = 0;
const int BALL_RADIUS = 15;
//Bar
const int BAR_INIT_X = SCREEN_WIDTH / 2;
const int BAR_INIT_Y = SCREEN_HEIGHT - 50;
const int BAR_WIDTH = 150;
const int BAR_HEIGHT = 20;
const int BAR_SPEED = 500;
#endif