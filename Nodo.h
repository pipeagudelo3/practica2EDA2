#ifndef NODO_H
#define NODO_H

class Nodo {
    public:
        Nodo* siguiente;
        Nodo* izquierdo;
        Nodo* derecho;

        char c;
        int frecuencia;

        Nodo(char c, int frecuencia);
};

#endif