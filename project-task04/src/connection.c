/*
    Name:       connection.c
    
    Purpose:    implement of basic client connection and registration
*/

#include "connection.h"

/*
  Name:        is_first_char_slash

  Purpose:     Check is first non space character in string is '/'

  Params:      IN msg - input string
              
  Returns:     true, is first non spacechar is '/', else false
*/
bool is_first_char_slash(const char *msg)
{
  int i = 0;
  while (msg[i] == ' ' || msg[i] == '\t' || msg[i] == '\n' || msg[i] == '\r' || msg[i] == '\f' || msg[i] == '\v')
  {
    ++i;
  }
  if (msg[i] == '/')
  {
    return true;
  }
  else
  {
    return false;
  }
}

/*
*/
int tokenize(char *msg, char *token_array[])
{
  char *pch;
  int i = 0;
  pch = strtok(msg, " \r\n");
  while (pch != NULL)
  {
    if (i >= MAXIMAL_NUMER_OF_TOKENS)
    {
      break;
    }
    token_array[i++] = pch;
    pch = strtok(NULL, " \r\n");
  }
  return i;
} /* tokenize */

/*
*/
int connect_callback(void *a, char *tokens[], int *count)
{
  //check if client is unconnected
  //create and bind the socket
  //register
  return 0;
} /* connect_callback */

/*
*/
int change_nickname(void *a, char *tokens[], int *count)
{
  return 0;
} /* change_nickname */