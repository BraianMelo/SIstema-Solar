#include "../include/Planetas.h"

// Definição das variáveis globais
float anguloVenus = 0;
float anguloMercurio = 0;
float anguloTerra = 0;
float anguloLua = 0;
float anguloMarte = 0;

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