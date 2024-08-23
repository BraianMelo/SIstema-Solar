#include "../include/Sistema_Solar.h"

// Variaveis globais
float eyex = 0;
float eyey = 60;
float eyez = 120;

void desenha(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);

    // Desenha o sistema planetário
    glPushMatrix();
        desenhaSol();

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
    anguloTerra += 3;
    if (anguloTerra >= 360) anguloTerra = 0;
    
    anguloLua += 6;
    if (anguloLua >= 360) anguloLua = 0;
    
    anguloMarte += 2;
    if (anguloMarte >= 360) anguloMarte = 0;

    anguloMercurio += 1;
    if (anguloMercurio >= 360) anguloMercurio = 0;

    anguloVenus += 1.25;
    if (anguloVenus >= 360) anguloVenus = 0;

    glutPostRedisplay();
    glutTimerFunc(33, TimerFunction, 1);
}

void definirIluminacao() {
    // Parâmetros da luz
    GLfloat luzAmbiente[] = {0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat luzDifusa[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat luzEspecular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat posicaoLuz[] = {0.0f, 0.0f, 100.0f, 1.0f};

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
    gluPerspective(50, 1, 1, 500);
    glEnable(GL_DEPTH_TEST);

    //definirIluminacao();
}