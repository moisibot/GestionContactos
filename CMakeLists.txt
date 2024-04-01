cmake_minimum_required(VERSION 3.27)
project(GestionContactos)

set(CMAKE_CXX_STANDARD 17)

add_executable(GestionContactos main.cpp
        Menu.cpp
        Menu.h
        TiposDatos.cpp
        TiposDatos.h
        CrearGrupo/MenuCrear.cpp
        CrearGrupo/MenuCrear.h
        IngresarContacto/IngresarContacto.cpp
        IngresarContacto/IngresarContacto.h
        IngresarContacto/ListaOrdenada.cpp
        IngresarContacto/ListaOrdenada.h
        IngresarContacto/BusquedaBinaria.cpp
        IngresarContacto/BusquedaBinaria.h
        ArbolesAVL/Busqueda.cpp
        ArbolesAVL/Busqueda.h
        ArbolesAVL/AVLTree.cpp
        ArbolesAVL/AVLTree.h
        Grupo.cpp
        Grupo.h
        ListaEnlazada.cpp
        ListaEnlazada.h
        ArbolesAVL/HashTable.cpp
        ArbolesAVL/HashTable.h
        IngresarContacto/Contacto.cpp
        IngresarContacto/Contacto.h)
