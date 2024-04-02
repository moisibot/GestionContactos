

#ifndef GESTIONCONTACTOS_INGRESARCONTACTO_H
#define GESTIONCONTACTOS_INGRESARCONTACTO_H


#include "ContactoIndi.h"
//#include "HashContacto.h"

class IngresarContacto {
public:
    IngresarContacto();
     void ingresar();
    void ingresarContactoPorComando(const std::string& comando);
    void ingresarContacto();
private:
    void guardarContacto(std::ofstream& archivo, const ContactoIndi& contacto);
    //HashContacto tablaHash;

};


#endif //GESTIONCONTACTOS_INGRESARCONTACTO_H
