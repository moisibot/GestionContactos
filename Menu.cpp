
#include "limits"
#include "Menu.h"
#include "iostream"
#include "CrearGrupo/MenuCrear.h"

using namespace std;

Menu::Menu()= default;

void Menu::menu() {
    int opcion;
    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcion = -1;
        }
        cout << "1. Creacion de minigrupo " << endl;
        cout << "2. Ingresar contacto" << endl;
        cout << "3. Busqueda de contacto" << endl;
        cout << "4. Menu de reportes" << endl;
        cout << "5. Ver graficos" << endl;
        cout << "6. Importar contactos" << endl;
        cout << "7. salir " << endl;
        cin >> opcion;
        switch (opcion) {
            case 1:
            {
                MenuCrear menuCrear;
                menuCrear.menu();
            }
                break;
            case 2:
                break;

            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:
                cout<<" adio pe causa"<<endl;
                break;
            default:
                cout<<"opcion invalida"<<endl;
                break;
        }


    }while(opcion!=7);


}
