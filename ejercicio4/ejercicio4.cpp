#include "ejercicio4.hpp"

constexpr bool coincidencia_texto_compilacion(const char* str1, const char* str2) {
    if (*str1 == '\0' && *str2 == '\0') return true;
    else if (*str1 != *str2) return false;
    return coincidencia_texto_compilacion(++str1, ++str2);
}

bool coincidencia_texto(const char* str1, const char* str2) {
    if (*str1 == '\0' && *str2 == '\0') return true;
    else if (*str1 != *str2) return false;
    return coincidencia_texto(++str1, ++str2);
}

bool coincidencia_texto_str( const string &str1, const string &str2, int pos)
{
    //comparo que la pos ultima si es el tam-1
    if ( pos == static_cast<int>(str1.size()-1) && pos == static_cast<int>(str2.size()-1)) return true;
    //si los tam son distintos o el contenido es distinto es false
    else if ((str1.size() != str2.size()) || str1[pos] != str2[pos]) return false;
    return  coincidencia_texto_str(str1, str2, ++pos);
}


void impresion_tiempos_resultados(){
    const char* texto = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec";
    string texto_str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec";
    constexpr const char* texto_const = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec";

    //tiempo de ejecucion empleado con la funcion de  string
    auto tiempo_inicial = chrono::high_resolution_clock::now();
    bool res_str = coincidencia_texto_str(texto_str, texto_str);
    auto tiempo_final = chrono::high_resolution_clock::now();
    auto tiempo_ejecucion_str = chrono::duration_cast<chrono::nanoseconds>(tiempo_final - tiempo_inicial);

    //timepo de ejecucion empleado con la funcion de char*
    tiempo_inicial = chrono::high_resolution_clock::now();
    bool res_char = coincidencia_texto(texto, texto);
    tiempo_final = chrono::high_resolution_clock::now();
    auto tiempo_ejecucion_char_ptr = chrono::duration_cast<chrono::nanoseconds>(tiempo_final - tiempo_inicial);

    //tiempo de ejecucion empleado con 
    tiempo_inicial = chrono::high_resolution_clock::now();
    constexpr bool res_const = coincidencia_texto_compilacion(texto_const, texto_const);
    tiempo_final = chrono::high_resolution_clock::now();
    auto tiempo_compilacion = chrono::duration_cast<chrono::nanoseconds>(tiempo_final - tiempo_inicial);

    cout << "Tiempos de las funciones:" << endl;
    cout << "Tiempo ejecucion con string: " << tiempo_ejecucion_str.count() << " nanosegundos" << endl;
    cout << "Tiempo ejecucion con puntero a char: " << tiempo_ejecucion_char_ptr.count() << " nanosegundos" << endl;
    cout << "Tiempo ejecucion con la compracion en timepo de compilacion con puntero a char: " << tiempo_compilacion.count() << " nanosegundos" << endl;

    cout<<endl;
    cout << "Verificacion de funcionamiento:" << endl;
    cout << "Resultado con char* en ejecucion: " << (res_char ? "Iguales" : "Diferentes") << endl;
    cout << "Resultado con string en ejecucion: " << (res_str ? "Iguales" : "Diferentes") << endl;
    cout << "Resultado con char* con el preprocesamiento en tiempo de compilacion: " << (res_const ? "Iguales" : "Diferentes") << endl;
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
