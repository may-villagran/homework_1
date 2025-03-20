#include "ejercicio3.hpp"


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
    if(pos<0 || pos>=static_cast<int>(list->size) ) return nullptr;
    
    shared_ptr<Node_t> prev_node = list->head;
    if(pos == 1) return prev_node;
    
    for(int i=1; i<pos; i++)  prev_node = prev_node->next;

    return prev_node;
}

void delete_tail(shared_ptr<List_t>list){
    if(list->size == 0) return;
    if(list->size == 1) {
        list->head = list->tail = nullptr;
        list->size = 0;
        return;    
    }

    shared_ptr<Node_t> prev_tail = prev_node(list, list->size-1);
    list->tail = prev_tail;
    prev_tail->next = nullptr;
    
    list->size--;

}

void delete_head(shared_ptr<List_t>list){
    if(list->size == 0) return;
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

    //si la lista esta vacia por default agrego al principio
    if(pos == 0 || list->size == 0) return push_front(list, value);
    //defino que tambien para las posiciones negativas agrego al final de la lista
    if(pos>=static_cast<int>(list->size) || pos<0) return push_back(list, value); 
    
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
    if(list->size == 0){
        cerr << "Advertencia: Intento de borrar de una lista vacía." << endl; //cer salida de consola de advertencia 
        return;}


    if(pos==0) {
        delete_head(list); 
        return;
    }
    //si paso posiciones fuera del rango elimino la tail, tanto para pos neg como mayores al tam
    if(pos>=static_cast<int>(list->size) || pos<0){
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
    shared_ptr<Node_t> nodo = create_nodo(4);
    if(!nodo) return 1;

    cout<<"Test creacion nodo: \n Dirección en memoria: "<<nodo<<" \n Valor asignado:"<<nodo->value<<endl;
    shared_ptr<List_t> list = create_list();
    if(!list) return 1;

    bool flag = push_back(list, 1);
    cout<<"Test push_back, valor 1. Estado: "<<(flag ? "Agregado" : "No se pudo agregar el valor a la lista")<<endl;
    cout<<"Estado de la lista actual:"<<endl;
    print_list(list);

    flag = push_front(list, 0);
    cout<<"Test push_front, valor 0. Estado:"<<(flag ? "Agregado" : "No se pudo agregar el valor a la lista")<<endl;
    cout<<"Estado de la lista actual:"<<endl;
    print_list(list);

    flag = insert(list, 1, 23);
    cout<<"Test insert en la pos 1, valor 23. Estado:"<<(flag ? "Agregado" : "No se pudo agregar el valor a la lista")<<endl;
    cout<<"Estado de la lista actual:"<<endl;
    print_list(list);

    flag = insert(list, 40, 897);
    cout<<"Test insert en la pos 42,  valor 897. Estado:"<<(flag ? "Agregado" : "No se pudo agregar el valor a la lista")<<endl;
    cout<<"Estado de la lista actual:"<<endl;
    print_list(list);



    erase(list, 0);
    cout<<"Test erase, valor borrado de la pos 0."<<endl;
    cout<<"Estado de la lista actual:"<<endl;
    print_list(list);

    erase(list, 98);
    cout<<"Test erase, valor borrado de la pos 98."<<endl;
    cout<<"Estado de la lista actual:"<<endl;
    print_list(list);

    erase(list, 98);
    cout<<"Test erase, valor borrado de la pos 98."<<endl;
    cout<<"Estado de la lista actual:"<<endl;
    print_list(list);

    erase(list, 787);
    cout<<"Test erase, borrado de último elemento."<<endl;
    cout<<"Estado de la lista actual:"<<endl;
    print_list(list);

    erase(list, 787);
    cout<<"Test erase, borrado cuando no hay elementos."<<endl;
    cout<<"Estado de la lista actual:"<<endl;
    print_list(list);


    


   
    return 0;
}