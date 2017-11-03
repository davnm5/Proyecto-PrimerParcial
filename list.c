
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    void * contenido; //tipo de dato parametrizado
    struct Nodo *siguiente;  //definimos la estructura  que tendra dos punteros
    struct Nodo *anterior;
} nodoLista;


nodoLista *crear(void * contenido); // nos permite crear un nodo
void modificar(nodoLista ** enlace,void * contenido,void * nuevo_contenido);// permite buscar y modificar dicho contenido
void buscar(nodoLista** enlace, void* contenido);//permite buscar el contenido de un nodo
void agregarInicio(nodoLista **enlace, void *contenido);//permite agregar un nodo al inicio
void agregarFinal(nodoLista **enlace, void *contenido);//permite agregar un nodo al final
void imprimir(nodoLista *enlace); //permite visualizar la lista final
void eliminar(nodoLista **enlace, void *contenido); //elimina un nodo que tenga dicho contenido


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


void buscar(nodoLista **enlace ,void *contenido){
nodoLista *actual = *enlace;
int c=0;
while(actual != NULL && c!=1)
{
  if(actual->contenido==contenido){
    c=1;
  }
  actual=actual->siguiente;
}

if(c==1){
printf("El nodo con el contenido: %lu fue encontrado\n",(long) contenido);
}
else {
  printf("El nodo no fue encontrado\n");
}

}

void modificar(nodoLista **enlace,void * contenido,void * nuevo_contenido){
  nodoLista *actual = *enlace;
  int c=0;
  while(actual != NULL && c!=1)
  {
    if(actual->contenido==contenido){
      actual->contenido=nuevo_contenido;
      c=1;
    }
    actual=actual->siguiente;
  }


}

void eliminar(nodoLista **enlace, void *contenido)
{
    nodoLista *actual = *enlace, *prev = NULL, *next = NULL;

    while(actual != NULL)
    {
        if(actual->contenido == contenido)
        {
            if( actual == *enlace)
            {
                *enlace = actual->siguiente;
                if( actual->siguiente != NULL)
                    actual->siguiente->anterior = NULL;
            }
            else if( actual->siguiente == NULL)
            {
                prev = actual->anterior;
                actual->anterior = NULL;
                prev->siguiente = NULL;
            }
            else
            {
                prev = actual->anterior;
                actual->anterior = NULL;
                next = actual->siguiente;
                actual->siguiente = NULL;
                prev->siguiente = next;
                next->anterior = prev;
            }
            free(actual);
        }
        actual = actual->siguiente;
    }
}

void agregarFinal(nodoLista **enlace, void *contenido)
{
    nodoLista *nuevo = NULL, *aux = *enlace;

    nuevo = crear(contenido);
    if (nuevo != NULL)
    {
        while(aux->siguiente != NULL){
          aux = aux->siguiente;
        }
        nuevo->anterior = aux;
        aux->siguiente = nuevo;
    }
}


void imprimir(nodoLista *enlace)
{
    nodoLista *aux = enlace;

    while(aux != NULL)
    {
        printf("%lu\n",(long) aux->contenido);
        aux = aux->siguiente;
    }
}


void agregarInicio(nodoLista **enlace, void *contenido)
{
    nodoLista *nuevo = NULL;

    nuevo = crear(contenido);
    if (nuevo != NULL)
    {
        nuevo->siguiente = *enlace;
        nuevo->anterior = NULL;
        if( *enlace != NULL)
            (*enlace)->anterior = nuevo;
        *enlace = nuevo;
    }
}


nodoLista *crear(void *contenido)
{
    nodoLista* nuevo = NULL;

    nuevo = (nodoLista*)malloc(sizeof(nodoLista));
    if( nuevo != NULL)
    {
        nuevo->contenido = contenido;
        nuevo->siguiente = NULL;
        nuevo->anterior = NULL;
    }
    return nuevo;
}
