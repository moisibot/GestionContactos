#include "limits"
#include "MenuCrear.h"
#include "iostream"
#include "string"
#include "../Grupo.h"
#include "../ListaEnlazada.h"

using namespace std;

MenuCrear::MenuCrear() =default;
ListaEnlazada listaGrupos;

void MenuCrear::menu() {
    int opcion;
    Grupo* grupoActual = nullptr;
    string entrada;
    std::string nombreGrupo;
    Grupo* nuevoGrupo = new Grupo(nombreGrupo);
    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcion = -1;
        }
        cout << "1. Crear un minigrupo " << endl;
        cout << "2. Regresar " << endl;
        cout << "3. Ver grupos" << endl;
        cin >> opcion;
        switch (opcion) {
            case 1:
                std::cout << "Ingrese el nombre del grupo: ";
                std::cin.ignore();
                std::getline(std::cin, nombreGrupo);

                nuevoGrupo = new Grupo(nombreGrupo);
                if (!nuevoGrupo->existeCarpeta()) {
                    nuevoGrupo->crearCarpeta();
                }
                nuevoGrupo->crearFormulario("Nombre:STRING,Apellido:STRING,Telefono:INTEGER,Email:STRING");
                nuevoGrupo->solicitarValoresCampos();
                listaGrupos.agregarGrupo(*nuevoGrupo);
                std::cout << "Grupo creado exitosamente!" << std::endl;
                delete nuevoGrupo;
                break;
            case 2:
                cout << " Adios pe causa" << endl;
                break;
            case 3:
                listaGrupos.mostrarGrupos();
                break;
            default:
                cout << "opcion invalida" << endl;
                break;
        }
    } while (opcion != 2);
}
