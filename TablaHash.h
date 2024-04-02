
#ifndef GESTIONCONTACTOS_TABLAHASH_H
#define GESTIONCONTACTOS_TABLAHASH_H

#include <unordered_map>
#include "Grupo.h"

#include "IngresarContacto/ContactoIndi.h"

class TablaHash {
public:
    TablaHash();
    void agregarGrupo(const std::string& nombre);
    void agregarContacto(const std::string& nombreGrupo, const Contacto& contacto);
    void mostrarContactosEnGrupo(const std::string& nombreGrupo) const;

private:
    std::unordered_map<std::string, Grupo> grupos;

};


#endif //GESTIONCONTACTOS_TABLAHASH_H
