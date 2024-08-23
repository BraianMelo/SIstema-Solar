#ifndef SISTEMA_SOLAR_H
#define SISTEMA_SOLAR_H

#include <GL/glut.h>
#include "../include/Planetas.h"

// Variáveis globais
extern float eyex;
extern float eyey;
extern float eyez;

// Declarações de funções
void desenhaSol();
void desenhaMercurio();
void desenhaVenus();
void desenhaTerra();
void desenhaLua();
void desenhaMarte();
void desenha();
void TimerFunction(int value);
void definirIluminacao();
void Inicializa();

#endif
