
#ifndef _LISTA_H
#define _LISTA_H
#include "../include/hashTable.h"
typedef struct Nodo
{
    int clave;
    struct Nodo *masReciente;  //definimos la estructura  que tendra dos punteros
    struct Nodo *menosReciente;
    char *contenido;
} nodoLista;


typedef struct LRU{
int size,hit,miss;
char* estado;
nodoLista *inicio;
nodoLista *fin;
}cache;

extern void inicializar(int x);
extern char* getValor(int clave,HashTable tabla);
extern void remover(nodoLista ** n);
extern void set(int clave,char *contenido,HashTable tabla);
extern void setHead(nodoLista ** n);
extern cache* retornar();
#endif
