cmake_minimum_required(VERSION 3.27)
project(GestionContactos)

set(CMAKE_CXX_STANDARD 17)

add_executable(GestionContactos main.cpp
        Menu.cpp
        Menu.h
        Busqueda.cpp
        Busqueda.h
        TiposDatos.cpp
        TiposDatos.h
        CrearGrupo/MenuCrear.cpp
        CrearGrupo/MenuCrear.h
        IngresarContacto/IngresarContacto.cpp
        IngresarContacto/IngresarContacto.h
        IngresarContacto/ListaOrdenada.cpp
        IngresarContacto/ListaOrdenada.h
        IngresarContacto/Insercion.cpp
        IngresarContacto/Insercion.h
        IngresarContacto/BusquedaBinaria.cpp
        IngresarContacto/BusquedaBinaria.h)
