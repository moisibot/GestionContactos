
#ifndef GESTIONCONTACTOS_BUSQUEDA_H
#define GESTIONCONTACTOS_BUSQUEDA_H

#include <unordered_map>
#include <string>
#include "ContactoIndi.h"

class Busqueda {
public:
    Busqueda();
    explicit Busqueda(const std::unordered_map<std::string, ContactoIndi> &contactosPorNombreArchivo);
    static ContactoIndi buscarContactoPorNombreArchivo(const std::string& nombreArchivo) ;

private:
    std::unordered_map<std::string, ContactoIndi> contactosPorNombreArchivo;


};

#endif // GESTIONCONTACTOS_BUSQUEDA_H
