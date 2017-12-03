
#include <stdio.h>
#include <stdlib.h>  //se incluyen los archivos cabecera
#include <string.h>
#include "../include/lista.h"
#include "../include/hashTable.h"
cache *aux; //se define puntero global de tipo cache


void inicializar(int x){     //se inicializa la cache con un tamaño
  aux=NULL;
  aux = (cache*)malloc(sizeof(cache)); // se hace asignación de memoria dinámica para la estructura cache
  aux->size=x;
  aux->inicio=NULL;
  aux->fin=NULL;

}

/*función que me devuelve un puntero a char
Se encarga de verificar si el contenido existe en alguna posicion luego de asignar dicho contenido al nodoLista y devolverlo
*/
char* getValor(int clave,HashTable tabla) {

  if(existeClave(clave,tabla)==1){

           nodoLista* n= NULL;
           n = (nodoLista*)malloc(sizeof(nodoLista));
           n->contenido=get(clave,tabla);

           return n->contenido;
       }

       else return NULL; // cuando la clave del contenido no esta en la tabla Hash
   }


/*Método que se encarga de remover un nodo cuando la caché esta llena */
   void remover(nodoLista** n){

          if((*n)->menosReciente!=NULL){
              (*n)->menosReciente->masReciente = (*n)->masReciente;
          }else{
              aux->inicio = (*n)->masReciente;
          }

          if((*n)->masReciente!=NULL){
              (*n)->masReciente->menosReciente = (*n)->menosReciente;
          }else{
              aux->fin = (*n)->menosReciente;
          }

      }

      void setUbicaciones(nodoLista** n){   //modifica las ubicaciones del inicio y fin de la caché
          (*n)->masReciente =aux->inicio;
          (*n)->menosReciente =NULL;

          if(aux->inicio!=NULL)
              aux->inicio->menosReciente = (*n);

          aux->inicio = (*n);

          if(aux->fin ==NULL)
              aux->fin= aux->inicio;
      }


// Se crean los nodos y se agregan las claves y contenidos a la tabla
      void set(int clave,char *contenido,HashTable tabla) {

             if(existeClave(clave,tabla)==1){ //verifica si existe la clave en la tabla
                 nodoLista* old = NULL;
                 old = (nodoLista*)malloc(sizeof(nodoLista));
                 old->clave=clave;
                 old->contenido=contenido;
                 remover(&old);
                 setUbicaciones(&old);
             }else{
               //ingresa cuando la clave del contenido es nueva
                 nodoLista *nuevo=NULL;
                 nuevo = (nodoLista*)malloc(sizeof(nodoLista));
                 nuevo->clave=clave;
                 nuevo->contenido=contenido;
                 if(tamEfectivo(tabla)>=aux->size){  // si el tamaño de cache es mayor que el tamaño de la tabla
                     borrar(aux->fin->clave,tabla); // borra la clave de la tabla
                     remover(&aux->fin); //remueve el nodo fin de la caché
                     setUbicaciones(&nuevo); //como se ha realizado eliminación de un nodo se debe reubicar posiciones

                 }else{
                     setUbicaciones(&nuevo);
                 }

                 put(nuevo->clave,nuevo->contenido,tabla); //agrega clave y valor a la tabla


             }
           }
