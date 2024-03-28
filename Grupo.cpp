#include "Grupo.h"
#include "ListaEnlazada.h"

TipoDato stringToTipoDato(string tipoDatoStr);  // Forward declaration
string tipoDatoToString(TipoDato tipoDato);

void Grupo::agregarContacto(Contacto contacto) {
    contactos[contacto.nombre] = contacto;
}
void Grupo::mostrarContactos() {
    for (auto it = contactos.begin(); it != contactos.end(); ++it) {
        cout << "Nombre: " << it->second.nombre << endl;
        cout << "Apellido: " << it->second.apellido << endl;
        cout << "Telefono: " << it->second.telefono << endl;
        cout << "Email: " << it->second.email << endl;
        cout << endl;
    }
}
void Grupo::crearFormulario(string campos) {
    grupos= new ListaEnlazada();
    this->campos = campos;
    size_t pos = 0;
    while (pos != string::npos) {
        string campo = campos.substr(pos, campos.find(",", pos) - pos);

        // Obtener el tipo de dato del campo
        TipoDato tipoDato = STRING;
        if (campo.find(":") != string::npos) {
            tipoDato = stringToTipoDato(campo.substr(campo.find(":") + 1));
            campo = campo.substr(0, campo.find(":"));
        }
        // Pedir al usuario el valor del campo
        string valor;
        cout << "Ingrese " << campo << " (" << tipoDatoToString(tipoDato) << "): ";

        // Almacenar el valor del campo en el formulario
        // ... (dependiendo de la implementación del formulario)

        // Validar el valor del campo según el tipo de dato
        switch (tipoDato) {
            case STRING:
                // Validar que la entrada sea una cadena de caracteres
                break;
            case INTEGER:
                // Validar que la entrada sea un número entero
                break;
            case CHAR:
                // Validar que la entrada sea un caracter
                break;
            case DATE:
                // Validar que la entrada sea una fecha válida
                break;
        }

        pos = campos.find(",", pos) + 1;
    }

    cout << "Formulario creado exitosamente!" << endl;
}




// Función para convertir una cadena a un tipo de dato

TipoDato stringToTipoDato(string tipoDatoStr) {
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
// Función para convertir un tipo de dato a una cadena
string tipoDatoToString(TipoDato tipoDato) {
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



