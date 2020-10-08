
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
#include <sys/time.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
  char msg[1024];
  char msg_text[1024];
  int client;
  int total_connections = 0;
  int client_socket[MAX_CLIENTS];
  int activity;
  int sd;
  int max_sd;
  int server_fd;
  int new_socket;
  struct sockaddr_in address;
  fd_set readfds;
  int opt = 1;
  int addrlen = sizeof(address);

  for (int i = 0; i < MAX_CLIENTS; i++)
  {
    client_socket[i] = 0;
  }

  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
  {
    perror("Socket creation failed\n");
    exit(EXIT_FAILURE);
  }

  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt,
                 sizeof(opt)) < 0)
  {
    perror("setsockopt error\n");
    exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
  {
    perror("Bind failed\n");
    exit(EXIT_FAILURE);
  }
  printf("Listener on port %d \n", PORT);

  if (listen(server_fd, 0) < 0)
  {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  while (1)
  {
    /* Clear the socket set */
    FD_ZERO(&readfds);

    /* add master socket to set of socket descriptors */
    FD_SET(server_fd, &readfds);
    max_sd = server_fd;

    /* add child sockets to set */
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
      sd = client_socket[i];

      /* if valid socket descriptor then add to read list */
      if (sd > 0)
        FD_SET(sd, &readfds);

      /* highest file descriptor number, need it for the select function */
      if (sd > max_sd)
        max_sd = sd;
    }

    /* wait for an activity on one of the sockets */
    activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);

    if ((activity < 0) && (errno != EINTR))
    {
      printf("select error");
    }

    /* If something happened on the master socket, then its an incoming connection */
    if (FD_ISSET(server_fd, &readfds))
    {
      if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                               (socklen_t *)&addrlen)) < 0)
      {
        perror("accept");
        exit(EXIT_FAILURE);
      }
      else
      {
        if(total_connections < MAX_CLIENTS)
        {
          total_connections++;
        }
        else
        {
          /* send connection reject message to user */
          strcpy(msg, "Connection was rejected due the recieving a maximal limit of clients");
          send(new_socket, msg, sizeof(msg), 0);
          close(new_socket);
          continue;
        }
      }

      /* inform user of socket number - used in send and receive commands */
      printf("New connection, socket fd is %d , ip is : %s , port : %d \n", new_socket, inet_ntoa(address.sin_addr), ntohs(address.sin_port));

      /* add new socket to array of sockets */
      for (int i = 0; i < MAX_CLIENTS; i++)
      {
        /* if position is empty */
        if (client_socket[i] == 0)
        {
          client_socket[i] = new_socket;
          printf("Adding to list of sockets as %d\n", i);

          break;
        }
      }
    }

    /* else its some IO operation on some other socket */
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
      sd = client_socket[i];

      if (FD_ISSET(sd, &readfds))
      {
        /* Check if it was for closing , and also read the incoming message */
        if (read(sd, msg, sizeof(msg)) == 0)
        {
          /* Somebody disconnected , get his details and print */
          getpeername(sd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
          printf("Host disconnected , ip %s , port %d \n",
                 inet_ntoa(address.sin_addr), ntohs(address.sin_port));

          /* Close the socket and mark as 0 in list for reuse */
          close(sd);
          client_socket[i] = 0;
        }
        else
        {
          sscanf(msg, "%d:%s",
           &client,
           msg_text
           );

          if (client == CLIENT_1)
          {
            to_upper(msg_text);
          }
          else
          {
            double_number(msg_text);
          }

          /* Close the socket and mark as 0 in list for reuse */
          send(sd, msg_text, strlen(msg_text) + 1, 0);
          --total_connections;
          printf("To client with fd: %d, was send response message: %s with length of %ld\n", sd, msg_text, strlen(msg_text));
        }
      }
    }
  }

  return 0;
} /* main */
