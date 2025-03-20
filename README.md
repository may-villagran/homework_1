# homework_1
## Compilación de archivos y ejecución: 
**Ejercicio 1:**
   - g++ -Wall -Wextra -Werror ejercicio1.cpp -o ejercicio1
   - valgrind ./ejercicio1

**Ejercicio 2:**
   - g++ -Wall -Wextra -Werror ejercicio2.cpp -o ejercicio2
   - valgrind ./ejercicio2

**Ejercicio 3:**
   - g++ -Wall -Wextra -Werror ejercicio3.cpp -o ejercicio3
   - valgrind ./ejercicio3

**Ejercicio 4:**
   - g++ -Wall -Wextra -Werror ejercicio4.cpp -o ejercicio4
   - valgrind ./ejercicio4

## Descripción de los códigos:

### Ejercicio 1
Este programa gestiona una matriz dinámica de tamaño `n x n`. Se incluyen funciones para:
- Reservar memoria (`asignacion_memoria`).
- Inicializar la matriz con valores consecutivos (`matriz_valores`).
- Imprimir la matriz en orden inverso (`imprimir_matriz`).
- Liberar la memoria reservada (`destruir_matriz`).

### Ejercicio 2
Este programa implementa un sistema de registro de logs en un archivo de texto. Permite almacenar mensajes con distintos niveles de importancia (`DEBUG`, `INFO`, `WARNING`, `ERROR`, `CRITICAL`), además de logs específicos para errores con archivo y línea de código, y eventos de seguridad relacionados con usuarios.

### Ejercicio 3
Este programa implementa una lista enlazada simple utilizando `shared_ptr`. Permite operaciones como:
- Agregar elementos al principio y al final.
- Insertar en posiciones específicas.
- Eliminar nodos.
- Recorrer la lista.

### Ejercicio 4
Este programa implementa comparaciones de cadenas (`char*` y `std::string`), incluyendo una evaluación en **tiempo de compilación** con `constexpr`. También mide y compara los tiempos de ejecución de cada método.



