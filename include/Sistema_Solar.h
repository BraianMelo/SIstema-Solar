#ifndef SISTEMA_SOLAR_H
#define SISTEMA_SOLAR_H

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

#include "../include/Planetas.h"

// Variáveis locais
extern bool iluminacaoLigada;

// Variáveis globais
extern float eyex;
extern float eyey;
extern float eyez;

extern float velocidadeZoom; 
extern float anguloRotacao; 
extern float velocidadeRotacao;
extern float multVelocidade;

// Declarações de funções
void desenha();
void gerenciarTeclado(unsigned char key, int x, int y);
void gerenciarTecladoEspecial(int key, int x, int y);
void gerenciarMouse(int button, int state, int x, int y);
void TimerFunction(int value);
void definirIluminacao();
void Inicializa();

#endif
