
#ifndef GESTIONCONTACTOS_LISTAORDENADA_H
#define GESTIONCONTACTOS_LISTAORDENADA_H


class ListaOrdenada {
    static void listaOrdenada();

    private:
    class Nodo{
    public:
        int info;
        Nodo *sig;
    };

    Nodo *raiz;

public:
    ListaOrdenada();
    ~ListaOrdenada();
    void insertar(int x);
    void imprimir();
};

ListaOrdenada::ListaOrdenada()
{
    raiz = NULL;
}

ListaOrdenada::~ListaOrdenada()
{
    Nodo *reco = raiz;
    Nodo *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->sig;
        delete bor;
    }



};


#endif //GESTIONCONTACTOS_LISTAORDENADA_H
