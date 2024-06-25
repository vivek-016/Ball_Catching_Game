#include "Utils.h"
#include "Game.h"
#include <GL/glut.h>
#include <cmath>
#include <cstring>

void loadHighScore() {
    std::ifstream file("highScore.txt");
    if (file.is_open()) {
        std::string line;
        std::getline(file, line);
        if (!line.empty()) {
            high_score = std::stoi(line);
        }
        file.close();
    }
}

void saveHighScore() {
    std::ofstream file("highScore.txt");
    if (file.is_open()) {
        file << "High Score: " << high_score << std::endl;
        file.close();
    }
}

void gameOver() {
    glColor3f(1.0f, 0.0f, 0.0f);
    glRasterPos2f(-0.2f, 0.0f);
    const char* message = "Game Over!";
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
    glFlush();
}

void pauseGame() {
    glColor3f(1.0f, 1.0f, 0.0f);
    glRasterPos2f(-0.2f, 0.0f);
    const char* message = "GAME PAUSED!!!";
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
    glFlush();
}

void drawScore(int score) {
    glColor3f(0.0f, 1.0f, 0.0f);
    glRasterPos2f(-0.9f, 0.9f);
    char str[20];
    sprintf(str, "Score: %d", score);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
    }
}

void drawMissing(int miss) {
    glColor3f(0.0f, 1.0f, 0.0f);
    glRasterPos2f(0.7f, 0.9f);
    char str[20];
    sprintf(str, "Miss: %d", miss);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
    }
}

void drawBall(float x, float y) {
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 360; i++) {
        float radian = i * M_PI / 180.0f;
        glVertex2f(x + BALL_RADIUS * cos(radian), y + BALL_RADIUS * sin(radian));
    }
    glEnd();
}

void drawBasket(float x) {
    glColor3f(0.52f, 0.37f, 0.26f);
    glBegin(GL_QUADS);
    glVertex2f(x - BASKET_WIDTH / 2, -0.9f);
    glVertex2f(x - 0.1f + BASKET_WIDTH / 2, -0.9f);
    glVertex2f(x + BASKET_WIDTH / 2, -0.9f + BASKET_HEIGHT);
    glVertex2f(x - 0.1f - BASKET_WIDTH / 2, -0.9f + BASKET_HEIGHT);
    glEnd();
}

void drawMoon() {
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float degInRad = i * 3.14159 / 180;
        glVertex2f(cos(degInRad) * 0.18 - 0.8f, sin(degInRad) * 0.18 + 0.8f);
    }
    glEnd();
}

void home() {
    glColor3f(1.0f, 0.0f, 0.0f);
    glRasterPos2f(-0.5f, 0.7f);
    const char* message = "Catch the Ball Game";
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }

    glRasterPos2f(-0.5f, 0.5f);
    message = "Press 'S' to Start";
    len = strlen(message);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message[i]);
    }
}

void instructions() {
    glColor3f(1.0f, 0.0f, 0.0f);
    glRasterPos2f(-0.5f, 0.7f);
    const char* message = "Instructions";
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }

    glRasterPos2f(-0.9f, 0.5f);
    message = "Catch the red ball using the basket.";
    len = strlen(message);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message[i]);
    }

    glRasterPos2f(-0.7f, 0.3f);
    message = "Move the basket using arrow keys.";
    len = strlen(message);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message[i]);
    }

    glRasterPos2f(-0.5f, 0.1f);
    message = "Press 'H' to go back to Home.";
    len = strlen(message);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message[i]);
    }
}

void team() {
    glColor3f(1.0f, 0.0f, 0.0f);
    glRasterPos2f(-0.5f, 0.7f);
    const char* message = "Our Team";
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }

    glRasterPos2f(-0.7f, 0.5f);
    message = "Developed by: Your Team Name";
    len = strlen(message);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message[i]);
    }

    glRasterPos2f(-0.5f, 0.3f);
    message = "Press 'H' to go back to Home.";
    len = strlen(message);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message[i]);
    }
}

void drawGameScene() {
    drawBall(ball_x, ball_y);
    drawBasket(basket_x);
    drawScore(score);
    drawMissing(miss);
}

void updateGame() {
    if (!pause) {
        ball_y -= ball_speed;
        if (ball_y < -0.9f) {
            ball_x = (float(rand()) / float(RAND_MAX)) * 2 - 1;
            ball_y = 1.0f;
            miss++;
        }
        if (miss == 5) {
            game_over = true;
            gameOver();
        }
        if (game_over) {
            if (score > high_score) {
                high_score = score;
                saveHighScore();
            }
        }
    }
}

void animateHome() {
    bx += dx;
    if (bx < -1.0 || bx > 1.0)
        dx = -dx;
    drawMoon();
    home();
}

void updateBasket() {
    if (leftKeyPressed && basket_x > -0.8f)
        basket_x -= BASKET_SPEED;
    if (rightKeyPressed && basket_x < 0.8f)
        basket_x += BASKET_SPEED;
}

void handleMouseClick(int x, int y) {
    if (page == 0) {
        if (x >= 250 && x <= 390 && y >= 340 && y <= 380)
            page = 1;
        else if (x >= 250 && x <= 390 && y >= 280 && y <= 320)
            page = 2;
        else if (x >= 250 && x <= 390 && y >= 220 && y <= 260)
            page = 3;
    } else if (page == 1 || page == 2) {
        if (x >= 10 && x <= 150 && y >= 10 && y <= 50)
            page = 0;
    } else if (game_over) {
        if (x >= 250 && x <= 390 && y >= 280 && y <= 320) {
            game_over = false;
            page = 3;
            ball_x = (float(rand()) / float(RAND_MAX)) * 2 - 1;
            ball_y = 1.0f;
            score = 0;
            miss = 0;
        } else if (x >= 250 && x <= 390 && y >= 220 && y <= 260)
            page = 0;
    }
}

void handleKeyboardDown(unsigned char key) {
    if (key == 's' || key == 'S') {
        page = 0;
    } else if (key == 'h' || key == 'H') {
        page = 1;
    } else if (key == 't' || key == 'T') {
        page = 2;
    } else if (key == 'r' || key == 'R') {
        game_over = false;
        page = 3;
        ball_x = (float(rand()) / float(RAND_MAX)) * 2 - 1;
        ball_y = 1.0f;
        score = 0;
        miss = 0;
    } else if (key == 'p' || key == 'P') {
        pause = !pause;
        if (pause)
            pauseGame();
    }
}

void handleKeyboardUp(unsigned char key) {
    // Handle key release events if needed
}
