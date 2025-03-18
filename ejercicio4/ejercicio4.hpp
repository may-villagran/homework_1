#ifndef EJERCICIO4_HPP
#define EJERCICIO4_HPP

#include <string>
#include <chrono>
#include <iostream>
using namespace std;

/**
 * @brief Compara dos cadenas de texto en tiempo de compilación.
 * 
 * Esta función es evaluada en tiempo de compilación cuando se usa `constexpr`.
 * Compara los caracteres de dos cadenas `const char*` carácter por carácter.
 * 
 * @param str1 La primera cadena a comparar.
 * @param str2 La segunda cadena a comparar.
 * @return `true` si las dos cadenas son iguales, `false` si son diferentes.
 */
constexpr bool coincidencia_texto_compilacion(const char* str1, const char* str2);


/**
 * @brief Compara dos cadenas de texto en tiempo de ejecución usando punteros a char.
 * 
 * Compara las cadenas carácter por carácter en tiempo de ejecución. Esta función
 * es adecuada para trabajar con cadenas que no sean constantes en tiempo de compilación.
 * 
 * @param str1 La primera cadena a comparar.
 * @param str2 La segunda cadena a comparar.
 * @return `true` si las dos cadenas son iguales, `false` si son diferentes.
 */
bool coincidencia_texto(const char* str1, const char* str2);


/**
 * @brief Compara dos cadenas de texto de tipo `std::string` en tiempo de ejecución.
 * 
 * Esta función compara las cadenas `std::string` carácter por carácter de forma recursiva.
 * 
 * @param str1 La primera cadena de tipo `std::string` a comparar.
 * @param str2 La segunda cadena de tipo `std::string` a comparar.
 * @param pos La posición actual para la comparación recursiva (por defecto es 0).
 * @return `true` si las dos cadenas son iguales, `false` si son diferentes.
 */
bool coincidencia_texto_str(const string& str1, const string& str2, int pos = 0);


/**
 * @brief Función que mide y muestra los tiempos de ejecución de las tres funciones de comparación.
 * 
 * Esta función calcula el tiempo de ejecución para las tres funciones: 
 * - Comparación con `std::string` 
 * - Comparación con punteros a `char*`
 * - Comparación en tiempo de compilación con `constexpr`.
 * 
 * Muestra los resultados de tiempo de ejecución en nanosegundos para cada caso y la verificación
 * de que los resultados de las comparaciones son correctos.
 */
void impresion_tiempos_resultados();

#endif // EJERCICIO4_H
