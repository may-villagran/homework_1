#include "ejercicio4.h"

bool coincidencia_texto(const char* str1, const char* str2) {
    if (*str1 == '\0' && *str2 == '\0') return true;
    else if (*str1 != *str2) return false;
    return coincidencia_texto(++str1, ++str2);
}

int main() {
    auto tiempo_inicial = std::chrono::high_resolution_clock::now();
    bool res = coincidencia_texto("abcdefghi", "abcdefghj");
    auto tiempo_final = std::chrono::high_resolution_clock::now();
    auto tiempo_ejecucion = std::chrono::duration_cast<std::chrono::nanoseconds>(tiempo_final - tiempo_inicial);

    tiempo_inicial = std::chrono::high_resolution_clock::now();
    constexpr bool res2 = coincidencia_texto_compilacion("abcdefghi", "abcdefghj");
    tiempo_final = std::chrono::high_resolution_clock::now();
    auto tiempo_compilacion = std::chrono::duration_cast<std::chrono::nanoseconds>(tiempo_final - tiempo_inicial);

    std::cout << "Tiempo ejecucion: " << tiempo_ejecucion.count() << " nanosegundos" << std::endl;
    std::cout << "Tiempo compilacion: " << tiempo_compilacion.count() << " nanosegundos" << std::endl;
}
