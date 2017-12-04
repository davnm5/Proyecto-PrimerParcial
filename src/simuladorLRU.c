#include "../include/lista.h" //archivos cabecera
#include "../include/hashTable.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

HashTable tabla;
int tamArchivo();
void crear_cache(int size){ //creamos la cache, añadiendo las claves a la lista, y colocando los espacios extras como vacio

char palabra[10]={0};
int i,lineas=0,contador=0;
int n=tamArchivo();

while (lineas!=n) //nos permite leer las claves del registro que son enviados mediante el entubamiento de entrada
{

  fscanf(stdin,"%s",palabra); //leemos los datos del entubamiento de entrada y se los separa por los saltos de línea

  int z=buscarContenido(palabra,tabla); //devuelve la posición asignada para cada contenido
  set(z,palabra,tabla);  //se encargará de añadir y realizar los intercambios de posiciones
  cache *aux=retornar(); // asigna al puntero aux una estructura tipo cache proveniente desde list.c
  printf("REGISTRO:%s  -> %s\n",palabra,aux->estado); //imprime si fue un hit o miss
      lineas++;
}

int k=size-n;
//información
cache *aux=retornar();
printf("\t\t\n**LA MEMORIA CACHÉ FUE CREADA EXITOSAMENTE**\n\n");
printf("\tINFORMACION\n\n ESPACIO CREADO:%d\n ESPACIO USADO:%d\n MISS:%d\n HIT:%d\n TASA DE FALLAS: %f\n",size,n,aux->miss,aux->hit,(float)(aux->miss)/n);

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


int main(int argc, char *argv[])
{
int valor=atoi(argv[2]); //se convierte a entero el tercer argumento
if(valor!=0){
inicializar(valor);// se envia a la lista el tamaño que tendrá
tabla=crearTabla(tamArchivo()); // se crea la HashTable con el tamaño igual al numero de líneas
crear_cache(valor);// se llama al procedimiento encrgado de crear la Caché
}

  return 0;
}
