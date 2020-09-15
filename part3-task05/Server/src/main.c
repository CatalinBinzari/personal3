
/* 
  Name:     main.c   

  Purpose:  Server will recieve text message from client, returns to client the response, and finish the process
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include "server.h"

int main(int argc, char const *argv[])
{
  int server_fd;
  int new_socket;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  message mess;

  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
  {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                 &opt, sizeof(opt)))
  {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  if (bind(server_fd, (struct sockaddr *)&address,
           sizeof(address)) < 0)
  {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  if (listen(server_fd, 3) < 0)
  {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                           (socklen_t *)&addrlen)) < 0)
  {
    perror("accept");
    exit(EXIT_FAILURE);
  }

  read(new_socket, &mess, sizeof(mess));
  printf("Client message: %s\n", mess.value);

  if (mess.type == TO_UPPER)
  {
    to_upper(mess.value);
  }
  else if (mess.type == DOUBLE_NUMBER)
  {
    double_number(mess.value);
  }

  send(new_socket, &mess, sizeof(message), 0);

  printf("%s message was sent from server\n", mess.value);

  return 0;
} /* main */
