#include <stdlib.h>
#include <stdio.h>




int main(){
  FILE *file = fopen("test.txt", "r");


  if (file == NULL){
    printf("failed to open file \n");
    exit(EXIT_FAILURE);
  }


  char c;
  while ((c = fgetc(file)) != EOF){
    printf("%c", c);
  }


  return 0;
}
