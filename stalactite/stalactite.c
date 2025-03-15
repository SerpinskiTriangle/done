#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <string.h>



struct winsize ws;

typedef unsigned int (uint);

uint largest(uint *stlgs, uint len){
  uint largest = 0;
  for (uint index = 0; index < len; index++){
    stlgs[index] > largest ? largest = stlgs[index] : 0 ;
  }
  return largest;
}

void drawStalagtite(uint *stlgs, uint len){
  len -= len%2;
  uint bigStlg = largest(stlgs, len);
  for (uint row = 0; row < bigStlg + 1; row++){
    for (uint col = 0; col < len; col += 2){
      if((int)(stlgs[col] - row) == 0){

        printf("▽ ");
      }
      else{
        ((int)(stlgs[col] - row) > 0) ? printf("││"): printf("  ");
      }
    }
    printf("\n");
  }
}

int main(){
  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1){
    perror("ioctl");
    return 1;
  }

  uint slgArr[ws.ws_col];
  memset(slgArr, 0, sizeof(uint)*ws.ws_col);


  printf("ws_row: %d\n", ws.ws_col);

  while (1){
    drawStalagtite(slgArr, ws.ws_col);
    printf("\033[2J\033[H");
    
    slgArr[rand()%ws.ws_col]++;
    usleep(5000);
  }

  return 0;
}
