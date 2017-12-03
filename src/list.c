
#include <stdio.h>
#include <stdlib.h>
#include "../include/lista.h"
#include <string.h>

int cont=1;



void modificar(nodoLista **enlace,char contenido[],char nuevo_contenido []){
  nodoLista *actual = *enlace;
  int c=0;
  while(actual != NULL && c!=1)
  {
    if(strcmp(actual->contenido,contenido)==0){
      strcpy(actual->contenido,nuevo_contenido);
      c=1;
    }
    actual=actual->masReciente;
  }


}



void imprimir(nodoLista *enlace)
{
    nodoLista *aux = enlace;

    while(aux != NULL)
    {
        printf("%s\n",aux->contenido);
        aux = aux->masReciente;
    }
}



void agregar(nodoLista **enlace,char contenido[])
{
    cont=0;
    nodoLista *nuevo = NULL;

    nuevo = crear(contenido);
    if (nuevo != NULL)
    {
        nuevo->masReciente = *enlace;
        nuevo->menosReciente = NULL;
        if( *enlace != NULL)
            (*enlace)->menosReciente = nuevo;
        *enlace = nuevo;
    }
}



nodoLista *crear(char contenido[])
{
    nodoLista* nuevo = NULL;
    nuevo = (nodoLista*)malloc(sizeof(nodoLista));


    if(nuevo!=NULL){
    strcpy(nuevo->contenido,contenido);
    nuevo->masReciente = NULL;
    nuevo->menosReciente = NULL;

  }

    return nuevo;
}
