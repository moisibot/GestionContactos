#include "iostream"
#include "ListaOrdenada.h"

using namespace std;

void ListaOrdenada::insertar(int x) {
    Nodo *nuevo = new Nodo();
    nuevo->info = x;
    if (raiz == NULL)
    {
        raiz = nuevo;
    }
    else
    {
        if (x<raiz->info)
        {
            nuevo->sig = raiz;
            raiz = nuevo;
        }
        else
        {
            Nodo *reco = raiz;
            Nodo *atras = raiz;
            while (x >= reco->info && reco->sig != NULL)
            {
                atras = reco;
                reco = reco->sig;
            }
            if (x >= reco->info)
            {
                reco->sig = nuevo;
            }
            else
            {
                nuevo->sig = reco;
                atras->sig = nuevo;
            }
        }
    }
}

void ListaOrdenada::imprimir()
{
    Nodo *reco = raiz;
    cout << "Listado completo.\n";
    while (reco != NULL)
    {
        cout << reco->info << "-";
        reco = reco->sig;
    }
    cout << "\n";

}





