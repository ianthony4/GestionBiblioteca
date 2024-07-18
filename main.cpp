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
    std::cout "Ingrese el precio del libro: ";
    std::cin >> libro.precio;
    
    libros.push_back(libro);
}