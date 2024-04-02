#include "Busqueda.h"
#include <iostream>
#include <fstream>
#include <filesystem>

Busqueda::Busqueda(const std::unordered_map<std::string, ContactoIndi> &contactosPorNombreArchivo)
        : contactosPorNombreArchivo(contactosPorNombreArchivo) {}

Busqueda::Busqueda() {
    // Constructor por defecto, no es necesario inicializar nada aquí en este ejemplo
}

ContactoIndi Busqueda::buscarContactoPorNombreArchivo(const std::string& nombreArchivo) {
    std::filesystem::path rutaBase("/home/moisibot/CLionProjects/GestionContactos/contactos");
    std::filesystem::path rutaCompleta = rutaBase / nombreArchivo;

    if (std::filesystem::exists(rutaCompleta)) {
        std::ifstream archivo(rutaCompleta);
        if (archivo.is_open()) {
            std::string nombre, apellido, email;
            int telefono;
            archivo >> nombre >> apellido >> telefono >> email;
            return ContactoIndi(nombre, apellido, telefono, email);
        } else {
            std::cerr << "Error al abrir el archivo '" << rutaCompleta << "'." << std::endl;
        }
    } else {
        std::cerr << "El archivo '" << rutaCompleta << "' no existe." << std::endl;
    }
    return ContactoIndi(); // Devolver un ContactoIndi vacío si no se encontró el archivo
}