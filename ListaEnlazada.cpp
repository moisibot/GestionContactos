#include "ListaEnlazada.h"
#include "Grupo.h"
ListaEnlazada::ListaEnlazada() {
    primerNodo = ultimoNodo = nullptr;
}

ListaEnlazada::~ListaEnlazada() {
    Nodo* actual = primerNodo;
    while (actual != nullptr) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp->minigrupo;
        delete temp;
    }

}

void ListaEnlazada::agregarGrupo(Grupo grupo) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->minigrupo = new Grupo();
    nuevoNodo->minigrupo->nombre = grupo.nombre;

    if (primerNodo == nullptr) {
        primerNodo = ultimoNodo = nuevoNodo;
    } else {
        ultimoNodo->siguiente = nuevoNodo;
        ultimoNodo = nuevoNodo;
    }
}
void ListaEnlazada::mostrarGrupos() {
    Nodo* actual = primerNodo;
    while (actual != nullptr) {
        cout << "Nombre del minigrupo: " << actual->minigrupo->nombre << endl;
        actual = actual->siguiente;
    }
}
