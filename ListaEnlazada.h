#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

#include <iostream>
class Grupo;

using namespace std;

class Nodo {
public:
    Grupo* minigrupo;
    Nodo* siguiente;
};

class ListaEnlazada {
private:
    Nodo* primerNodo;
    Nodo* ultimoNodo;

public:
    ListaEnlazada();
    void agregarGrupo(Grupo grupo);
    void mostrarGrupos();
};
#endif // LISTA_ENLAZADA_H
