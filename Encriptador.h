#ifndef ENCRIPTADOR_H
#define ENCRIPTADOR_H

#include "Lista.h"
#include "HashTable.h" // Asegúrate de incluir el archivo de encabezado de TablaHash aquí
#include <string>

class Encriptador {
private:
    void pathFinder(std::string d, Nodo* nodo, TablaHash& tabla);
public:
    std::string encriptar(std::string* texto, TablaHash& tabla);
    std::string descifrar(std::string* texto, TablaHash& tabla);
};

#endif // ENCRIPTADOR_H