#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/hashTable.h"


HashTable crearTabla ()
{
   HashTable t;
   int i;

   t=(HashTable)malloc(SIZE*sizeof(char *));
   if (t==NULL) {
     return VACIO;
   }

   for (i=0;i<SIZE;i++)
      t[i]=VACIO;

   return t;
}

int hash (char *contenido)

{
   int valor=0,i;
   unsigned char *c;
   for(i=1;i<strlen(contenido)+1;i++){
     c=contenido[i-1];
     valor=valor+(i*(int)c);
   }

   return (valor%2017);
}

int buscarContenido (char *x,HashTable t)
{
   int ini,i,aux;

   ini=hash(x);

   for (i=0;i<SIZE;i++) {
      aux=(ini+i)%SIZE;
      if (t[aux]==VACIO)
         return aux;
      if (!strcmp(t[aux],x))
         return aux;
   }
   return ini;
}


int existeContenido (char *contenido,HashTable t)
{
   int pos=buscarContenido(contenido,t);

   if (t[pos]==VACIO)
      return 0;
   else
      return(!strcmp(t[pos],contenido));
}

void insertar (char *contenido,HashTable t)

{
   int pos;

   if (!contenido)
      printf("Cadena no Existe.");

   if (!existeContenido(contenido,t)) {
       pos=buscarContenido(contenido,t);
       if (t[pos]==VACIO || t[pos]==BORRADO) {
          t[pos]=(char *)malloc((strlen(contenido)+1)*sizeof(char));
          strcpy(t[pos],contenido);
       } else {
          printf("Tabla Llena. \n");
       }
   }
}


void borrar (char *contenido,HashTable t)
{
   int pos = buscarContenido(contenido,t);

   if (t[pos]!=VACIO && t[pos]!=BORRADO) {
      if (!strcmp(t[pos],contenido)) {
         free(t[pos]);
         t[pos]=BORRADO;
      }
   }
}


void imprimirTabla(HashTable t){
  int i;
  for(i=0;i<SIZE;i++){
    printf("pos :%d -> clave: %s\n",i,t[i]);
  }
}
