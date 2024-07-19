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

//Metodo para eliminar un libro
void eliminarLibro() {
    std::string codigo;
    std::cout << "Ingrese el codigo del libro a eliminar: ";
    std::cin >> codigo;
    
    for (auto i = libros.begin(); i != libros.end(); ++i) {
        if (i->codigo == codigo) {
            libros.erase(i);
            std::cout << "Libro eliminado correctamente." << std::endl;
            return;
        }
    }
    std::cout << "No se encontro un libro con ese codigo." << std::endl;
}

//Metodo para buscar un libro
void buscarLibro() {
    std::string codigo;
    std::cout << "Ingrese el codigo del libro a buscar: ";
    std::cin >> codigo;
    
    for (const auto& libro : libros) {
        if (libro.codigo == codigo) {
            std::cout << "Codigo: " << libro.codigo << std::endl;
            std::cout << "Nombre: " << libro.nombre << std::endl;
            std::cout << "Autor: " << libro.autor << std::endl;
            std::cout << "Anio de Publicacion: " << libro.anioPublicacion << std::endl;
            std::cout << "Precio: " << libro.precio << std::endl;
            return;
        }
    }
    std::cout << "No se encontro un libro con ese codigo." << std::endl;
}

//Metodo para actualizar la informacion de los libros
void actualizarLibros(){
    std::string codigo;
    std::cout << "Ingrese el codigo del libro para actualizar";
    std::cin >> codigo;

    for(auto& libro : libros){
        if(libro.codigo == codigo){
            std::cout << "Ingrese el nuevo nombre: ";
            std::cin.ignore();
            std::getline(std::cin, libro.nombre);
            std::cout << "Ingrese el nuevo autor: ";
            std::getline(std::cin, libro.autor);
            std::cout << "Ingrese el nuevo anio de publicacion: ";
            std::cin >> libro.anioPublicacion;
            std::cout << "Ingrese el nuevo precio: ";
            std::cin >> libro.precio;
            std::cout << "Exito al actualizar. " << std::endl;
            return;
            
        }
    }

    std::cout << "No se encontro el libro" << std::endl;
}


//Para hacer pruebas y no perder tiempo creando libros
void inicializarLibros(){
    // Libro 1
    Libro libro1;
    libro1.codigo = "L001";
    libro1.nombre = "Cien Anios de Soledad";
    libro1.autor = "Gabriel Garcia Marquez";
    libro1.anioPublicacion = 1967;
    libro1.precio = 25.50;
    libros.push_back(libro1);

    // Libro 2
    Libro libro2;
    libro2.codigo = "L002";
    libro2.nombre = "1984";
    libro2.autor = "George Orwell";
    libro2.anioPublicacion = 1949;
    libro2.precio = 20.00;
    libros.push_back(libro2);
}

int main(){
    inicializarLibros();
    //Menu de opciones
    int opcion;
    do {
        std::cout << "1. Agregar Libro" << std::endl;
        std::cout << "2. Listar Libros" << std::endl;
        std::cout << "3. Eliminar Libro" << std::endl;
        std::cout << "4. Buscar Libro" << std::endl;
        std::cout << "5. Salir" << std::endl;
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
                eliminarLibro();
                break;
            case 4:
                buscarLibro();
                break;
            case 5:
                std::cout << "Hasta la proxima!" << std::endl;
                break;
            //Para cualquier opcion no valida
            default:
                std::cout << "Opcion no valida, vuelva a intentarlo..." << std::endl;
        }   
    }while (opcion != 5);
    
    return 0;

}