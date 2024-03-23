#include "limits"
#include "MenuCrear.h"
#include "iostream"
using namespace std;

MenuCrear::MenuCrear() =default;

void MenuCrear::menu() {
    int opcion;
    do {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcion = -1;
        }
        cout << "1. crear un grupo " << endl;
        cout << "2. regresar " << endl;
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