#ifndef _HASHTABLE_H
#define _HASHTABLE_H
#define SIZE 10
#define VACIO NULL
static char * BORRADO="borrado";

typedef char ** HashTable;

extern HashTable crearTabla ();
extern int hash (char *contenido);
extern int buscarContenido (char *x,HashTable t);
extern int existeContenido (char *contenido,HashTable t);
extern void insertar(char *contenido,HashTable t);
extern void borrar(char *contenido,HashTable t);
extern void imprimirTabla(HashTable t);


#endif
