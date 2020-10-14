
/*
    Name:       connection.h
    
    Purpose:    Contains function declarations from connection.c file
*/

#ifndef CONNECTION_H
#define CONNECTION_H
#include "global.h"
#include "config.h"

#define NUMBER_OF_COMMANDS 7
#define MAXIMAL_NUMER_OF_TOKENS 15

typedef int (*fp)(void *a, char *tokens[], int *count);

typedef enum
{
  DISCONNECTED = 0,
  CONNECTED,
  REGISTERED
} status1;

typedef enum
{
  ONLINE = 0,
  OFFLINE
} STATUS;

typedef enum
{
  CONNECT,
  NICK,
  JOIN,
  NAMES,
  PRIVMSG,
  PART,
  EXIT
} COMMAND;

typedef struct command_t
{
  COMMAND id;
  char identifier[20];
  int token_count;
  STATUS status;
  fp callback;
} command;

typedef struct connection_t
{
  int socket_fd;
  struct sockaddr_in address;
  int address_len;
  char nick[15];
  char username[60];
  char password[16];
  char channel[10];
  status1 sts;
} connection;

int function_ponter(void *a, char *tokens[], int *count);
void parse_input(char *msg);
bool is_first_char_slash(const char *msg);
int tokenize(char *msg, char *token_array[]);
int connect_callback(void *a, char *tokens[], int *count);
int change_nickname(void *a, char *tokens[], int *count);
#endif /* CONNECTION_H */