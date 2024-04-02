
#include "limits"
#include "Menu.h"
#include "iostream"
#include "CrearGrupo/MenuCrear.h"
#include "IngresarContacto/IngresarContacto.h"
#include "IngresarContacto/ContactoIndi.h"
#include "IngresarContacto/Busqueda.h"
using namespace std;
Menu::Menu()= default;
void Menu::menu() {
    int opcion;
    IngresarContacto ingresar;
    IngresarContacto ingresarContactoPorComando;
   // Busqueda busqueda;
    std::string nombreContacto;
 //   std::vector<Contacto> contactosEncontrados;
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

               // ingresar.ingresarContacto();
            {
                std::string comando;
                cout << "Ingrese el comando para agregar un nuevo contacto (formato: ADD NEW-CONTACT FIELDS [nombre=valor, apellido=valor, telefono=valor, email=valor];): ";
                std::getline(cin >> std::ws, comando);
                ingresar.ingresarContactoPorComando(comando);
            }
                //ingresar.ingresar();
                break;
            case 3: {
                //Busqueda::buscarContacto();

                Busqueda busqueda;
                cout << "Ingrese el nombre del archivo del contacto que desea buscar: ";
                cin >> nombreContacto;
                ContactoIndi contactoEncontrado = busqueda.buscarContactoPorNombreArchivo(nombreContacto);
                if (contactoEncontrado.getNombre() != "") {
                    cout << "Contacto encontrado:" << endl;
                    cout << "Nombre: " << contactoEncontrado.getNombre() << endl;
                    cout << "Apellido: " << contactoEncontrado.getApellido() << endl;
                    cout << "Teléfono: " << contactoEncontrado.getTelefono() << endl;
                    cout << "Email: " << contactoEncontrado.getEmail() << endl;
                } else {
                    cout << "No se encontró ningún contacto con ese nombre de archivo." << endl;
                }
            }
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
