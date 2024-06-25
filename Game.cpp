#include "Game.h"
#include "Utils.h"
#include <cmath>
#include <ctime>
#include <cstring>

// Constants
float BALL_RADIUS = 0.08f;
float BASKET_HEIGHT = 0.1f;
float BASKET_WIDTH = 0.3f;
float BASKET_SPEED = 0.02f;
float WINDOW_WIDTH = 640;
float WINDOW_HEIGHT = 480;

// Global variables
float ball_speed = 0.02f;
int page = 0;
float bx = 0.0;
int high_score = 0;
float dx = 0.01;
float ball_x = 0.0f;
float ball_y = 1.0f;
float basket_x = 0.0f;
int score = 0;
int miss = 0;
bool game_over = false;
bool leftKeyPressed = false;
bool rightKeyPressed = false;
bool pause = true;

void initializeGame() {
    // Load high score from file
    loadHighScore();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    switch (page) {
        case 0:
            home();
            break;
        case 1:
            instructions();
            break;
        case 2:
            team();
            break;
        case 3:
            drawGameScene();
            break;
        default:
            break;
    }

    glutSwapBuffers();
}

void timer(int) {
    if (page == 3) {
        updateGame();
        updateBasket();
    }
    else if (page == 0) {
        animateHome();
    }

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        handleMouseClick(x, y);
    }
}

void reshape(int w, int h) {
    WINDOW_WIDTH = w;
    WINDOW_HEIGHT = h;

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboardDown(unsigned char key, int x, int y) {
    handleKeyboardDown(key);
}

void keyboardUp(unsigned char key, int x, int y) {
    handleKeyboardUp(key);
}
