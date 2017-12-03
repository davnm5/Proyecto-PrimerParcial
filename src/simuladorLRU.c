#include "../include/lista.h" //archivos cabecera
#include "../include/hashTable.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

HashTable tabla;
int miss=0,hit=0;

void crear_cache(int size){ //creamos la cache, añadiendo las claves a la lista, y colocando los espacios extras como vacio

char palabra[10]={0};
int i,lineas=0,contador=0;
int n=tamArchivo();

while (lineas!=n) //nos permite leer las claves del registro que son enviados mediante el entubamiento de entrada
{

  fscanf(stdin,"%s",palabra);

  int z=buscarContenido(palabra,tabla); //devuelve la posición asignada para cada contenido
  set(z,palabra,tabla);  //se encargará de añadir y realizar los intercambios de posiciones

      lineas++;
}

int k=size-n;
//información
printf("\t\t**LA MEMORIA CACHÉ FUE CREADA EXITOSAMENTE**\n\n");
printf("\tINFORMACION\n ESPACIO CREADO:%d\n ESPACIO USADO:%d\n ESPACIO DISPONIBLE:%d\n",size,n,k);

}





int tamArchivo(){ //esta función devuelve el número de claves que hay en el archivo

  char cadena[10];
  int lineas=0;
  FILE * archivo= fopen("bin/listado_prueba.txt", "r"); //se abre el archivo ubicado en la carpeta bin

  while (fgets(cadena,10,archivo) != NULL)   //se lee cada línea del archivo
  {
    lineas=lineas+1;    //contamos las líneas
  }
fclose(archivo);   // se cierra el archivo
return lineas;
}

void imprimirCache(){
int i;
  for(i=0;i<tamEfectivo(tabla);i++){    // Se recorre la lista dependiendo de la cantidad de elementos insertados
    if(getValor(i,tabla)!=NULL){   //se verifica que dicha posicion este presente en la lista
    printf("pos:%d-> valor:%s\n",i,getValor(i,tabla));  //se imprime el contenido de la posicion
  }
}
}


int main(int argc, char *argv[])
{
int valor=atoi(argv[2]); //se convierte a entero el tercer argumento
inicializar(valor);// se envia a la lista el tamaño que tendrá
tabla=crearTabla(tamArchivo()); // se crea la HashTable con el tamaño igual al numero de líneas
crear_cache(valor);// se llama al procedimiento encrgado de crear la Caché
imprimirCache();//se imprime la cache
  return 0;
}
