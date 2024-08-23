#ifndef PLANETAS_H
#define PLANETAS_H

#include <GL/glut.h>

// Variáveis globais para ângulos de rotação
extern float anguloVenus;
extern float anguloMercurio;
extern float anguloTerra;
extern float anguloLua;
extern float anguloMarte;
extern float anguloJupiter;
extern float anguloSaturno;
extern float anguloUrano;
extern float anguloNetuno;

// Funcoes
void desenhaSol();
void desenhaMercurio();
void desenhaVenus();
void desenhaTerra();
void desenhaLua();
void desenhaMarte();
void desenhaJupiter();
void desenhaSaturno();
void desenhaUrano();
void desenhaNetuno();

#endif // PLANETAS_H
