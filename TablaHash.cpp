
#include "TablaHash.h"
#include <iostream>

TablaHash::TablaHash() {}

void TablaHash::agregarGrupo(const std::string& nombre) {
    grupos.emplace(nombre, Grupo());
}

void TablaHash::agregarContacto(const std::string& nombreGrupo, const Contacto& contacto) {
    auto it = grupos.find(nombreGrupo);
    if (it != grupos.end()) {
        it->second.agregarContacto(contacto);
    } else {
        std::cout << "El grupo " << nombreGrupo << " no existe." << std::endl;
    }
}

void TablaHash::mostrarContactosEnGrupo(const std::string& nombreGrupo) const {
    auto it = grupos.find(nombreGrupo);
    if (it != grupos.end()) {
        it->second.mostrarContactos();
    } else {
        std::cout << "El grupo " << nombreGrupo << " no existe." << std::endl;
    }
}