#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Nodo.h"

using namespace std;

class TablaHash {
private:
    static const int capacidad_inicial = 12;
    vector<list<Nodo>> tabla;
    int elementos;
    // Función hash básica
    int funcionHash(const string& c) {
        int hash = 0;
        for (char c : c) {
            hash += c;
        }
        return hash % tabla.size();
    }
    // Rehashing para redimensionar la tabla
    void rehash() {
        vector<list<Nodo>> nuevaTabla(tabla.size() * 2);
        for (const auto& bucket : tabla) {
            for (const auto& entrada : bucket) {
                int nuevoIndice = funcionHash(entrada.c);
                nuevaTabla[nuevoIndice].push_back(entrada);
            }
        }
        tabla = move(nuevaTabla);
    }
public:
    // Constructor
    TablaHash() : tabla(capacidad_inicial), elementos(0) {}
    // Función para añadir un elemento
    void adicionar(const string& c, int frecuencias) {
        int indice = funcionHash(c);
        tabla[indice].push_back(Nodo(c, frecuencias));
        ++elementos;
        // Rehashing si la carga supera el factor de carga
        if (elementos > tabla.size()) {
            rehash();
        }
    }
    // Función para cambiar el frecuencias asociado a una c
    void cambiar(const string& c, int nuevoValor) {
        int indice = funcionHash(c);
        for (auto& entrada : tabla[indice]) {
            if (entrada.c == c) {
                entrada.frecuencias = nuevoValor;
                return;
            }
        }
        cout << "Clave no encontrada." << endl;
    }
    
    std::string obtenerCodigo(const std::string& c) const {
    int indice = funcionHash(c);
    for (const auto& entrada : tabla[indice]) {
        if (entrada.c == c) {
            return entrada.frecuencias;
        }
    }
    return ""; // Retornar una cadena vacía si no se encuentra el código
}
}