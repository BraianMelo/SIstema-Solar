#include <GL/glut.h>
#include "../include/Sistema_Solar.h"

int main(int argc, char **argv) {
	
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Sistema Solar");

    Inicializa();

    glutDisplayFunc(desenha);
    glutTimerFunc(33, TimerFunction, 1);

    glutMainLoop();
    
    return 0;
}
