#ifndef GAME_H
#define GAME_H

#include <GL/glut.h>

extern float BALL_RADIUS;
extern float BASKET_HEIGHT;
extern float BASKET_WIDTH;
extern float BASKET_SPEED;
extern float WINDOW_WIDTH;
extern float WINDOW_HEIGHT;

extern float ball_speed;
extern int page;
extern float bx;
extern int high_score;
extern float dx;
extern float ball_x;
extern float ball_y;
extern float basket_x;
extern int score;
extern int miss;
extern bool game_over;
extern bool leftKeyPressed;
extern bool rightKeyPressed;
extern bool pause;

void initializeGame();
void display();
void timer(int);
void mouseClick(int, int, int, int);
void reshape(int, int);
void keyboardDown(unsigned char, int, int);
void keyboardUp(unsigned char, int, int);

#endif // GAME_H
