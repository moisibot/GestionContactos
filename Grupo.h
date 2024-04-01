#ifndef GESTIONCONTACTOS_GRUPO_H
#define GESTIONCONTACTOS_GRUPO_H
#include <iostream>
#include <string>
#include <map>
#include <filesystem>
#include <sstream>
#include <vector>
class ListaEnlazada;
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
    std::map<std::string, Contacto> contactos;
    std::string campos;
    ListaEnlazada* grupos;
    Grupo() = default;
    Grupo(std::string nombre);
    void agregarContacto(const Contacto& contacto);
    void mostrarContactos() const;
    void crearFormulario(const std::string& camposStr);
    static Grupo* analizarCampos(const std::string& entrada);
    void solicitarValoresCampos();
    void crearCarpeta();
    void guardarContacto(std::ofstream& archivo, const Contacto& contacto);

    bool existeCarpeta();

private:
    TipoDato stringToTipoDato(const std::string& tipoDatoStr) const;
    std::string tipoDatoToString(TipoDato tipoDato) const;
    std::filesystem::path rutaCarpeta;
    bool validarValor(const std::string& valor, TipoDato tipoDato) const;

};

#endif // GESTIONCONTACTOS_GRUPO_H
