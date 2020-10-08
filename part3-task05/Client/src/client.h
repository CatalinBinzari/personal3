
/*
  Header:  client.h

  Purpose: Contains function declarations from client.c file
*/

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef CLIENT_H
#define CLIENT_H

#define PORT 8080

typedef enum
{
  CLIENT_1 = 1,
  CLIENT_2,
} client_type;

int get_value(char *msg);
int select_action();

#endif /* CLIENT_H */
