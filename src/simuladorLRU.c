#include "../include/lista.h" //archivos cabecera
#include "../include/hashTable.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void crear_cache(int size){

printf("size:%d\n",size);

}

void entubamiento(){
  int i, num;
  unsigned char block[2];
     while ((num = fread(block, 1, 2, stdin)) == 2)
     {
         for(i = 0; i < 2; i++)
         {
             printf("%c", block[i]);
         }
     }

}


int main(int argc, char *argv[])
{

  entubamiento();
  crear_cache(atoi(argv[2]));

  return 0;
}
