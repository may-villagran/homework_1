#include "ejercicio2.hpp"

string casteo_string(ETIQUETAS nivel_importancia) {
    switch (nivel_importancia) {
        case ETIQUETAS::DEBUG: return "DEBUG";
        case ETIQUETAS::INFO: return "INFO";
        case ETIQUETAS::WARNING: return "WARNING";
        case ETIQUETAS::ERROR: return "ERROR";
        case ETIQUETAS::CRITICAL: return "CRITICAL";
        default: return " ";
    }
}

void salida_archivo(string etiqueta, string mensaje) {
    try {
        ofstream archivo_salida("logMessage_archivo.txt", ios::app);
        if (!archivo_salida.is_open()) {
            throw runtime_error("No se pudo abrir el archivo");
        }
        archivo_salida << "[" << etiqueta << "]: " << mensaje << endl;
        archivo_salida.close();
    } catch (const runtime_error &e) {
        cout << "Runtime error: " << e.what() << endl;
    }
}

void logMessage(string mensaje, ETIQUETAS nivel_importancia) {
    string str_etiqueta = casteo_string(nivel_importancia);
    salida_archivo(str_etiqueta, mensaje);
}

void logMessage(string mensaje_error, string archivo, int linea_codigo) {
    string str_etiqueta = "ERROR";
    string str_linea = to_string(linea_codigo);
    string mensaje = mensaje_error + ", en el archivo: \"" + archivo + "\", línea: " + str_linea;
    salida_archivo(str_etiqueta, mensaje);
}

void logMessage(string mensaje_acceso, string nombre_usuario) {
    string str_etiqueta = "SECURITY";
    string mensaje = mensaje_acceso + ", para el usuario: " + nombre_usuario;
    salida_archivo(str_etiqueta, mensaje);
}

void test_logMessage() {
    logMessage("acceso autorizado", "usuario_de_prueba");
    logMessage("Leyendo el archivo de configuración", ETIQUETAS::DEBUG);
    logMessage("El archivo \"texto.txt\" fue creado", ETIQUETAS::INFO);
    logMessage("Intento de cambiar el tipo del archivo 'documento.txt' a 'documento.pdf' no es compatible", ETIQUETAS::WARNING);
    logMessage("Error de lectura en el disco, acceso a datos imposible.", ETIQUETAS::CRITICAL);
    logMessage("Error al abrir el archivo para lectura", "datos.csv", 240);
}

bool test_captura_runtime_error() {
    try {
        throw runtime_error("Runtime_error: error desconocido");
    } catch (const runtime_error &e) {
        logMessage(e.what(), ETIQUETAS::ERROR);
        return true;
    }
    return false;
}

int main() {
    test_logMessage();
    if (test_captura_runtime_error()) return 1;
    return 0;
}
