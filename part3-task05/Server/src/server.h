
/*
  Header:  server.h

  Purpose: Contains function declarations from server.c file
*/

#ifndef SERVER_H
#define SERVER_H

#define PORT 8080
#define UPPER_TO_LOWER 32

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

void to_upper(char *mess_value);
void double_number(char *mess_value);

#endif /* SERVER_H */
