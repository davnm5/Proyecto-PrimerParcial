#include "../include/lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


int main(int argc, char *argv[])
{
    nodoLista *enlace = NULL;
    agregarInicio(&enlace,(void*) 1);
    agregarInicio(&enlace,(void*) 5);
    agregarInicio(&enlace,(void*) 3);
    agregarFinal(&enlace,(void*) 7);
    modificar(&enlace,(void*) 7,(void*) 10);   //Hacemos una prueba de la lista Doblemente enlazada
    modificar(&enlace,(void*) 1,(void*) 21);
    eliminar(&enlace,(void*) 5);
    buscar(&enlace,(void*)3);
    imprimir(enlace);

    return 0;
}
