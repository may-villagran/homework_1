#ifndef EJERCICIO4_H
#define EJERCICIO4_H
#include <string>
#include <chrono>
#include <iostream>
using namespace std;

constexpr bool coincidencia_texto_compilacion(const char* str1, const char* str2) {
    if (*str1 == '\0' && *str2 == '\0') return true;
    else if (*str1 != *str2) return false;
    return coincidencia_texto_compilacion(++str1, ++str2);
}

bool coincidencia_texto(const char* str1, const char* str2);
bool coincidencia_texto_str(const string& str1, const string& str2, int pos);

#endif 