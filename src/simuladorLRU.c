#include "../include/lista.h" //archivos cabecera
#include "../include/hashTable.h"
#include <stdlib.h>
#include <stdio.h>



int main(int argc, char *argv[])
{
    nodoLista *enlace = NULL;
    HashTable t=crearTabla();
    agregarInicio(&enlace,(void*) 1);
    agregarInicio(&enlace,(void*) 5);
    agregarInicio(&enlace,(void*) 3);
    agregarFinal(&enlace,(void*) 7);
    modificar(&enlace,(void*) 7,(void*) 10);   //Hacemos una prueba de la lista Doblemente enlazada
    modificar(&enlace,(void*) 1,(void*) 21);
    eliminar(&enlace,(void*) 5);
    buscar(&enlace,(void*)3);
    imprimir(enlace);
    insertar("aaccee",t);
    insertar("aaccej",t);                      //Hacemos una prueba del HashTable
    insertar("aacceh",t);
    insertar("aacceq",t);
    borrar("aaccee",t);
    printf("%d\n",existeContenido("david",t));
    printf("clave:%d\n",hash("aaccee"));
    imprimirTabla(t);
    return 0;
}
