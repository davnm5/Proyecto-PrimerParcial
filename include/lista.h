
#ifndef _LISTA_H
#define _LISTA_H

typedef struct Nodo
{
    void * contenido; //tipo de dato parametrizado
    struct Nodo *siguiente;  //definimos la estructura  que tendra dos punteros
    struct Nodo *anterior;
} nodoLista;

extern nodoLista *crear(void * contenido);
extern void modificar(nodoLista ** enlace,void * contenido,void * nuevo_contenido);
extern void buscar(nodoLista** enlace, void* contenido);
extern void agregarInicio(nodoLista **enlace, void *contenido);
extern void agregarFinal(nodoLista **enlace, void *contenido);
extern void imprimir(nodoLista *enlace);
extern void eliminar(nodoLista **enlace, void *contenido);

#endif
