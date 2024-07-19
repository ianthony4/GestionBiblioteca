#include <iostream>
#include <vector>
#include "libro.h"
#include <fstream> // Para los ficheros
#include "prestamo.h"
#include "usuario.h"

std::vector<Libro> libros;
std::vector<Usuario> usuarios;
std::vector<Prestamo> prestamos;

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

// Manipulacion de ficheros
void guardarLibros(){
    std::ofstream archivo("librosGuardados.txt");
    if(!archivo){
        std::cerr << "Error al abrir el archivo para guardarlo." << std::endl;
        return;
    }

    for(const auto& libro : libros){
        archivo << libro.codigo << "\n"
                << libro.nombre << "\n"
                << libro.autor << "\n"
                << libro.anioPublicacion << "\n"
                << libro.precio << "\n";
    }

    archivo.close();
    std::cout << "libro guardado con exito!" << std::endl;

}

// Ficheros - Cargar libros
void cargarLibros(){
    std::ifstream archivo("librosParaCargar.txt");
    if(!archivo){
        std::cerr << "Error al abrir el archivo para cargar." << std::endl;
        return;
    }
    libros.clear();
    //Creamos el objeto libro que se encargara de recoger los datos
    Libro libro;
    while(archivo >> libro.codigo){
        archivo.ignore();
        std::getline(archivo, libro.nombre);
        std::getline(archivo, libro.autor);
        archivo >> libro.anioPublicacion >> libro.precio;
        archivo.ignore();
        libros.push_back(libro);
    }

    archivo.close();
    std::cout << "Libros cargados!!" << std::endl;
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

//Metodo para agregar nuevos usuarios
void agregarUsuario(){
    Usuario usuario;
    std::cout << "Ingrese el DNI del usuario: ";
    std::cin >> usuario.dni;
    std::cout << "Ingrese el nombre del usuario: ";
    std::cin.ignore();
    std::getline(std::cin, usuario.nombre);
    std::cout << "Ingrese el email del usuario: ";
    std::getline(std::cin, usuario.email);
    std::cout << "Ingrese el telefono del usuario: ";
    std::getline(std::cin, usuario.telefono);

    usuarios.push_back(usuario);
}

//Metodo para establecer un prestamo
void establecerPrestamo() {
    Prestamo prestamo;
    std::cout << "Ingrese el codigo del libro: ";
    std::cin >> prestamo.codigoRegistro;
    std::cout << "Ingrese el DNI del usuario: ";
    std::cin >> prestamo.dniUsuario;
    std::cout << "Ingrese la fecha de prestamo (DD/MM/AAAA): ";
    std::cin >> prestamo.fechaPrestamo;
    std::cout << "Ingrese la fecha de devolucion (DD/MM/AAAA): ";
    std::cin >> prestamo.fechaDevolucion;
    prestamos.push_back(prestamo);
}

//Metodo para establecer una devolucion
void establecerDevolucion() {
    std::string codigoRegistro, dniUsuario;
    std::cout << "Ingrese el codigo del libro: ";
    std::cin >> codigoRegistro;
    std::cout << "Ingrese el DNI del usuario: ";
    std::cin >> dniUsuario;
    
    for (auto& prestamo : prestamos) {
        if (prestamo.codigoRegistro == codigoRegistro && prestamo.dniUsuario == dniUsuario) {
            std::cout << "Ingrese la nueva fecha de devolucion (DD/MM/AAAA): ";
            std::cin >> prestamo.fechaDevolucion;
            std::cout << "Fecha de devolucion actualizada con exito." << std::endl;
            return;
        }
    }
    std::cout << "No se encontro un prestamo con esos datos." << std::endl;
}

//Metodo para listar los prestamos
void listarPrestamos() {
    for (const auto& prestamo : prestamos) {
        std::cout << "Codigo del Libro: " << prestamo.codigoRegistro << std::endl;
        std::cout << "DNI del Usuario: " << prestamo.dniUsuario << std::endl;
        std::cout << "Fecha de Prestamo: " << prestamo.fechaPrestamo << std::endl;
        std::cout << "Fecha de Devolucion: " << prestamo.fechaDevolucion << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
}

int main(){
    //inicializarLibros();
    //Menu de opciones
    int opcion;
    do {
        std::cout << "1. Agregar Libro" << std::endl;
        std::cout << "2. Listar Libros" << std::endl;
        std::cout << "3. Eliminar Libro" << std::endl;
        std::cout << "4. Buscar Libro" << std::endl;
        std::cout << "5. Actualizar Libro" << std::endl;
        std::cout << "6. Guardar Libros" << std::endl;
        std::cout << "7. Cargar Libros" << std::endl;
        std::cout << "8. Salir" << std::endl;
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
                actualizarLibros();
                break;
            case 6:
                guardarLibros();
                break;
            case 7:
                cargarLibros();
                break;
            case 8:
                std::cout << "Hasta la proxima!" << std::endl;
                break;
            //Para cualquier opcion no valida
            default:
                std::cout << "Opcion no valida, vuelva a intentarlo..." << std::endl;
        }   
    }while (opcion != 8);
    
    return 0;

}