#include "limits"
#include "iostream"
using namespace std;

#include "IngresarContacto.h"
IngresarContacto::IngresarContacto() =default;

void IngresarContacto::ingresar() {
    int opcion;
    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcion = -1;
        }
        cout << "1. ingresar contacto" << endl;
        cout << "2. regresar " << endl;
        cout<< "3;"<<endl;
        cin >> opcion;
        switch (opcion) {
            case 1:

                break;
            case 2:
                cout<<" adio pe causa"<<endl;
                break;
            default:
                cout<<"opcion invalida"<<endl;
                break;
        }
    }while(opcion!=2);
}