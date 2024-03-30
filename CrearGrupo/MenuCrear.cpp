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
                std::cout << "Ingrese el comando para crear un nuevo grupo (ADD NEW-GROUP nombreGrupo FIELDS (campo1 TipoDato, campo2 TipoDato, ...)): ";
                std::cin.ignore();
                std::getline(std::cin, entrada);
                grupoActual = Grupo::analizarCampos(entrada);
                if (grupoActual) {
                    listaGrupos.agregarGrupo(*grupoActual);
                    std::cout << "Grupo creado exitosamente!" << std::endl;
                    delete grupoActual;
                } else {
                    std::cout << "Error al crear el grupo" << std::endl;
                }
                break;


            case 2:
                cout << " Adios pe causa" << endl;
                break;
            case 3:
                listaGrupos.mostrarGrupos();
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    } while (opcion != 2);
}
