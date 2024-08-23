#include "../include/Planetas.h"

// Definição das variáveis globais
float anguloVenus = 0;
float anguloMercurio = 0;
float anguloTerra = 0;
float anguloLua = 0;
float anguloMarte = 0;
float anguloJupiter = 0;
float anguloSaturno = 0;
float anguloUrano = 0;
float anguloNetuno = 0;

// Implementação das funções de desenho dos planetas
void desenhaSol() {
    glColor3f(1, 1, 0);
    glutSolidSphere(12, 32, 32);
}

void desenhaMercurio() {
    glColor3f(0.5, 0.5, 0.5);
    glutSolidSphere(2, 16, 16);
}

void desenhaVenus() {
    glColor3f(1.0f, 0.647f, 0.2f);
    glutSolidSphere(4, 16, 16);
}

void desenhaTerra() {
    glColor3f(0, 0, 1);
    glutSolidSphere(5, 16, 16);
}

void desenhaLua() {
    glColor3f(0.5, 0.5, 0.5);
    glutSolidSphere(1, 16, 16);
}

void desenhaMarte() {
    glColor3f(1, 0.2, 0);
    glutSolidSphere(4, 16, 16);
}

void desenhaJupiter() {
    glColor3f(1.0, 0.8, 0.6);
    glutSolidSphere(7, 16, 16);
}

void desenhaSaturno() {
    glColor3f(0.9, 0.8, 0.5); 
    glutSolidSphere(6, 16, 16);

    // Desenha o anel
    GLfloat raioAnelInterno = 7.0;
    GLfloat raioAnelExterno = 8.0;
    GLint numSlices = 100;      
    GLint numLoops = 1;           

    glPushMatrix();
    glRotatef(90, 1, 0, 0);

    glColor3f(0.6, 0.6, 0.6); 
    GLUquadricObj *quadrico = gluNewQuadric();

    gluQuadricDrawStyle(quadrico, GLU_FILL);
    gluDisk(quadrico, raioAnelInterno, raioAnelExterno, numSlices, numLoops);

    gluDeleteQuadric(quadrico);

    glPopMatrix();
}

void desenhaUrano() {
    glColor3f(0.5, 0.8, 1.0);
    glutSolidSphere(4.5, 16, 16);

    GLfloat raioAnelInterno = 5.5; 
    GLfloat raioAnelExterno = 6.5; 
    GLint numSlices = 100;    
    GLint numLoops = 1;         

    glPushMatrix();
    glRotatef(125, 1, 0, 0); // Inclina o anel para que fique horizontal

    glColor3f(0.7, 0.7, 0.7); // Cor cinza claro para o anel
    GLUquadricObj *quadrico = gluNewQuadric();

    gluQuadricDrawStyle(quadrico, GLU_FILL);
    gluDisk(quadrico, raioAnelInterno, raioAnelExterno, numSlices, numLoops);

    gluDeleteQuadric(quadrico);

    glPopMatrix();
}

void desenhaNetuno() {
    glColor3f(0.0, 0.0, 1.0); 
    glutSolidSphere(4.5, 16, 16);

}
