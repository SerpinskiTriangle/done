#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>


void clear_screen() {
    printf("\033[2J\033[H");
    fflush(stdout);
}

int main() {
  struct winsize ws;

  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1){
    perror("ioctl");
    return 1;
  }

  clear_screen();

  printf("Terminal width: %d columns\n", ws.ws_col);
  printf("Terminal height: %d rows\n", ws.ws_row);

  return 0;
}

