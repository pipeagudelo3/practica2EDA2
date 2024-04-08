#include "Lista.h"
#include "Encriptador.h"
#include "HashTable.h" 
#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    std::string texto = "Hola Mundo estóy haciendo una prueba cpn una gran ..,.,.;:;:éáúíóÁSEDVKHGDUFYVBJHFVBJDHVKBXVHJSBDKVBJSHVJHSVHBSJHVBJVAJGCjhdhbcjshv.,,.,.,";
    
    Encriptador e;
    TablaHash hash; // Crear un objeto TablaHash
    
    std::cout << "Texto a comprimir :   " << texto << "\n" << std::endl;
    
    std::string encriptado = e.encriptar(&texto, hash); // Pasar la dirección de memoria de hash
    
    std::cout << "Texto comprimido :    " << encriptado << "\n" << std::endl;
    
    std::string descifrado = e.descifrar(&encriptado, hash); // Pasar la referencia de hash
    
    std::cout << "Texto descomprimido :    " << descifrado << "\n" << std::endl;
    
    return 0;
}