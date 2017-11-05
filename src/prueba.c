#include <stdlib.h>
#include <stdio.h>


void leer_archivo(){
printf("POSI");
FILE * archivo;
char caracteres[100];
printf("POSI1");
archivo = fopen("bin/listado_prueba.txt","r");

 while (feof(archivo) == 0)
 {
 		fgets(caracteres,100,archivo);
 		printf("%s\n",caracteres);
 }

fclose(archivo);

}


int main()
{
  leer_archivo();
  return 0;
}
