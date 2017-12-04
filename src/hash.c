#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/hashTable.h"

int size=0,tam=0;

HashTable crearTabla (int x) //se inicializa la tabla Hash con NULL y se le asigna un tamaño
{
   size=x;
   HashTable t;
   int i;

   t=(HashTable)malloc(size*sizeof(char *));
   if (t==NULL) {
     return VACIO;
   }

   for (i=0;i<size;i++)
      t[i]=VACIO;

   return t;
}

int hash (char *contenido)    //función que devuelve el codigo hash generado para cada registro

{
   int valor=0,i;
   unsigned char *c;
   for(i=1;i<strlen(contenido)+1;i++){
     c=contenido[i-1];
     valor=valor+(i*(int)c);    /* se realiza la función hash solicitada sumando los valores ASCII de la cadena y multiplicando por su indice
                                 para luego aplicar el modulo de un primo*/
   }

   return (valor%2017);
}

char *get(int key,HashTable t){  // se retorna el contenido dependiendo de la posicion
  return (char*)t[key];
}

int existeClave(int key,HashTable t){  //función que determina si la clave existe

  if(t[key]!=VACIO && t[key]!=BORRADO){
    return 1;
  }
  else return 0;
}

int buscarContenido (char *x,HashTable t)    // se busca un contenido en caso de haber colisiones le asigna una nuevo clave
{
   int ini,i,aux;

   ini=hash(x);

   for (i=0;i<size;i++) {
      aux=(ini+i)%size;
      if (t[aux]==VACIO)
         return aux;
      if (!strcmp(t[aux],x))
         return aux;
   }
   return ini;
}


int tamEfectivo(HashTable t){

return tam;
}


void put(int clave, char *contenido,HashTable t){  // agrega el contendio en la clave dada


  if (!existeClave(clave,t)) {

    if (t[clave]==VACIO || t[clave]==BORRADO) {
       t[clave]=(char *)malloc((strlen(contenido)+1)*sizeof(char));
       strcpy(t[clave],contenido);
       tam++;
  }
}
}


void borrar (int clave,HashTable t)
{                                                 //borra el contenido de la tabla dependiendo de la clave enviada
    if(existeClave(clave,t)==1){
      if (t[clave]!=VACIO && t[clave]!=BORRADO) {
         if (!strcmp(t[clave],get(clave,t))) {
            t[clave]=BORRADO;
         }
      }
    }

}
