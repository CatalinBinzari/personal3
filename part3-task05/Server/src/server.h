
/*
  Header:  server.h

  Purpose: Contains function declarations from server.c file
*/

#ifndef SERVER_H
#define SERVER_H
#include <string.h>

#define PORT 8080
#define UPPER_TO_LOWER 32
#define MAX_CLIENTS 2

typedef enum
{
  CLIENT_1 = 1,
  CLIENT_2,
} client_type;

void to_upper(char *msg_value);
void double_number(char *msg_value);

#endif /* SERVER_H */
