
/* 
  Name:     client.c   

  Purpose:  Conains fuctions which make main file more readable
*/

#include "client.h"

/*
  Name:        get_value

  Purpose:     Get data from user and store to struct field

  Params:      IN  msg - pointer to message struct

  Returns:     Size of input string
*/
int get_value(char *msg)
{
  printf("Enter input data:\n");
  scanf("%1023s", msg);

  return strlen(msg);
} /* get_value */

/*
  Name:        select_action

  Purpose:     Ask the user which type of client to start

  Params:      Nothing

  Returns:     message_type of the client
*/
int select_action()
{
  int client;
  printf("Choose Client1 to make uppercase\n"
          "or Client2 to double number\n"
          "Press [1] for Client1\n"
          "Press [2] for Client2\n");
  scanf("%d", &client);
  if (client == CLIENT_1 || client == CLIENT_2)
  {
    return client;
  }
  printf("ERROR: type 1 for Client1 or 2 for Client2\n");
  exit(EXIT_FAILURE);
} /* select_action */
