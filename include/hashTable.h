#ifndef _HASHTABLE_H
#define _HASHTABLE_H
#define VACIO NULL
static char * BORRADO="borrado";

typedef char ** HashTable;

extern HashTable crearTabla (int size);
extern int hash (char *contenido);
extern int buscarContenido (char *x,HashTable t);
extern int existeContenido (char *contenido,HashTable t);
extern void insertar(char *contenido,HashTable t);
extern void borrar(int clave,HashTable t);
extern void imprimirTabla(HashTable t);
extern char* get(int key,HashTable t);
extern int existeClave(int key,HashTable t);
extern int tamEfectivo(HashTable t);


#endif
