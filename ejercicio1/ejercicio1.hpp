#ifndef EJERCICIO1_HPP
#define EJERCICIO1_HPP
#include <iostream>
using namespace std;

/**
 * @brief Asigna memoria dinámica para una matriz cuadrada de tamaño n x n.
 * @param n Tamaño de la matriz (número de filas y columnas).
 * @return Puntero doble a la matriz de enteros asignada dinámicamente.
 */
int **asignacion_memoria(int n);

/**
 * @brief Inicializa los valores de la matriz de tamaño n x n.
 * @param matriz Puntero doble a la matriz a inicializar.
 * @param n Tamaño de la matriz (número de filas y columnas).
 */
void matriz_valores(int** matriz, int n);

/**
 * @brief Crea y retorna una matriz cuadrada de tamaño n x n con memoria asignada e inicializada con números desde 1 a n.
 * @param n Tamaño de la matriz (número de filas y columnas).
 * @return Puntero doble a la matriz creada e inicializada.
 */
int **crear_matriz(int n);

/**
 * @brief Imprime los elementos de la matriz de tamaño n x n en formato de tabla.
 * @param matriz Puntero doble a la matriz a imprimir.
 * @param n Tamaño de la matriz (número de filas y columnas).
 */
void imprimir_matriz(int **matriz, int n);

/**
 * @brief Libera la memoria asignada dinámicamente para la matriz.
 * @param matriz Puntero doble a la matriz cuya memoria se desea liberar.
 * @param n Tamaño de la matriz (número de filas y columnas).
 */
void destruir_matriz(int **matriz, int n);

#endif
