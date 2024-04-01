#include "Grupo.h"
#include "ListaEnlazada.h"
#include <cctype>
#include "iostream"
#include <sstream>
#include "filesystem"
#include "vector"
#include "fstream"

Contacto::Contacto(std::string nombre, std::string apellido, int telefono, std::string email) {
    this->nombre = std::move(nombre);
    this->apellido = std::move(apellido);
    this->telefono = telefono;
    this->email = std::move(email);
}
Grupo::Grupo(std::string nombre) : nombre(std::move(nombre)) {}

void Grupo::agregarContacto(const Contacto& contacto) {
    contactos[contacto.nombre] = contacto;
}
void Grupo::mostrarContactos() const {
    for (const auto& [nombre, contacto] : contactos) {
        std::cout << "Nombre: " << contacto.nombre << std::endl;
        std::cout << "Apellido: " << contacto.apellido << std::endl;
        std::cout << "Telefono: " << contacto.telefono << std::endl;
        std::cout << "Email: " << contacto.email << std::endl;
        std::cout << std::endl;
    }
}
void Grupo::crearFormulario(const std::string& camposStr) {
    campos = camposStr;

}
void Grupo::crearCarpeta() {
    std::filesystem::path rutaBase("/home/moisibot/CLionProjects/GestionContactos/contactos");
    rutaCarpeta = rutaBase / nombre;
    if (!std::filesystem::exists(rutaCarpeta)) {
        try {
            std::filesystem::create_directory(rutaCarpeta);
            std::cout << "carpeta creada: " << rutaCarpeta << std::endl;
        } catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "error al crear la carpeta: " << e.what() << std::endl;
        }
    } else {
        std::cout << "La carpeta ya existe: " << rutaCarpeta << std::endl;
    }
}

void Grupo::solicitarValoresCampos() {
    std::ofstream archivoContactos;
    std::filesystem::path rutaArchivo = rutaCarpeta / "contactos.txt";
    if (std::filesystem::exists(rutaArchivo)) {
        archivoContactos.open(rutaArchivo, std::ios::app);
    } else {
        archivoContactos.open(rutaArchivo);
    }
    if (!archivoContactos) {
        std::cerr << "Error al abrir el archivo contactos.txt" << std::endl;
        return;
    }
    std::string nombre, apellido, email;
    int telefono;
    std::cout << "Ingrese los datos del contacto (ingrese 0 para omitir un campo):" << std::endl;
    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);
    if (nombre == "0") {
        nombre = "";
    }
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
    agregarContacto(nuevoContacto);
    rutaArchivo = rutaCarpeta / (nuevoContacto.nombre + ".txt");
    std::ofstream archivoContacto(rutaArchivo);

    if (!archivoContacto) {
        std::cerr << "Error al abrir el archivo " << rutaArchivo << std::endl;
        return;
    }
    guardarContacto(archivoContacto, nuevoContacto);
    archivoContacto.close();
}

void Grupo::guardarContacto(std::ofstream& archivo, const Contacto& contacto) {
    archivo << "Nombre: " << contacto.nombre << std::endl;
    archivo << "Apellido: " << contacto.apellido << std::endl;
    archivo << "Teléfono: " << contacto.telefono << std::endl;
    archivo << "Email: " << contacto.email << std::endl;
}

bool Grupo::existeCarpeta() {
    std::filesystem::path rutaBase("/home/moisibot/CLionProjects/GestionContactos");
    rutaCarpeta = rutaBase / nombre;
    return std::filesystem::exists(rutaCarpeta);
}
