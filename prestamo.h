//Creacion de la estructura prestamo.h
#ifndef PRESTAMO_H
#define PRESTAMO_H

#include <string>

struct Prestamo {
    std::string codigoRegistro;
    std::string dniUsuario;
    std::string fechaPrestamo;
    std::string fechaDevolucion;
};

#endif