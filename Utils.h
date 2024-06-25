#ifndef UTILS_H
#define UTILS_H

#include <fstream>
#include <iostream>
#include <string>

extern int high_score;
extern bool game_over;

void loadHighScore();
void saveHighScore();
void gameOver();
void pauseGame();
void drawScore(int);
void drawMissing(int);
void drawBall(float, float);
void drawBasket(float);
void drawMoon();
void home();
void instructions();
void team();
void drawGameScene();
void updateGame();
void animateHome();
void updateBasket();
void handleMouseClick(int, int);
void handleKeyboardDown(unsigned char);
void handleKeyboardUp(unsigned char);

#endif // UTILS_H
