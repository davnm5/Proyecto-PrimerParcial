#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/hashTable.h"

int size=0,tam=0;

HashTable crearTabla (int x)
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

char * get(int key,HashTable t){
  return t[key];
}

int existeClave(int key,HashTable t){
  if(t[key]!=VACIO && t[key]!=BORRADO)
    return 1;
  else return 0;
}

int buscarContenido (char *x,HashTable t)
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
printf("contenido:%s\n",contenido);
   if (!existeContenido(contenido,t)) {
       pos=buscarContenido(contenido,t);
       if (t[pos]==VACIO || t[pos]==BORRADO) {
          t[pos]=(char *)malloc((strlen(contenido)+1)*sizeof(char));
          strcpy(t[pos],contenido);
          printf("palabra insertada:%s\n",t[pos]);
       } else {
          printf("Tabla Llena. \n");
       }
       tam++;
   }

}


void borrar (int clave,HashTable t)
{
    if(existeClave(clave,t)==1){
      if (t[clave]!=VACIO && t[clave]!=BORRADO) {
         if (!strcmp(t[clave],get(clave,t))) {
            free(t[clave]);
            t[clave]=BORRADO;
         }
      }
    }


}

void imprimirTabla(HashTable t){
  int i;
  for(i=0;i<size;i++){
    printf("pos :%d -> clave: %s\n",i,t[i]);
  }
}
