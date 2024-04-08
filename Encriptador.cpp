#include "Encriptador.h"

//Función que recorre el árbol de huffman recursivamente y registra las representaciones binarias de los caracteres (Numeral 5)
void Encriptador::pathFinder(std::string d, Nodo* nodo, TablaHash& tabla){
    char _c = nodo->c;

    if(_c != '\0'){ //Caso base: el nodo actual es hoja
        tabla.adicionar(std::string(1, _c), nodo->frecuencia);
    }else{ //Caso recursivo: el nodo actual es un nodo interno
        if(nodo->izquierdo != nullptr){
            pathFinder(d + "0", nodo->izquierdo, tabla);
        }
        if(nodo->derecho != nullptr){
            pathFinder(d + "1", nodo->derecho, tabla);
        }
    }
}

//Función para comprimir una cadena de texto.
//Toma por parámetros las direcciones de memoria del texto a comprimir y de la hash-table donde se almacenarán los códigos
std::string Encriptador::encriptar(std::string* texto, TablaHash& tabla){

    //Numerales 1 y 2 del pseudocódigo
    Lista* lista = new Lista();
    for(char c : *texto){
        Nodo* nodo = lista->contiene(c);
        if(nodo != nullptr){
            nodo->frecuencia++;
        }else{
            lista->agregar(new Nodo(c, 1));
        }
    }
    lista->mergeSort();

    //Conversión de la lista a árbol de huffman (Numeral 3)
    lista->convertirAHuffman();

    //Navegación del árbol para obtener hash-table de códigos (Numeral 5)
    pathFinder("", lista->cabeza, tabla);

    //Compresión del texto caracter por caracter (Numeral 7)
    std::string comprimido = "";

    for(char c : *texto){
        comprimido += tabla.obtenerCodigo(std::string(1, c));
    }

    return comprimido;
}

//Función para descomprimir una cadena de texto (Numeral 9)
//Toma por parámetros las direcciones de memoria del texto comprimido y de la hash-table que permitirá decodificarlo
std::string Encriptador::descifrar(std::string* texto, TablaHash& tabla){
    std::string descifrado = "";
    std::string codigo = "";

    //Agrupación ordenada de bits del texto cifrado
    for(char c : *texto){
        codigo += c;

        //Verificación respecto a tabla de decodificación
        for(const auto& bucket : tabla.getTabla()){
            for(const auto& entrada : bucket){
                if(entrada.c == codigo){
                    descifrado += entrada.frecuencia;
                    codigo = "";
                    break;
                }
            }
        }
    }

    return descifrado;
}