#include "ContactoIndi.h"
#include "IngresarContacto.h"
#include <fstream>
#include <sstream>
#include <limits>
#include <filesystem>

/*
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
    ContactoIndi nuevoContacto(nombre, apellido, telefono, email);
    std::string nombreArchivo = nombre + "" + apellido + ".txt";
    std::filesystem::path rutaBase("/home/moisibot/CLionProjects/GestionContactos/contactos");
    std::filesystem::path rutaCompleta = rutaBase / nombreArchivo;

    std::ofstream archivo(rutaCompleta);
    if (archivo.is_open()) {
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
*/
void IngresarContacto::ingresarContactoPorComando(const std::string& comando) {
    std::istringstream iss(comando);
    std::string add, newcontact, fields, attributes;
    iss >> add >> newcontact >> fields;
    if (add == "ADD" && newcontact == "NEW-CONTACT" && fields == "FIELDS") {
        std::string nombre, apellido, email;
        int telefono = 0;
        std::getline(iss, attributes, ';');
        attributes.erase(0, 2);
        attributes.erase(attributes.size() - 1);
        std::istringstream iss2(attributes);
        std::string attribute;
        while (std::getline(iss2, attribute, ',')) {
            std::istringstream iss3(attribute);
            std::string key, value;
            std::getline(iss3 >> std::ws, key, '=');
            std::getline(iss3, value);
            if (key == "nombre") {
                nombre = value;
            } else if (key == "apellido") {
                apellido = value;
            } else if (key == "telefono") {
                telefono = std::stoi(value);
            } else if (key == "email") {
                email = value;
            }
        }
        ContactoIndi nuevoContacto(nombre, apellido, telefono, email);
        std::string nombreArchivo = nombre + "" + apellido + ".txt";
        std::filesystem::path rutaBase("/home/moisibot/CLionProjects/GestionContactos/contactos");
        std::filesystem::path rutaCompleta = rutaBase / nombreArchivo;

        std::ofstream archivo(rutaCompleta);
        if (archivo.is_open()) {
            guardarContacto(archivo, nuevoContacto);
            archivo.close();
            std::cout << "Contacto guardado exitosamente en " << rutaCompleta << " " << std::endl;
        } else {
            std::cerr << "Error al abrir el archivo '" << rutaCompleta << "'." << std::endl;
        }
    } else {
        std::cout << "El comando no es válido" << std::endl;
    }
}

void IngresarContacto::guardarContacto(std::ofstream& archivo, const ContactoIndi& contacto) {
    archivo << "Nombre: " << contacto.nombre << std::endl;
    archivo << "Apellido: " << contacto.apellido << std::endl;
    archivo << "Teléfono: " << contacto.telefono << std::endl;
    archivo << "Email: " << contacto.email << std::endl << std::endl;
}
ContactoIndi::ContactoIndi(const std::string& nombre, const std::string& apellido, int telefono, const std::string& email)
        : nombre(nombre), apellido(apellido), telefono(telefono), email(email) {}

std::string ContactoIndi::getNombre() const {
    return nombre;
}

std::string ContactoIndi::getApellido() const {
    return apellido;
}

int ContactoIndi::getTelefono() const {
    return telefono;
}

std::string ContactoIndi::getEmail() const {
    return email;
}