

#ifndef GESTIONCONTACTOS_INGRESARCONTACTO_H
#define GESTIONCONTACTOS_INGRESARCONTACTO_H


#include "Contacto.h"

class IngresarContacto {
public:
    IngresarContacto();
     void ingresar();

    void ingresarContacto();
private:
    void guardarContacto(std::ofstream& archivo, const Contacto& contacto);

};


#endif //GESTIONCONTACTOS_INGRESARCONTACTO_H
