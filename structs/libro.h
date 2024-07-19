#ifndef LIBRO_H
#define LIBRO_H

#include <string>

struct Libro {
    std::string codigo;
    std::string nombre;
    std::string autor;
    int anioPublicacion;
    double precio;
};

#endif 