#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>


struct winsize ws, wsCmp;

void clear_screen() {
    printf("\033[2J\033[H");
    fflush(stdout);
}

void printBox(){
  clear_screen();

  for (int i = 0; i < ws.ws_col; i++){
    printf("#");
  }

  for (int i = 0; i < ws.ws_row - 2; i++){
    printf("#");
      for (int j = 0; j < ws.ws_col - 2; j++){
      printf(" ");
    }
    printf("#\n");
  }
  
  for (int i = 0; i < ws.ws_col; i++){
    printf("#");
  }

  fflush(stdout);
 
}

int main() {
  while (1){
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1){
      perror("ioctl");
      return 1;
    }
    if (ws.ws_col != wsCmp.ws_col || ws.ws_row != wsCmp.ws_row){
      wsCmp.ws_row = ws.ws_row;
      wsCmp.ws_col = ws.ws_col;

      printBox();
    }
  }
  return 0;
}

