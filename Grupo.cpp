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
std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
Grupo* Grupo::analizarCampos(const std::string& entrada) {
    try {
        std::vector<std::string> tokens;
        std::istringstream iss(entrada);
        std::string token;
        while (std::getline(iss, token, ' ')) {
            tokens.push_back(token);
        }
        if (tokens.size() < 5) {
            std::cout << "Formato invalido" << std::endl;
            return nullptr;
        }
        if (tokens[0] != "ADD" || tokens[1] != "NEW-GROUP") {
            std::cout << "Comando invalido" << std::endl;
            return nullptr;
        }
        const std::string& nombreGrupo = tokens[2];

        if (tokens[3] != "FIELDS" || tokens[4] != "(") {
            std::cout << "Formato invalido" << std::endl;
            return nullptr;
        }
        size_t campoInicio = 5;
        size_t campoFin = tokens.size() - 1;

        std::string camposStr;
        for (size_t i = campoInicio; i < campoFin; ++i) {
            camposStr += tokens[i];
            if (i != campoFin - 1) {
                camposStr += ",";
            }
        }

        if (tokens[tokens.size() - 1] != ")") {
            std::cout << "Formato invalido" << std::endl;
            return nullptr;
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
                    std::cout << "ingrese un numero entero." << std::endl;
                    return false;
                }
            }
            return true;
        case CHAR:
            if (valor.length() != 1) {
                std::cout << "ingrese un solo caracter." << std::endl;
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
                    std::cout << "ingrese una fecha valida (dd/mm/yyyy)." << std::endl;
                    return false;
                }
            } catch (std::exception& e) {
                std::cout << "Vingrese una fecha valida (dd/mm/yyyy)." << std::endl;
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
