#include "../include/lista.h" //archivos cabecera
#include "../include/hashTable.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>




void crear_cache(int size){ //creamos la cache, añadiendo las claves a la lista, y colocando los espacios extras como vacio
nodoLista *lista=NULL;
unsigned char palabra[100]={0};
int i;
int n=tamArchivo();
int y=0;
printf("lineas:%d\n",n);
while (fread(palabra,8,n,stdin)==n) //nos permite leer las claves del registro que son enviados mediante el entubamiento de entrada
{
      agregarFinal(&lista,(void*)palabra); //agregamos las claves a la lista
}

int k=size-n;
for(i=0;i<k;i++){
agregarFinal(&lista,(void*)"vacio");
}

imprimir(lista);
}


int tamArchivo(){ //esta función devuelve el número de claves que hay en el archivo

  char cadena[10];
  int lineas=0;
  FILE * archivo= fopen("bin/listado_prueba.txt", "r");

  while (fgets(cadena,10,archivo) != NULL)
  {
    lineas=lineas+1;
  }
fclose(archivo);
return lineas;
}



int main(int argc, char *argv[])
{
crear_cache(atoi(argv[1])); //le enviamos el tamaño como argumento al método crear_cache
  return 0;
}
