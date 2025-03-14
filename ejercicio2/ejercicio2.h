#ifndef EJERCICIO2_H
#define EJERCICIO2_H

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

enum ETIQUETAS {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

string casteo_string(ETIQUETAS nivel_importancia);
void salida_archivo(string etiqueta, string mensaje);
void logMessage(string mensaje, ETIQUETAS nivel_importancia);
void logMessage(string mensaje_error, string archivo, int linea_codigo);
void logMessage(string mensaje_acceso, string nombre_usuario);
void test_logMessage();
bool test_captura_runtime_error();

#endif