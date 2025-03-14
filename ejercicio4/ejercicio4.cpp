#include "ejercicio4.h"

bool coincidencia_texto(const char* str1, const char* str2) {
    if (*str1 == '\0' && *str2 == '\0') return true;
    else if (*str1 != *str2) return false;
    return coincidencia_texto(++str1, ++str2);
}

bool coincidencia_texto_str(const string& str1, const string& str2, int pos = 0)
{
    if (pos == static_cast<int>(str1.size()) && pos == static_cast<int>(str2.size())) return true;
    else if ((str1.size() != str2.size()) || str1[pos] == str2[pos]) return false;
    return  coincidencia_texto_str(str1, str2, ++pos);
}


void impresion_tiempos_resultados(){
    auto tiempo_inicial = chrono::high_resolution_clock::now();
    bool res1 = coincidencia_texto_str("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec");
    auto tiempo_final = chrono::high_resolution_clock::now();
    auto tiempo_ejecucion_str = chrono::duration_cast<chrono::nanoseconds>(tiempo_final - tiempo_inicial);

    tiempo_inicial = chrono::high_resolution_clock::now();
    res1 = coincidencia_texto("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec");
    tiempo_final = chrono::high_resolution_clock::now();
    auto tiempo_ejecucion_char_ptr = chrono::duration_cast<chrono::nanoseconds>(tiempo_final - tiempo_inicial);

    tiempo_inicial = chrono::high_resolution_clock::now();
    constexpr bool res2 = coincidencia_texto_compilacion("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec");
    tiempo_final = chrono::high_resolution_clock::now();
    auto tiempo_compilacion = chrono::duration_cast<chrono::nanoseconds>(tiempo_final - tiempo_inicial);


    cout<<"Tiempos de las funciones:"<<endl;
    cout << "Tiempo ejecucion con string: " << tiempo_ejecucion_str.count() << " nanosegundos" << endl;
    cout << "Tiempo ejecucion con puntero a char: " << tiempo_ejecucion_char_ptr.count() << " nanosegundos" << endl;
    cout << "Tiempo compilacion con puntero a char: " << tiempo_compilacion.count() << " nanosegundos" << endl;

    cout<<"Verificacion de funcionamiento:"<<endl;
    cout << "Resultado con char* en ejecucion: " << (res1 ? "Iguales" : "Diferentes") << endl;
    cout << "Resultado con char* en tiempo de compilacion: " << (res2 ? "Iguales" : "Diferentes") << endl;
}

int main() {
    impresion_tiempos_resultados();
    /*
    a) Elección del tipo de varible:
    Se seleciono char * debido que es una varible primitiva que usa memoria estática, por lo que al trabajar con este tipo de datos solo debo 
    acceder al espacio de memoria. Mientras que el string es un objeto que trabaja con memoria dinámica, por lo que cuando se crea un string
    el compilador debe realizar la gestion de asignacion y liberacion de memoria    
    
    c) diferencia entre los tiempos:
    Cuando usamos constexpr la compración se realiza en tiempos de compilación, por lo que cuando se ejecuta el programa
    esta comparativa ya está hecha, usandose solo los datos precomputados en la funcion de test. 
    */
    return 0;
}
