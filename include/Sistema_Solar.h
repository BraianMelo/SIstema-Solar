#ifndef SISTEMA_SOLAR_H
#define SISTEMA_SOLAR_H

#include <GL/glut.h>
#include <math.h>
#include "../include/Planetas.h"

// Variáveis globais
extern float eyex;
extern float eyey;
extern float eyez;

extern float zoomSpeed; 
extern float anguloRotacao; 
extern float rotacaoSpeed;

// Declarações de funções
void desenha();
void keyboardFunc(int key, int x, int y);
void mouseFunc(int button, int state, int x, int y);
void TimerFunction(int value);
void definirIluminacao();
void Inicializa();

#endif
