#include "ListaEnlazada.h"
#include "Grupo.h"
ListaEnlazada::ListaEnlazada() {
    primerNodo = ultimoNodo = nullptr;
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
        // ... (mostrar información del minigrupo)
        actual = actual->siguiente;
    }
}
