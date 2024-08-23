#include "../include/Sistema_Solar.h"

// Variáveis globais
float eyex = 0;
float eyey = 60;
float eyez = 120;
float zoomSpeed = 10.0f; // Velocidade do zoom
float anguloRotacao = 0.0f; // Ângulo de rotação ao redor do eixo Y
float rotacaoSpeed = 0.1f; // Velocidade da rotação

void mouseFunc(int button, int state, int x, int y) {
    static int lastY = 0; // Última posição Y do mouse para detectar rotação

    if (state == GLUT_DOWN) {
        if (button == 3) { // Scroll up
            eyez -= zoomSpeed; // Zoom in
        } else if (button == 4) { // Scroll down
            eyez += zoomSpeed; // Zoom out
        }
        glutPostRedisplay();
    }
    
    if (button == GLUT_MIDDLE_BUTTON) {
        int deltaY = y - lastY; // Calcula a diferença do movimento do mouse
        anguloRotacao += deltaY * rotacaoSpeed; // Atualiza o ângulo de rotação
        lastY = y; // Atualiza a posição Y do mouse
        glutPostRedisplay();
    }
}

void keyboardFunc(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) {
        anguloRotacao -= rotacaoSpeed; // Rotaciona para a esquerda
    } else if (key == GLUT_KEY_RIGHT) {
        anguloRotacao += rotacaoSpeed; // Rotaciona para a direita
    }
    glutPostRedisplay();
}


void desenha(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Aplica a rotação e zoom
    gluLookAt(eyex * cos(anguloRotacao) - eyez * sin(anguloRotacao), eyey, eyex * sin(anguloRotacao) + eyez * cos(anguloRotacao), 
              0, 0, 0, 0, 1, 0);

    // Desenha o sistema planetário
    glPushMatrix();
        desenhaSol();

        glPushMatrix();
            glRotatef(anguloNetuno, 0, 1, 0);
            glTranslatef(130, 0, 0);
            desenhaNetuno();
        glPopMatrix();

        glPushMatrix();
            glRotatef(anguloUrano, 0, 1, 0);
            glTranslatef(115, 0, 0);
            desenhaUrano();
        glPopMatrix();

        glPushMatrix();
            glRotatef(anguloSaturno, 0, 1, 0);
            glTranslated(100, 0, 0);
            desenhaSaturno();
        glPopMatrix();

        glPushMatrix();
            glRotatef(anguloJupiter, 0, 1, 0);
            glTranslated(85, 0, 0);
            desenhaJupiter();
        glPopMatrix();

        glPushMatrix();
            glRotatef(anguloMarte, 0, 1, 0);
            glTranslatef(65, 0, 0);
            desenhaMarte();
        glPopMatrix();

        glPushMatrix();
            glRotatef(anguloTerra, 0, 1, 0);
            glTranslatef(50, 0, 0);
            desenhaTerra();

            glPushMatrix();
                glRotatef(anguloLua, 0, 1, 0);
                glTranslatef(7, 0, 0);
                desenhaLua();
            glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            glRotatef(anguloVenus, 0, 1, 0);
            glTranslatef(35, 0, 0);
            desenhaVenus();
        glPopMatrix();

        glPushMatrix();
            glRotatef(anguloMercurio, 0, 1, 0);
            glTranslatef(20, 0, 0);
            desenhaMercurio();
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void TimerFunction(int value) {
    anguloTerra += 360.0 / 365;    // Ajuste para refletir uma órbita completa em 365 "segundos"
    if (anguloTerra >= 360) anguloTerra = 0;

    anguloLua += (360.0 / 27.3);    // Ajuste para refletir uma órbita completa em 27,3 "segundos"
    if (anguloLua >= 360) anguloLua = 0;

    anguloMarte += 360.0 / 687;     // Ajuste para refletir uma órbita completa em 687 "segundos"
    if (anguloMarte >= 360) anguloMarte = 0;

    anguloMercurio += 360.0 / 88;   // Ajuste para refletir uma órbita completa em 88 "segundos"
    if (anguloMercurio >= 360) anguloMercurio = 0;

    anguloVenus += 360.0 / 225;     // Ajuste para refletir uma órbita completa em 225 "segundos"
    if (anguloVenus >= 360) anguloVenus = 0;

    anguloJupiter += 360.0 / 4333;  // Ajuste para refletir uma órbita completa em 4333 "segundos"
    if (anguloJupiter >= 360) anguloJupiter = 0;

    anguloSaturno += 360.0 / 10759; // Ajuste para refletir uma órbita completa em 10759 "segundos"
    if (anguloSaturno >= 360) anguloSaturno = 0;

    anguloUrano += 360.0 / 30660;   // Ajuste para refletir uma órbita completa em 30660 "segundos"
    if (anguloUrano >= 360) anguloUrano = 0;

    anguloNetuno += 360.0 / 60180;  // Ajuste para refletir uma órbita completa em 60180 "segundos"
    if (anguloNetuno >= 360) anguloNetuno = 0;

    glutPostRedisplay();
    glutTimerFunc(33, TimerFunction, 1); // Ajuste o intervalo conforme necessário
}

void definirIluminacao() {
    // Parâmetros da luz
    GLfloat luzAmbiente[] = {0.3f, 0.3f, 0.3f, 1.0f}; // Cor da luz ambiente
    GLfloat luzDifusa[] = {0.6f, 0.6f, 0.6f, 1.0f};   // Luz difusa que espalha em todas as direções
    GLfloat luzEspecular[] = {0.1f, 0.1f, 0.1f, 0.1f}; // Simula o brilho
    GLfloat posicaoLuz[] = {0.0f, 0.0f, 100.0f, 1.0f}; // Posição da luz

    glEnable(GL_LIGHTING); 
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    GLfloat especularidade[4] = {1.0, 1.0, 1.0, 1.0};
    GLint especMaterial = 60;

    glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
    glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
}

void Inicializa() {
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(100, 1, 1, 500);
    glEnable(GL_DEPTH_TEST);

    definirIluminacao();
    glutMouseFunc(mouseFunc); // Registra a função de callback do mouse
    glutSpecialFunc(keyboardFunc); // Registra a função de callback do teclado para teclas especiais
}

