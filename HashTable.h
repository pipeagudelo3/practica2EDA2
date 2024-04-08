#ifndef TABLAHASH_H
#define TABLAHASH_H

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "Nodo.h"

class TablaHash {
private:
    static const int capacidad_inicial = 12;
    std::vector<std::list<Nodo>> tabla;
    int elementos;
    int funcionHash(const std::string& c);
    void rehash();
public:
    TablaHash();
    void adicionar(const std::string& c, int frecuencias);
    void cambiar(const std::string& c, int nuevoValor);
    std::vector<std::list<Nodo>> getTabla() const { return tabla; } // Método para obtener la tabla
};

#endif // TABLAHASH_H
