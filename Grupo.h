#ifndef GESTIONCONTACTOS_GRUPO_H
#define GESTIONCONTACTOS_GRUPO_H

#include <iostream>
#include <string>
#include <map>
#include <filesystem>
#include "string"
#include "sstream"
class ListaEnlazada;
using namespace std;

enum TipoDato { STRING, INTEGER, CHAR, DATE };
class Contacto {
public:
    std::string nombre;
    std::string apellido;
    int telefono;
    std::string email;

    Contacto() = default;
    Contacto(std::string nombre, std::string apellido, int telefono, std::string email);
};

class Grupo {
public:
    std::string nombre;
    std::map<string, Contacto> contactos;
    std::string campos;  // Lista de campos del formulario (separados por coma)
    ListaEnlazada* grupos;
    Grupo() = default;
    Grupo(std::string nombre);

    void agregarContacto(const Contacto& contacto);
    void mostrarContactos() const;
    void crearFormulario(const std::string& camposStr);
    static Grupo* analizarCampos(const std::string& entrada);
    void solicitarValoresCampos();
    void crearCarpeta();

private:
    TipoDato stringToTipoDato(const std::string& tipoDatoStr) const;
    std::string tipoDatoToString(TipoDato tipoDato) const;
    std::filesystem::path rutaCarpeta;
    bool validarValor(const string &valor, TipoDato tipoDato) const;
};
#endif //GESTIONCONTACTOS_GRUPO_H
