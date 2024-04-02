#ifndef GESTIONCONTACTOS_CONTACTOINDI_H
#define GESTIONCONTACTOS_CONTACTOINDI_H
#include <string>
#include <iostream>
#include <unordered_map>
#include <string>
#include <iostream>

class Contactos {
public:
    std::string nombre;
    std::string apellido;
    int telefono;
    std::string email;
    Contactos() = default;
    Contactos(std::string nombre, std::string apellido, int telefono, std::string email);

};
class ContactoIndi {
public:

    std::string campos;
    std::unordered_map<std::string, ContactoIndi> contactos;
    void imprimir() const {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Apellido: " << apellido << std::endl;
        std::cout << "Telefono: " << telefono << std::endl;
        std::cout << "Email: " << email << std::endl;
        std::cout << std::endl;
    }
    ContactoIndi()=default;

public:
    ContactoIndi(const std::string& nombre,const std::string& apellido, int telefono,const std::string& email);
    std::string getNombre() const;
    std::string getApellido() const ;
    int getTelefono() const ;
    std::string getEmail() const ;
    void ingresarContactoPorComando(const std::string& comando);
    static void crearNuevoContacto(const std::string& comando);
    void agregarContacto(const Contactos &contactos);

public:
    std::string nombre;
    std::string apellido;
    int telefono;
    std::string email;
};
#endif // GESTIONCONTACTOS_CONTACTOINDI_H

