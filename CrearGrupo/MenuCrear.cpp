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
                /*
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
                listaGrupos.mostrarGrupos();*/
                std::cout << "1. Ingresar comando para crear grupo y contacto" << std::endl;
                std::cout << "2. Crear grupo manualmente" << std::endl;
                std::cout << "Ingrese una opción: ";
                int opcionCrearGrupo;
                cin >> opcionCrearGrupo;

                if (opcionCrearGrupo == 1) {
                    std::string comando;
                    std::cout << "Ingrese el comando (formato: ADD NEW-GROUP nombreDelGrupo FIELDS nombre STRING, apellido STRING, telefono INTEGER, email STRING;): ";
                    std::cin.ignore();
                    std::getline(std::cin, comando);

                    nuevoGrupo = new Grupo(nombreGrupo);
                    nuevoGrupo->crearGrupoPorComando(comando);
                    listaGrupos.agregarGrupo(*nuevoGrupo);
                    std::cout << "Grupo y contacto creados exitosamente!" << std::endl;
                    delete nuevoGrupo;
                    listaGrupos.mostrarGrupos();
                } else if (opcionCrearGrupo == 2) {
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
                    listaGrupos.mostrarGrupos();
                } else {
                    std::cout << "Opción inválida" << std::endl;
                }

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
