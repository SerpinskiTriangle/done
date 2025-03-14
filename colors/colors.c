#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

struct winsize ws;
void reset(){
  printf("\033[39;49m");
}

int main(){
  int column = 0, row = 0;

  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1){
    perror("ioctl");
    return 1;
  }

  while(row < ws.ws_row){
    while (column < ws.ws_col){
      printf("\033[%d;%dm-",30+(column%9), 40 + (row%9));
      column++;
    }
    printf("\n");

    column=0;
    row++;

    usleep(10000);
  }

  reset();
  printf("row%dcol%d", ws.ws_row,ws.ws_col);


  return 0;
}
