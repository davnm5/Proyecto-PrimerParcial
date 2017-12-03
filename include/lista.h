
#ifndef _LISTA_H
#define _LISTA_H


typedef struct Nodo
{
     //tipo de dato parametrizado
    struct Nodo *masReciente;  //definimos la estructura  que tendra dos punteros
    struct Nodo *menosReciente;
    char contenido [];
} nodoLista;

extern nodoLista *crear(char contenido[]);
extern void modificar(nodoLista ** enlace,char contenido[],char  nuevo_contenido[]);
extern void agregar(nodoLista **enlace, char contenido[]);
extern void imprimir(nodoLista *enlace);

#endif
