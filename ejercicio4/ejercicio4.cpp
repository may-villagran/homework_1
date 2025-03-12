#include <chrono> 
#include <string>
#include <iostream>
using namespace std;

consteval bool coincidencia_texto_compilacion(const char* str1, const char* str2){
    if(*str1 == '\0'&&  *str2 == '\0') return true;
    else if(*str1 != *str2) return false;
    return coincidencia_texto_compilacion(++str1, ++str2);   
}

bool coincidencia_texto(const char* str1, const char* str2){
    if(*str1 == '\0'&& *str2 == '\0') return true;
    else if(*str1 != *str2) return false;
    return coincidencia_texto(++str1, ++str2);
}




int main(){
    auto tiempo_inicial = chrono::high_resolution_clock::now();
    bool res = coincidencia_texto("abcdefghi\0", "abcdefghj\0");
    auto tiempo_final = chrono::high_resolution_clock::now();
    auto tiempo_ejecucion =  chrono::duration_cast<chrono::nanoseconds>(tiempo_final - tiempo_inicial); 

    tiempo_inicial = chrono::high_resolution_clock::now();
    bool  res2 = coincidencia_texto_compilacion;
    tiempo_final = chrono::high_resolution_clock::now();
    auto tiempo_compilacion = chrono::duration_cast<chrono::nanoseconds>(tiempo_final-tiempo_inicial);
    

    cout<<"Tiemmpo ejecucion: "<<tiempo_ejecucion.count()<<" nanosegundos"<<endl;
    cout<<"Tiemmpo compilacion: "<<tiempo_compilacion.count()<<" nanosegundos"<<endl;
}


/*
el compilador no toma los objetos como una constante, en cambio el puntero una vez definido es constante

    COMPILACION SI O SI CON VERSION 23

*/