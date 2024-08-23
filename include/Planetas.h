#ifndef PLANETAS_H
#define PLANETAS_H

#include <GL/glut.h>

// Variáveis globais para ângulos de rotação
extern float anguloVenus;
extern float anguloMercurio;
extern float anguloTerra;
extern float anguloLua;
extern float anguloMarte;

// Funções para desenhar os planetas
void desenhaSol();
void desenhaMercurio();
void desenhaVenus();
void desenhaTerra();
void desenhaLua();
void desenhaMarte();

#endif