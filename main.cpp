#include <iostream>
#include <vector>
#include "libro.h"

std::vector<Libro> libros;

void agregarLibro(){
    Libro libro;
    std::cout << "Ingrese el codigo del libro: ";
    std::cin >> libro.codigo;
    std::cout << "Ingrese el nombre del libro: ";
    std::cin.ignore();
    std::getline(std::cin, libro.nombre);
    std::cout << "Ingrese el autor del libro: ";
    std::getline(std::cin, libro.autor);
    std::cout << "Ingrese el año de publicacion: ";
    std::cin >> libro.anioPublicacion;
    std::cout << "Ingrese el precio del libro: ";
    std::cin >> libro.precio;
    
    libros.push_back(libro);
}

//Aqui se listara los libros
void listarLibros(){
    //for each para recorrer los libros
    std::cout << "*********Lista de Libros********" << std::endl;
    for(const auto& libro : libros){
        std::cout << "Codigo: " << libro.codigo << std::endl;
        std::cout << "Nombre: " << libro.nombre << std::endl;
        std::cout << "Autor: " << libro.autor << std::endl;
        std::cout << "Año de publicacion: " << libro.anioPublicacion << std::endl;
        std::cout << "Precio: " << libro.precio << std::endl;
        std::cout << "--------------------------------" << std::endl;  
    }

}

int main(){
    //Menu de opciones
    int opcion;
    do {
        std::cout << "1. Agregar Libro" << std::endl;
        std::cout << "2. Listar Libros" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "Ingrese una opcion: " << std::endl;
        std::cin >> opcion;
        switch(opcion){
            case 1:
                agregarLibro();
                break;
            case 2:
                listarLibros();
                break;
            case 3:
                std::cout << "Hasta la proxima!" << std::endl;
                break;
            //Para cualquier opcion no valida
            default:
                std::cout << "Opcion no valida, vuelva a intentarlo..." << std::endl;
        }   
    }while (opcion != 3);
    
    return 0;
}