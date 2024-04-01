#ifndef GESTIONCONTACTOS_CONTACTO_H
#define GESTIONCONTACTOS_CONTACTO_H

#include <string>
#include <iostream>
#include <unordered_map>

class Contactos {
public:
    std::string nombre;
    std::string apellido;
    int telefono;
    std::string email;
    Contactos() = default;
    Contactos(std::string nombre, std::string apellido, int telefono, std::string email);
};
class Contacto {
public:
    std::string nombre;
    std::string apellido;
    int telefono;
    std::string email;
    std::string campos;
    std::unordered_map<std::string, Contacto> contactos;
    void imprimir() const {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Apellido: " << apellido << std::endl;
        std::cout << "Telefono: " << telefono << std::endl;
        std::cout << "Email: " << email << std::endl;
        std::cout << std::endl;
    }


public:
    Contacto(std::string nombre, std::string apellido, int telefono, std::string email);
    std::string getNombre() const { return nombre; }
    std::string getApellido() const { return apellido; }
    int getTelefono() const { return telefono; }
    std::string getEmail() const { return email; }


    void agregarContacto(const Contactos &contactos);
};

#endif // GESTIONCONTACTOS_CONTACTO_H

