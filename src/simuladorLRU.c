#include "../include/lista.h" //archivos cabecera
#include "../include/hashTable.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>




void crear_cache(int size){ //creamos la cache, añadiendo las claves a la lista, y colocando los espacios extras como vacio
nodoLista *lista=NULL;
char palabra[10]={0};
int i,lineas=0;
int n=tamArchivo();
printf("lineas:%d\n",n);

while (lineas!=n) //nos permite leer las claves del registro que son enviados mediante el entubamiento de entrada
{
      fscanf(stdin,"%s",palabra);
      printf("%s\n",palabra);
      agregarFinal(&lista,palabra);
      lineas++; //agregamos las claves a la lista
}

int k=size-n;
for(i=0;i<k;i++){
agregarFinal(&lista,"vacio");
}
printf("\t\t**LA MEMORIA CACHÉ FUE CREADA EXITOSAMENTE**\n\n");
printf("\tINFORMACION\n ESPACIO CREADO:%d\n ESPACIO USADO:%d\n ESPACIO DISPONIBLE:%d\n",size,n,k);
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
