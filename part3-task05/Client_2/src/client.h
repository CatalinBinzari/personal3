
/*
  Header:  client.h

  Purpose: Contains function declarations from client.c file
*/

#ifndef CLIENT_H
#define CLIENT_H

#define PORT 8080

typedef enum
{
  TO_UPPER,
  DOUBLE_NUMBER
} message_type;

typedef struct message_t
{
  message_type type;
  char value[1024];
} message;

void get_value(message *mess);

#endif /* CLIENT_H */
