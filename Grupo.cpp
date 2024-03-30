#include "Grupo.h"
#include "ListaEnlazada.h"
#include <cctype>
#include "iostream"
#include <sstream>
#include "filesystem"
#include "vector"
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
/*
Grupo* Grupo::analizarCampos(const std::string& entrada) {
    try{
    std::istringstream iss(entrada);
    std::string comando, nombreGrupo, camposStr;
    iss >> comando;
    if (comando != "ADD" && comando != "ADD NEW-GROUP") {
        std::cout << "Comando invalido" << std::endl;
        return nullptr;
    }
    std::getline(iss >> std::ws, nombreGrupo, ' '); // Leer hasta el primer espacio
    std::string temp;
    std::getline(iss >> std::ws, temp, '('); // Leer hasta el paréntesis de apertura
    if (temp != "FIELDS") {
        std::cout << "Formato invalido" << std::endl;
        return nullptr;
    }
    std::getline(iss, camposStr, ')'); // Leer hasta el paréntesis de cierre
    camposStr = camposStr.substr(1); // Eliminar el paréntesis de apertura
    std::istringstream camposStream(camposStr);
    std::string campo;
    std::string camposFormateados;
    while (std::getline(camposStream, campo, ',')) {
        camposFormateados += campo + ",";
    }
    camposFormateados.pop_back(); // Eliminar la última coma
    Grupo* nuevoGrupo = new Grupo(nombreGrupo);
    nuevoGrupo->crearFormulario(camposFormateados);
    nuevoGrupo->crearCarpeta();
    return nuevoGrupo;
    } catch (const std::exception& e) {
        std::cerr << "Error al analizar el comando: " << e.what() << std::endl;
        return nullptr;
    }
}*/
Grupo* Grupo::analizarCampos(const std::string& entrada) {
    try {
        std::vector<std::string> tokens;
        std::istringstream iss(entrada);
        std::string token;
        while (std::getline(iss, token, ' ')) {
            tokens.push_back(token);
        }
        if (tokens.size() != 4) {
            std::cout << "Formato invalido" << std::endl;
            return nullptr;
        }
        if (tokens[0] != "ADD" && tokens[0] + " " + tokens[1] != "ADD NEW-GROUP") {
            std::cout << "Comando invalido" << std::endl;
            return nullptr;
        }
        const std::string& nombreGrupo = tokens[2];
        if (tokens[3] != "FIELDS" || tokens[4] != "(") {
            std::cout << "Formato invalido" << std::endl;
            return nullptr;
        }
        std::string camposStr;
        for (size_t i = 5; i < tokens.size() - 1; ++i) {
            camposStr += tokens[i] + ",";
        }
        camposStr += tokens.back();
        if (!camposStr.empty() && camposStr.back() == ',') {
            camposStr.pop_back();
        }

        Grupo* nuevoGrupo = new Grupo(nombreGrupo);
        nuevoGrupo->crearFormulario(camposStr);
        nuevoGrupo->crearCarpeta();
        return nuevoGrupo;
    } catch (const std::exception& e) {
        std::cerr << "Error al analizar el comando: " << e.what() << std::endl;
        return nullptr;
    }
}

void Grupo::solicitarValoresCampos() {
    size_t pos = 0;
    while (pos != std::string::npos) {
        std::string campo = campos.substr(pos, campos.find(",", pos) - pos);
        TipoDato tipoDato = STRING;
        if (campo.find(":") != std::string::npos) {
            tipoDato = stringToTipoDato(campo.substr(campo.find(":") + 1));
            campo = campo.substr(0, campo.find(":"));
        }
        std::string valor;
        std::cout << "Ingrese " << campo << " (" << tipoDatoToString(tipoDato) << "): ";
        std::getline(std::cin, valor);
        while (!validarValor(valor, tipoDato)) {
            std::cout << "Valor invalido. Ingrese nuevamente: ";
            std::getline(std::cin, valor);
        }
        pos = campos.find(",", pos) + 1;
    }
    std::cout << "Formulario creado exitosamente!" << std::endl;
}
TipoDato Grupo::stringToTipoDato(const std::string& tipoDatoStr) const {
    if (tipoDatoStr == "STRING") {
        return STRING;
    } else if (tipoDatoStr == "INTEGER") {
        return INTEGER;
    } else if (tipoDatoStr == "CHAR") {
        return CHAR;
    } else if (tipoDatoStr == "DATE") {
        return DATE;
    } else {
        return STRING;
    }
}
std::string Grupo::tipoDatoToString(TipoDato tipoDato) const {
    switch (tipoDato) {
        case STRING:
            return "STRING";
        case INTEGER:
            return "INTEGER";
        case CHAR:
            return "CHAR";
        case DATE:
            return "DATE";
        default:
            return "";
    }
}
bool Grupo::validarValor(const std::string& valor, TipoDato tipoDato) const {
    switch (tipoDato) {
        case STRING:
            return true;
        case INTEGER:
            for (char c : valor) {
                if (!std::isdigit(c)) {
                    std::cout << "Valor invalido. Debe ser un numero entero." << std::endl;
                    return false;
                }
            }
            return true;
        case CHAR:
            if (valor.length() != 1) {
                std::cout << "Valor invalido. Debe ser un solo caracter." << std::endl;
                return false;
            }
            return true;
        case DATE:
            try {
                int dia, mes, anio;
                char delimitador;
                std::istringstream iss(valor);
                iss >> dia >> delimitador >> mes >> delimitador >> anio;
                if (mes < 1 || mes > 12 || dia < 1 || dia > 31 || anio < 1900 || anio > 2100) {
                    std::cout << "Valor invalido. Debe ser una fecha valida (dd/mm/yyyy)." << std::endl;
                    return false;
                }
            } catch (std::exception& e) {
                std::cout << "Valor invalido. Debe ser una fecha valida (dd/mm/yyyy)." << std::endl;
                return false;
            }
            return true;
        default:
            return false;
    }
}
void Grupo::crearCarpeta() {
    std::filesystem::path rutaBase("/home/moisibot/CLionProjects/GestionContactos/contactos");
    rutaCarpeta = rutaBase / nombre;
    try {
        std::filesystem::create_directory(rutaCarpeta);
        std::cout << "Carpeta creada: " << rutaCarpeta << std::endl;
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error al crear la carpeta: " << e.what() << std::endl;
    }
}