#include "Contacto.h"
#include "IngresarContacto.h"
#include <fstream>
#include <sstream>
#include <limits>
#include <filesystem>

void IngresarContacto::ingresarContacto() {
    std::string nombre, apellido, email;
    int telefono;

    std::cout << "Ingrese los datos del contacto o ingrese 0 para omitir un campo:" << std::endl;
    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);
    if (nombre == "0") {
        nombre = "";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Apellido: ";
    std::getline(std::cin, apellido);
    if (apellido == "0") {
        apellido = "";
    }

    std::cout << "Teléfono: ";
    std::string telefonoStr;
    std::getline(std::cin, telefonoStr);
    if (telefonoStr == "0") {
        telefono = 0;
    } else {
        std::istringstream(telefonoStr) >> telefono;
    }

    std::cout << "Email: ";
    std::getline(std::cin, email);
    if (email == "0") {
        email = "";
    }

    Contacto nuevoContacto(nombre, apellido, telefono, email);

    // Crear el nombre del archivo con el nombre del contacto
    std::string nombreArchivo = nombre + "_" + apellido + ".txt";

    // Concatenar la ruta base con el nombre del archivo
    std::filesystem::path rutaBase("/home/moisibot/CLionProjects/GestionContactos/contactos");
    std::filesystem::path rutaCompleta = rutaBase / nombreArchivo;

    std::ofstream archivo(rutaCompleta);
    if (archivo.is_open()) {
        // Escribir los datos del contacto en el archivo
        archivo << "Nombre: " << nuevoContacto.getNombre() << std::endl;
        archivo << "Apellido: " << nuevoContacto.getApellido() << std::endl;
        archivo << "Teléfono: " << nuevoContacto.getTelefono() << std::endl;
        archivo << "Email: " << nuevoContacto.getEmail() << std::endl;

        archivo.close();
        std::cout << "Contacto guardado exitosamente en '" << rutaCompleta << "'." << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo '" << rutaCompleta << "'." << std::endl;
    }
}



void IngresarContacto::guardarContacto(std::ofstream& archivo, const Contacto& contacto) {
    archivo << "Nombre: " << contacto.nombre << std::endl;
    archivo << "Apellido: " << contacto.apellido << std::endl;
    archivo << "Teléfono: " << contacto.telefono << std::endl;
    archivo << "Email: " << contacto.email << std::endl << std::endl;
}