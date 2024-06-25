#include <GL/glut.h>
#include "Game.h"

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Catch the Ball");

    // Initialize game
    initializeGame();

    // Set up callbacks
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMouseFunc(mouseClick);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);

    // Set clear color and projection
    glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    // Start main loop
    glutMainLoop();
    return 0;
}
