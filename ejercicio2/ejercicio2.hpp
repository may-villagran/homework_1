#ifndef EJERCICIO2_HPP
#define EJERCICIO2_HPP

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

/**
 * @brief Enumeración que representa los niveles de importancia para mensajes de log.
 */
enum ETIQUETAS {
    DEBUG,      
    INFO,      
    WARNING,   
    ERROR,     
    CRITICAL    
};

/**
 * @brief Convierte el nivel de importancia de tipo ETIQUETAS a una cadena de texto.
 * @param nivel_importancia Nivel de importancia a convertir.
 * @return Cadena de texto con la representación del nivel de importancia.
 */
string casteo_string(ETIQUETAS nivel_importancia);

/**
 * @brief Escribe un mensaje en un archivo de registro con la etiqueta especificada.
 * @param etiqueta string de la etiqueta que indica el nivel de importancia del mensaje.
 * @param mensaje string con el mensaje a registrar en el archivo.
 */
void salida_archivo(string etiqueta, string mensaje);

/**
 * @brief Registra un mensaje en el log con el nivel de importancia especificado.
 * @param mensaje string con el mensaje a registrar.
 * @param nivel_importancia Nivel de importancia del mensaje (DEBUG, INFO, WARNING, ERROR, CRITICAL).
 */
void logMessage(string mensaje, ETIQUETAS nivel_importancia);

/**
 * @brief Registra un mensaje de error junto con el nombre del archivo y la línea de código donde ocurrió.
 * @param mensaje_error string con la descripción del error.
 * @param archivo string con el nombre del archivo donde ocurrió el error.
 * @param linea_codigo Número entero de línea donde se detectó el error.
 */
void logMessage(string mensaje_error, string archivo, int linea_codigo);

/**
 * @brief Registra un mensaje de acceso con el nombre del usuario correspondiente.
 * @param mensaje_acceso string con el mensaje de registro del acceso.
 * @param nombre_usuario string con el nombre del usuario asociado al acceso.
 */
void logMessage(string mensaje_acceso, string nombre_usuario);

/**
 * @brief Realiza pruebas básicas de las funciones de registro de mensajes (`logMessage`).
 */
void test_logMessage();

/**
 * @brief Realiza una prueba para capturar y manejar errores en tiempo de ejecución (`runtime_error`).
 * @return `true` si se captura correctamente el error, `false` en caso contrario.
 */
bool test_captura_runtime_error();

#endif
