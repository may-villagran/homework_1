#ifndef EJERCICIO3_HPP
#define EJERCICIO3_HPP

#include <iostream>
#include <memory>
using namespace std;

/**
 * @brief Estructura que representa un nodo de la lista.
 */
struct Node_t {
    int value;            ///< Valor almacenado en el nodo.
    shared_ptr<Node_t> next;  ///< Puntero al siguiente nodo en la lista.
};

/**
 * @brief Estructura que representa la lista enlazada.
 */
struct List_t {
    shared_ptr<Node_t> head;  ///< Puntero al primer nodo de la lista.
    shared_ptr<Node_t> tail;  ///< Puntero al último nodo de la lista.
    size_t size;              ///< Tamaño de la lista.
};

/**
 * @brief Crea una nueva lista vacía.
 * 
 * @return shared_ptr<List_t> Puntero compartido a la nueva lista creada.
 */
shared_ptr<List_t> create_list();

/**
 * @brief Devuelve el nodo anterior al nodo en la posición especificada.
 * 
 * @param list Lista de la que se obtiene el nodo anterior.
 * @param pos Posición en la lista donde se busca el nodo anterior.
 * @return shared_ptr<Node_t> Puntero al nodo anterior.
 */
shared_ptr<Node_t> prev_node(shared_ptr<List_t> list, int pos);

/**
 * @brief Elimina el nodo al final de la lista.
 * 
 * @param list Lista de la cual se eliminará el nodo al final.
 */
void delete_tail(shared_ptr<List_t> list);

/**
 * @brief Elimina el nodo al principio de la lista.
 * 
 * @param list Lista de la cual se eliminará el nodo al principio.
 */
void delete_head(shared_ptr<List_t> list);

/**
 * @brief Crea un nuevo nodo con un valor especificado.
 * 
 * @param value Valor que se asignará al nuevo nodo.
 * @return shared_ptr<Node_t> Puntero al nodo creado.
 */
shared_ptr<Node_t> create_nodo(int value);

/**
 * @brief Agrega un nuevo nodo al principio de la lista.
 * 
 * @param list Lista a la que se agregará el nodo.
 * @param value Valor del nodo que se agregará.
 * @return bool Retorna true si el nodo fue agregado exitosamente, false en caso contrario.
 */
bool push_front(shared_ptr<List_t> list, int value);

/**
 * @brief Agrega un nuevo nodo al final de la lista.
 * 
 * @param list Lista a la que se agregará el nodo.
 * @param value Valor del nodo que se agregará.
 * @return bool Retorna true si el nodo fue agregado exitosamente, false en caso contrario.
 */
bool push_back(shared_ptr<List_t> list, int value);

/**
 * @brief Inserta un nuevo nodo en una posición específica de la lista si esta es válida, de lo contrario insertará el nodo en el final de la lista.
 * 
 * @param list Lista donde se insertará el nodo.
 * @param pos Posición en la cual se insertará el nuevo nodo.
 * @param value Valor del nodo que se insertará.
 * @return bool Retorna true si el nodo fue insertado exitosamente, false en caso contrario.
 */
bool insert(shared_ptr<List_t> list, int pos, int value);

/**
 * @brief Elimina un nodo en una posición específica de la lista si esta es válida, de lo contrario eliminará el nodo al final de la lista.
 * 
 * @param list Lista de la cual se eliminará el nodo.
 * @param pos Posición del nodo que se eliminará.
 */
void erase(shared_ptr<List_t> list, int pos);

/**
 * @brief Imprime el contenido de la lista.
 * 
 * @param list Lista que se desea imprimir.
 */
void print_list(shared_ptr<List_t> list);

#endif // EJERCICIO3_H
