#include "Lista.h"

Lista::Lista() : cabeza(nullptr) {};

Lista::~Lista(){
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

void Lista::agregar(Nodo* nodo) {
    nodo->siguiente = cabeza;
    cabeza = nodo;
}

Nodo* Lista::contiene(char c) {
    Nodo* actual = cabeza;
    
    while(actual != nullptr){
        if(actual->c == c){
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

Nodo* Lista::encontrarMitad() const {
    Nodo* rapido = cabeza->siguiente;
    Nodo* lento = cabeza;

    while(rapido != nullptr && rapido->siguiente != nullptr){
        rapido = rapido->siguiente->siguiente;
        lento = lento->siguiente;
    }
    return lento;
}

void Lista::dividir(Lista** lista1, Lista** lista2, Nodo* corte) {
    if(cabeza == nullptr || cabeza->siguiente == nullptr){
        return;
    }

    (*lista1)->cabeza = cabeza;
    (*lista2)->cabeza = corte->siguiente;

    corte->siguiente = nullptr;
    
}

void Lista::bisecar(Lista** lista1, Lista** lista2) {
    dividir(lista1, lista2, encontrarMitad());
}

Nodo* Lista::merge(Nodo* lista1, Nodo* lista2) const{

    Nodo* menor = nullptr;

    if(lista1 == nullptr){
        return lista2;
    }else if(lista2 == nullptr){
        return lista1;
    }

    if(lista1->frecuencia < lista2->frecuencia){
        menor = lista1;
        menor->siguiente = merge(lista1->siguiente, lista2);
    }else{
        menor = lista2;
        menor->siguiente = merge(lista1, lista2->siguiente);
    }

    return menor;
}

void Lista::mergeSort(){
    if(cabeza == nullptr || cabeza->siguiente == nullptr){
        return;
    }

    Lista* mitad1 = new Lista();
    Lista* mitad2 = new Lista();

    bisecar(&mitad1, &mitad2);


    mitad1->mergeSort();
    mitad2->mergeSort();

    cabeza = merge(mitad1->cabeza, mitad2->cabeza);
}


//Función que transforma la lista ligada a árbol de huffman (Numeral 3)
void Lista::convertirAHuffman(){

    //Reducción a través de nodos internos hasta que la lista conste de un solo nodo (Raíz del árbol)
    while(cabeza->siguiente != nullptr){
        //Extracción de nodos menores
        Nodo* min1 = cabeza;
        Nodo* min2 = cabeza->siguiente;

        cabeza = min2->siguiente;
        min1->siguiente = nullptr;
        min2->siguiente = nullptr;

        //Se declara y agrega un nodo auxiliar
        Nodo* aux = new Nodo('\0', min1->frecuencia + min2->frecuencia);

        aux->izquierdo = min1;
        aux->derecho = min2;

        agregar(aux);

        //Se reordena la lista
        mergeSort();
    }
}