
/* 
  Name:     main.c   

  Purpose:  Client will send a text to the server process. 
            The server will double the number and send the result to Client.
            Client prints the text it receives and then the process terminates.
*/

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "client.h"

int main(int argc, char const *argv[])
{
  message mess;
  int sock = 0;
  struct sockaddr_in serv_addr;

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    printf("\n Socket creation error \n");
    return -1;
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
  {
    printf("\nInvalid address/ Address not supported \n");
    return -1;
  }

  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
    printf("\nConnection Failed \n");
    return -1;
  }

  get_value(&mess);
  send(sock, &mess, sizeof(message), 0);

  read(sock, &mess, sizeof(mess));
  printf("%s\n", mess.value);

  return 0;
} /* main */
