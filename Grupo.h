#ifndef GESTIONCONTACTOS_GRUPO_H
#define GESTIONCONTACTOS_GRUPO_H

#include <iostream>
#include <string>
#include <map>
class ListaEnlazada;

using namespace std;
enum TipoDato { STRING, INTEGER, CHAR, DATE };
class Contacto {
public:
    string nombre;
    string apellido;
    int telefono;
    string email;
    Contacto() {}
    Contacto(string nombre, string apellido, int telefono, string email) {
        this->nombre = nombre;
        this->apellido = apellido;
        this->telefono = telefono;
        this->email = email;
    }
};

class Grupo {
public:
    string nombre;
    map<string, Contacto> contactos;
    string campos;  // Lista de campos del formulario (separados por coma)
    ListaEnlazada* grupos;

    Grupo() {}

    Grupo(string nombre) {
        this->nombre = nombre;
    }
    void agregarContacto(Contacto contacto);
    void mostrarContactos();
    // Nuevo método
    void crearFormulario(string campos);
};
#endif //GESTIONCONTACTOS_GRUPO_H
