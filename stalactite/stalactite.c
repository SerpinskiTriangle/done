#include <stdio.h>
#include <stdlib.h>

typedef unsigned int (uint);

uint largest(uint *stlgs, uint len){
  uint largest = 0;
  for (uint index = 0; index < len; index++){
    stlgs[index] > largest ? largest = stlgs[index] : 0 ;
  }
  return largest;
}

void drawStalagtite(uint *stlgs, uint len){
  uint bigStlg = largest(stlgs, len);
  for (uint row = 0; row < bigStlg + 1; row++){
    for (uint col = 0; col < len; col++){
      if((int)(stlgs[col] - row) == 0){

        printf("V");
      }
      else{
        ((int)(stlgs[col] - row) > 0) ? printf("H"): printf(" ");
      }
    }
    printf("\n");
  }
}

int main(){
  uint stlg[8] = {5,2,6,3,8,2,5,8};
  drawStalagtite(stlg, 8);
  return 0;
}
