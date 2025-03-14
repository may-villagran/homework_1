#ifndef EJERCICIO1_H
#define EJERCICIO1_H

#include <iostream>
using namespace std;

int **asignacion_memoria(int n);
void matriz_valores(int** matriz, int n);
int **crear_matriz(int n);
void imprimir_matriz(int **matriz, int n);
void destruir_matriz(int **matriz, int n);

#endif