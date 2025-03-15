#ifndef EJERCICIO3_H
#define EJERCICIO3_H
#include <memory>
#include <iostream>
using namespace std;

struct Node_t {
    int value; //DESPUES CAMBIAR A VOID
    shared_ptr<Node_t> next;
};

struct  List_t{
    shared_ptr<Node_t> head;
    shared_ptr<Node_t> tail;
    size_t size;
};



shared_ptr<List_t> create_list();
shared_ptr<Node_t> prev_node(shared_ptr<List_t>list, int pos);
void delete_tail(shared_ptr<List_t>list);
void delete_head(shared_ptr<List_t>list);
shared_ptr<Node_t> create_nodo(int value);
bool push_front(shared_ptr<List_t>list, int value);
bool push_back(shared_ptr<List_t>list, int value);
bool insert(shared_ptr<List_t>list, int pos, int value);
void erase(shared_ptr<List_t>list, int pos);
void print_list(shared_ptr<List_t>list);



#endif