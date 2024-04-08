#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

class Lista {
    private:
        Nodo* merge(Nodo* lista1, Nodo* lista2) const;

        Nodo* encontrarMitad() const;
        void dividir(Lista** lista1, Lista** lista2, Nodo* corte);
        void bisecar(Lista** lista1, Lista** lista2);

    public:
        Nodo* cabeza;

        Lista();
        ~Lista();
        
        void agregar(Nodo* nodo);

        Nodo* contiene(char c);

        void mergeSort();

        void convertirAHuffman();
};

#endif