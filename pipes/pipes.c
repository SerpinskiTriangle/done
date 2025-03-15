#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>

struct winsize ws;


struct pipe_agent{
  char direction;
  int x_pos;
  int y_pos;
};


struct pipe_agent agents_arr[8];


void check_ws(struct winsize *ws){
  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, ws) == -1){
    perror("ioctl");
  }
}


int check_invalid_pos(struct pipe_agent *agent){
  check_ws(&ws);

  return (
  agent->x_pos < 0             ||
  agent->x_pos > ws.ws_col - 1 ||
  agent->y_pos  < 0            ||
  agent->y_pos > ws.ws_row - 1  ); // cool formatting? idk
}


void handle_invalid_agent(struct pipe_agent *agent_ptr){
  // how do we want to do this,,,
  printf("invalid pos\n");
}


void evolve_pipe_agent(struct pipe_agent *agent_ptr){
  if (check_invalid_pos(agent_ptr)){
    handle_invalid_agent(agent_ptr);
    return;
  }

  printf("\033[%d;%dH", agent_ptr->y_pos, agent_ptr->x_pos);

  switch (agent_ptr->direction){
    case 'u':
      printf("║");
      agent_ptr->y_pos -= 1;
      break;
    case 'd':
      printf("║");
      agent_ptr->y_pos += 1;
      break;
    case 'l':
      printf("═");
      agent_ptr->x_pos -= 1;
      break;
    case 'r':
      printf("═");
      agent_ptr->x_pos += 1;
      break;
    default:
      printf("invalid direction\n");
  }
}


int main(){
  check_ws(&ws);




  agents_arr[0] = (struct pipe_agent){'d', 0,0};
  
  for (int i = 0; i < 30; i++){
    evolve_pipe_agent(agents_arr);
  }
  agents_arr[0].direction = 'r';
  for (int i = 0; i < 30; i++){
    evolve_pipe_agent(agents_arr);
  }

  printf("\n");
  return 0;
}
