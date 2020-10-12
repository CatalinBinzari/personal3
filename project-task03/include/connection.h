
/*
    Name:       connection.h
    
    Purpose:    Contains function declarations from connection.c file
*/

#ifndef CONNECTION_H
#define CONNECTION_H
#include "global.h"
#include "config.h"

typedef enum
{
  DISCONNECTED = 0,
  CONNECTED,
  REGISTERED
} status;

typedef struct connection_t
{
  int socket_fd;
  struct sockaddr_in address;
  int address_len;
  char nick[15];
  char username[60];
  char password[16];
  char channel[10];
  status sts;
} connection;

#endif /* CONNECTION_H */