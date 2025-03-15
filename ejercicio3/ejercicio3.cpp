#include "ejercicio3.h"


shared_ptr<List_t> create_list(){
    shared_ptr<List_t>list = nullptr;
    try{
        list = make_shared<List_t>();
        list->head = list->tail = nullptr;
        list->size = 0;
        return list;
        
    }
    catch(const bad_alloc& e){
        cerr << e.what() << '\n';
    }
    return list;
}

shared_ptr<Node_t> prev_node(shared_ptr<List_t>list, int pos){
    shared_ptr<Node_t> prev_node = list->head;
    if(pos == 1) return prev_node;
    
    for(int i=1; i<pos; i++)  prev_node = prev_node->next;

    return prev_node;
}

void delete_tail(shared_ptr<List_t>list){
    if(list->size == 1) list->head = list->tail = nullptr;

    shared_ptr<Node_t> prev_tail = prev_node(list, list->size-1);
    list->tail = prev_tail;
    prev_tail->next = nullptr;
    
    list->size--;

}

void delete_head(shared_ptr<List_t>list){
    if(list->size == 1) list->head = list->tail = nullptr;

    list->head = list->head->next;
    list->size--;
}


shared_ptr<Node_t> create_nodo(int value){
    shared_ptr<Node_t> nodo_ptr = nullptr;  // Inicializamos el puntero a nullptr
    try {
        nodo_ptr = make_shared<Node_t>();
        nodo_ptr->value = value;
        nodo_ptr->next = nullptr;
    }
    catch (const bad_alloc& e) {
        cerr << e.what() << endl;
        return nullptr;  // Si hay un error de asignación, retornamos nullptr
    }
    return nodo_ptr;  // Siempre devolvemos el puntero al nodo

}

bool push_front(shared_ptr<List_t>list, int value){
    if(!list) return false;

    shared_ptr<Node_t> nodo = create_nodo(value);
    if(!nodo) return false;
    
    if(list->size == 0 && list->head == nullptr) list->head = list->tail = nodo;
        
    else{
        nodo->next = list->head;
        list->head = nodo;
    }    
    list->size++;
    return true;
}

bool push_back(shared_ptr<List_t>list, int value){
    if(!list) return false;

    shared_ptr<Node_t> nodo = create_nodo(value);
    if(!nodo) return false;

    if(list->size == 0 && list->head == nullptr) list->head = list->tail = nodo;

    else{
        list->tail->next =nodo;
        list->tail = nodo;
    }

    list->size++;
    return true;


}

bool insert(shared_ptr<List_t>list, int pos, int value){
    if(!list) return false;
    
    if(pos == 0) return push_front(list, value);
    if(pos>list->size-1) return push_back(list, value); 
    
    shared_ptr<Node_t> nuevo_nodo = create_nodo(value);
    if(!nuevo_nodo) return false;

    shared_ptr<Node_t> anterior = prev_node(list, pos);

    nuevo_nodo->next = anterior->next;
    anterior->next = nuevo_nodo;
    list->size++;
    return true;

}

void erase(shared_ptr<List_t>list, int pos){
    if(!list) return;

    if(pos ==0) {
        delete_head(list); 
        return;
    }
    if(pos>=list->size-1){
        delete_tail(list); 
        return;
    }
    
    shared_ptr<Node_t> node_prev = prev_node(list, pos);

    node_prev->next = node_prev->next->next;
    list->size--;
}

void print_list(shared_ptr<List_t>list){
    shared_ptr<Node_t>curr = list->head;
    while(curr){
        cout<<curr->value<<(curr->next != nullptr? "->" : " " );
        curr = curr->next;
    }
    cout<<endl;
}


int main(){

   
    return 0;
}