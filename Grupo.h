#ifndef GESTIONCONTACTOS_GRUPO_H
#define GESTIONCONTACTOS_GRUPO_H
#include <iostream>
#include <string>
#include <map>
#include <filesystem>
#include <sstream>
#include <vector>
#include <unordered_map>

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
    explicit Grupo(std::string nombre);

    void agregarContacto(const Contacto& contacto);
    void crearFormulario(const std::string& camposStr);
    void crearGrupoPorComando(const std::string& comando);
    void crearCarpeta();
    void solicitarValoresCampos();
    void guardarContacto(std::ofstream& archivo, const Contacto& contacto);
    bool existeCarpeta();
    void mostrarContactos() const;
    ListaEnlazada* grupos;
    Grupo() = default;

    static Grupo* analizarCampos(const std::string& entrada);

    std::string getNombreCampo()const{
        return nombre;
    }
    std::unordered_map<std::string, Contacto>& getContactos() const;
    std::string nombre;
private:
    TipoDato stringToTipoDato(const std::string& tipoDatoStr) const;
    std::string tipoDatoToString(TipoDato tipoDato) const;
    std::filesystem::path rutaCarpeta;
    bool validarValor(const std::string& valor, TipoDato tipoDato) const;

    std::unordered_map<std::string, Contacto> contactos;
    std::string campos;
};

#endif // GESTIONCONTACTOS_GRUPO_H
