#include "limits"
#include "MenuCrear.h"
#include "iostream"
#include "string"

#include "limits"
#include "../Grupo.h"
#include "../ListaEnlazada.h"

using namespace std;

MenuCrear::MenuCrear() =default;
ListaEnlazada listarGrupos;

void MenuCrear::menu() {
    int opcion;
    Grupo grupoActual;
    string nombreGrupo;
    Grupo grupo;

    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcion = -1;
        }
        cout << "1. crear un minigrupo " << endl;
        cout << "2. regresar " << endl;
        cout<<"3. ver grupos"<<endl;
        cin >> opcion;
        switch (opcion) {
            case 1:

                cout << "Ingrese el nombre del minigrupo: ";
                cin >> nombreGrupo;
                try {
                    grupoActual = Grupo(nombreGrupo);
                    cout << "Grupo creado exitosamente!" << endl;
                } catch (const std::exception& e) {
                    cout << "Error al crear el minigrupo: " << e.what() << endl;
                }
                break;

            case 2:
                cout<<" adio pe causa"<<endl;
                break;
            case 3:

                grupo.mostrarContactos();

                break;
            default:
                cout<<"opcion invalida"<<endl;
                break;
        }
    }while(opcion!=2);
}

